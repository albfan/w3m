/* $Id$ */
#include "fm.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#ifdef HAVE_READLINK
#include <unistd.h>
#endif				/* HAVE_READLINK */
#ifdef __EMX__
#include <limits.h>		/* _MAX_PATH ? */
#endif				/* __EMX__ */
#include "local.h"
#include "hash.h"

#define CGIFN_NORMAL     0
#define CGIFN_DROOT      1
#define CGIFN_CGIBIN     2
#define CGIFN_MODE(x) ((x)&3)

#define CGIFN_CONTAIN_SLASH 4

static char *Local_cookie_file = NULL;

static void
writeLocalCookie()
{
    FILE *f;

    if (no_rc_dir)
	return;
    if (Local_cookie_file)
	return;
    Local_cookie_file = tmpfname(TMPF_COOKIE, NULL)->ptr;
    set_environ("LOCAL_COOKIE_FILE", Local_cookie_file);
    f = fopen(Local_cookie_file, "wb");
    if (!f)
	return;
    fwrite(Local_cookie->ptr, sizeof(char), Local_cookie->length, f);
    fclose(f);
    chmod(Local_cookie_file, S_IRUSR | S_IWUSR);
}

/* setup cookie for local CGI */
void
setLocalCookie()
{
    char hostname[256];
    gethostname(hostname, 256);

    Local_cookie = Sprintf("%d.%ld@%s", CurrentPid, lrand48(), hostname);
}

Str
loadLocalDir(char *dname)
{
    Str tmp;
    DIR *d;
    Directory *dir;
    struct stat st;
    char **flist;
    char *p, *qdir;
    Str fbuf = Strnew();
#ifdef HAVE_LSTAT
    struct stat lst;
#ifdef HAVE_READLINK
    char lbuf[1024];
#endif				/* HAVE_READLINK */
#endif				/* HAVE_LSTAT */
    int i, l, nrow = 0, n = 0, maxlen = 0;
    int nfile, nfile_max = 100;
    Str dirname;

    d = opendir(dname);
    if (d == NULL)
	return NULL;
    dirname = Strnew_charp(dname);
    if (Strlastchar(dirname) != '/')
	Strcat_char(dirname, '/');
    qdir = html_quote(Str_conv_from_system(dirname)->ptr);
    tmp = Strnew_m_charp("<HTML>\n<HEAD>\n<BASE HREF=\"file://", qdir,
			 "\">\n<TITLE>Directory list of ", qdir,
			 "</TITLE>\n</HEAD>\n<BODY>\n<H1>Directory list of ",
			 qdir, "</H1>\n", NULL);
    flist = New_N(char *, nfile_max);
    nfile = 0;
    while ((dir = readdir(d)) != NULL) {
	flist[nfile++] = allocStr(dir->d_name, -1);
	if (nfile == nfile_max) {
	    nfile_max *= 2;
	    flist = New_Reuse(char *, flist, nfile_max);
	}
	if (multicolList) {
	    l = strlen(dir->d_name);
	    if (l > maxlen)
		maxlen = l;
	    n++;
	}
    }

    if (multicolList) {
	l = COLS / (maxlen + 2);
	if (!l)
	    l = 1;
	nrow = (n + l - 1) / l;
	n = 1;
	Strcat_charp(tmp, "<TABLE CELLPADDING=0>\n<TR VALIGN=TOP>\n");
    }
    qsort((void *)flist, nfile, sizeof(char *), strCmp);
    for (i = 0; i < nfile; i++) {
	p = flist[i];
	if (strcmp(p, ".") == 0)
	    continue;
	Strcopy(fbuf, dirname);
	if (Strlastchar(fbuf) != '/')
	    Strcat_char(fbuf, '/');
	Strcat_charp(fbuf, p);
#ifdef HAVE_LSTAT
	if (lstat(fbuf->ptr, &lst) < 0)
	    continue;
#endif				/* HAVE_LSTAT */
	if (stat(fbuf->ptr, &st) < 0)
	    continue;
	if (multicolList) {
	    if (n == 1)
		Strcat_charp(tmp, "<TD><NOBR>");
	}
	else {
#ifdef HAVE_LSTAT
	    if (S_ISLNK(lst.st_mode))
		Strcat_charp(tmp, "[LINK] ");
	    else
#endif				/* HAVE_LSTAT */
	    if (S_ISDIR(st.st_mode))
		Strcat_charp(tmp, "[DIR]&nbsp; ");
	    else
		Strcat_charp(tmp, "[FILE] ");
	}
	Strcat_m_charp(tmp, "<A HREF=\"", html_quote(file_quote(p)), NULL);
	if (S_ISDIR(st.st_mode))
	    Strcat_char(tmp, '/');
	Strcat_m_charp(tmp, "\">", html_quote(conv_from_system(p)), NULL);
	if (S_ISDIR(st.st_mode))
	    Strcat_char(tmp, '/');
	Strcat_charp(tmp, "</A>");
	if (multicolList) {
	    if (n++ == nrow) {
		Strcat_charp(tmp, "</NOBR></TD>\n");
		n = 1;
	    }
	    else {
		Strcat_charp(tmp, "<BR>\n");
	    }
	}
	else {
#if defined(HAVE_LSTAT) && defined(HAVE_READLINK)
	    if (S_ISLNK(lst.st_mode)) {
		if ((l = readlink(fbuf->ptr, lbuf, sizeof(lbuf))) > 0) {
		    lbuf[l] = '\0';
		    Strcat_m_charp(tmp, " -> ",
				   html_quote(conv_from_system(lbuf)), NULL);
		    if (S_ISDIR(st.st_mode))
			Strcat_char(tmp, '/');
		}
	    }
#endif				/* HAVE_LSTAT && HAVE_READLINK */
	    Strcat_charp(tmp, "<br>\n");
	}
    }
    if (multicolList) {
	Strcat_charp(tmp, "</TR>\n</TABLE>\n");
    }
    Strcat_charp(tmp, "</BODY>\n</HTML>\n");

    return tmp;
}

static int
check_local_cgi(char *file, int status)
{
    struct stat st;

    if (status & CGIFN_CONTAIN_SLASH) {
	/* local CGI file must be just under /cgi-bin/
	 * or /$LIB/
	 */
	return -1;
    }
#ifdef __EMX__
    if (CGIFN_MODE(status) != CGIFN_CGIBIN) {
	char tmp[_MAX_PATH];
	int len;

	_abspath(tmp, w3m_lib_dir(), _MAX_PATH);	/* Translate '\\' to '/' */
	len = strlen(tmp);
	while (len > 1 && tmp[len - 1] == '/')
	    len--;
	if (strnicmp(file, tmp, len) ||	/* and ignore case  */
	    (file[len] != '/'))
	    return -1;
    }
#else				/* not __EMX__ */
    if (CGIFN_MODE(status) != CGIFN_CGIBIN) {
	char *tmp = Strnew_charp(w3m_lib_dir())->ptr;
	int len = strlen(tmp);

	while (len > 1 && tmp[len - 1] == '/')
	    len--;
	if (strncmp(file, tmp, len) || (file[len] != '/'))
	    /* 
	     * a local-CGI script should be located on either
	     * /cgi-bin/ directory or LIB_DIR (typically /usr/local/lib/w3m).
	     */
	    return -1;
    }
#endif				/* not __EMX__ */
    if (stat(file, &st) < 0)
	return -1;
    if ((st.st_uid == geteuid() && (st.st_mode & S_IXUSR)) || (st.st_gid == getegid() && (st.st_mode & S_IXGRP)) || (st.st_mode & S_IXOTH)) {	/* executable */
	return 0;
    }
    return -1;
}

void
set_environ(char *var, char *value)
{
#ifdef HAVE_SETENV
    if (var != NULL && value != NULL)
	setenv(var, value, 1);
#else				/* not HAVE_SETENV */
#ifdef HAVE_PUTENV
    static Hash_sv *env_hash = NULL;
    Str tmp = Strnew_m_charp(var, "=", value, NULL);

    if (env_hash == NULL)
	env_hash = newHash_sv(20);
    putHash_sv(env_hash, var, (void *)tmp->ptr);
    putenv(tmp->ptr);
#else				/* not HAVE_PUTENV */
    extern char **environ;
    char **ne;
    char *p;
    int i, l, el;
    char **e, **newenv;

    /* I have no setenv() nor putenv() */
    /* This part is taken from terms.c of skkfep */
    l = strlen(var);
    for (e = environ, i = 0; *e != NULL; e++, i++) {
	if (strncmp(e, var, l) == 0 && (*e)[l] == '=') {
	    el = strlen(*e) - l - 1;
	    if (el >= strlen(value)) {
		strcpy(*e + l + 1, value);
		return 0;
	    }
	    else {
		for (; *e != NULL; e++, i++) {
		    *e = *(e + 1);
		}
		i--;
		break;
	    }
	}
    }
    newenv = (char **)GC_malloc((i + 2) * sizeof(char *));
    if (newenv == NULL)
	return;
    for (e = environ, ne = newenv; *e != NULL; *(ne++) = *(e++)) ;
    *(ne++) = p;
    *ne = NULL;
    environ = newenv;
#endif				/* not HAVE_PUTENV */
#endif				/* not HAVE_SETENV */
}

static void
set_cgi_environ(char *name, char *fn, char *req_uri)
{
    set_environ("SERVER_SOFTWARE", w3m_version);
    set_environ("SERVER_PROTOCOL", "HTTP/1.0");
    set_environ("SERVER_NAME", "localhost");
    set_environ("SERVER_PORT", "80");	/* dummy */
    set_environ("REMOTE_HOST", "localhost");
    set_environ("REMOTE_ADDR", "127.0.0.1");
    set_environ("GATEWAY_INTERFACE", "CGI/1.1");

    set_environ("SCRIPT_NAME", name);
    set_environ("SCRIPT_FILENAME", fn);
    set_environ("REQUEST_URI", req_uri);
}

static Str
checkPath(char *fn, char *path)
{
    char *p;
    Str tmp;
    struct stat st;
    while (*path) {
	p = strchr(path, ':');
	tmp = Strnew_charp(expandPath(p ? allocStr(path, p - path) : path));
	if (Strlastchar(tmp) != '/')
	    Strcat_char(tmp, '/');
	Strcat_charp(tmp, fn);
	if (stat(tmp->ptr, &st) == 0)
	    return tmp;
	if (!p)
	    break;
	path = p + 1;
	while (*path == ':')
	    path++;
    }
    return NULL;
}

static char *
cgi_filename(char *fn, int *status)
{
    Str tmp;
    struct stat st;
    if (cgi_bin != NULL && strncmp(fn, "/cgi-bin/", 9) == 0) {
	*status = CGIFN_CGIBIN;
	if (strchr(fn + 9, '/'))
	    *status |= CGIFN_CONTAIN_SLASH;
	tmp = checkPath(fn + 9, cgi_bin);
	if (tmp == NULL)
	    return fn;
	return tmp->ptr;
    }
    if (strncmp(fn, "/$LIB/", 6) == 0) {
	*status = CGIFN_NORMAL;
	tmp = Strnew_charp(w3m_lib_dir());
	fn += 5;
	if (strchr(fn + 1, '/'))
	    *status |= CGIFN_CONTAIN_SLASH;
	if (Strlastchar(tmp) == '/')
	    fn++;
	Strcat_charp(tmp, fn);
	return tmp->ptr;
    }
    if (*fn == '/' && document_root != NULL && stat(fn, &st) < 0) {
	*status = CGIFN_DROOT;
	if (strchr(fn + 1, '/'))
	    *status |= CGIFN_CONTAIN_SLASH;
	tmp = Strnew_charp(document_root);
	if (Strlastchar(tmp) != '/')
	    Strcat_char(tmp, '/');
	Strcat_charp(tmp, fn);
	return tmp->ptr;
    }
    *status = CGIFN_NORMAL;
    return fn;
}

static pid_t
localcgi_popen_rw(int *p_fdr, int *p_fdw)
{
    int fdr[2], fdw[2];
    pid_t pid;
    Str emsg;

    if (pipe(fdr) < 0) {
	emsg = Sprintf("localcgi_popen_rw: pipe: %s", strerror(errno));
	goto pipe_err0;
    }
    if (p_fdw && pipe(fdw) < 0) {
	emsg = Sprintf("localcgi_popen_rw: pipe: %s", strerror(errno));
	goto pipe_err1;
    }

    flush_tty();
    if ((pid = fork()) < 0) {
	emsg = Sprintf("localcgi_popen_rw: fork: %s", strerror(errno));
	goto pipe_err2;
    }
    else if (!pid) {
	close(fdr[0]);
	dup2(fdr[1], 1);
	if (p_fdw) {
	    close(fdw[1]);
	    dup2(fdw[0], 0);
	}
	setup_child(TRUE, 2, -1);
    }
    else {
	close(fdr[1]);
	*p_fdr = fdr[0];
	if (p_fdw) {
	    close(fdw[0]);
	    *p_fdw = fdw[1];
	}
    }
    return pid;
  pipe_err2:
    close(fdw[0]);
    close(fdw[1]);
  pipe_err1:
    close(fdr[0]);
    close(fdr[1]);
  pipe_err0:
    disp_err_message(emsg->ptr, FALSE);
    return (pid_t) - 1;
}

FILE *
localcgi_post(char *uri, char *qstr, FormList *request, char *referer)
{
    int fdr, fdw = -1;
    int status;
    pid_t pid;
    char *file;

    file = cgi_filename(uri, &status);
    if (check_local_cgi(file, status) < 0)
	return NULL;
    writeLocalCookie();
    if (request && request->enctype != FORM_ENCTYPE_MULTIPART)
	pid = localcgi_popen_rw(&fdr, &fdw);
    else
	pid = localcgi_popen_rw(&fdr, NULL);
    if (pid < 0)
	return NULL;
    else if (pid) {
	if (fdw > 0) {
	    write(fdw, request->body, request->length);
	    close(fdw);
	}
	return fdopen(fdr, "r");
    }

    if (qstr == NULL)
	set_cgi_environ(uri, file, uri);
    else
	set_cgi_environ(uri, file, Strnew_m_charp(uri, "?", qstr, NULL)->ptr);
    if (referer && referer != NO_REFERER)
	set_environ("HTTP_REFERER", referer);
    if (request) {
	set_environ("REQUEST_METHOD", "POST");
	if (qstr)
	    set_environ("QUERY_STRING", qstr);
	set_environ("CONTENT_LENGTH", Sprintf("%d", request->length)->ptr);
	if (request->enctype == FORM_ENCTYPE_MULTIPART) {
	    set_environ("CONTENT_TYPE",
			Sprintf("multipart/form-data; boundary=%s",
				request->boundary)->ptr);
	    freopen(request->body, "r", stdin);
	}
	else
	    set_environ("CONTENT_TYPE", "application/x-www-form-urlencoded");
    }
    else {
	set_environ("REQUEST_METHOD", "GET");
	set_environ("QUERY_STRING", qstr ? qstr : "");
	freopen(DEV_NULL_PATH, "r", stdin);
    }

#ifdef HAVE_CHDIR		/* ifndef __EMX__ ? */
    chdir(mydirname(file));
#endif
    execl(file, mybasename(file), NULL);
    fprintf(stderr, "execl(\"%s\", \"%s\", NULL): %s\n",
	    file, mybasename(file), strerror(errno));
    exit(1);
    return NULL;
}
