/* $Id$ */
/* 
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 *
 *   Created: Wed Feb 10 12:47:03 1999
 */
extern int main(int argc, char **argv, char **envp);
extern void nulcmd(void);
extern void pushEvent(int cmd, void *data);
extern MySignalHandler intTrap(SIGNAL_ARG);
extern void pgFore(void);
extern void pgBack(void);
extern void lup1(void);
extern void ldown1(void);
extern void ctrCsrV(void);
extern void ctrCsrH(void);
extern void rdrwSc(void);
extern void srchfor(void);
extern void isrchfor(void);
extern void srchbak(void);
extern void isrchbak(void);
extern void srchnxt(void);
extern void srchprv(void);
extern void shiftl(void);
extern void shiftr(void);
extern void col1R(void);
extern void col1L(void);
extern void setEnv(void);
extern void pipeBuf(void);
extern void pipesh(void);
extern void readsh(void);
extern void execsh(void);
extern void ldfile(void);
extern void ldhelp(void);
extern void movL(void);
extern void movL1(void);
extern void movD(void);
extern void movD1(void);
extern void movU(void);
extern void movU1(void);
extern void movR(void);
extern void movR1(void);
extern void movLW(void);
extern void movRW(void);
extern void qquitfm(void);
extern void quitfm(void);
extern void selBuf(void);
extern void susp(void);
extern void goLine(void);
extern void goLineF(void);
extern void goLineL(void);
extern void linbeg(void);
extern void linend(void);
extern void editBf(void);
extern void editScr(void);
extern void followA(void);
extern void bufferA(void);
extern void followI(void);
extern void submitForm(void);
extern void followForm(void);
extern void topA(void);
extern void lastA(void);
extern void onA(void);

extern void nextA(void);
extern void prevA(void);
extern void nextVA(void);
extern void prevVA(void);
extern void nextL(void);
extern void nextLU(void);
extern void nextR(void);
extern void nextRD(void);
extern void nextD(void);
extern void nextU(void);
extern void nextBf(void);
extern void prevBf(void);
extern void backBf(void);
extern void deletePrevBuf(void);
extern void goURL(void);
extern void gorURL(void);
extern void ldBmark(void);
extern void adBmark(void);
extern void ldOpt(void);
extern void setOpt(void);
extern void pginfo(void);
extern void msgs(void);
extern void svA(void);
extern void svI(void);
extern void svBuf(void);
extern void svSrc(void);
extern void peekURL(void);
extern void peekIMG(void);
extern void curURL(void);
extern void vwSrc(void);
extern void reload(void);
extern void reshape(void);
extern void chkURL(void);
extern void chkURLBuffer(Buffer *buf);
extern void chkWORD(void);
#ifdef USE_NNTP
extern void chkNMID(void);
extern void chkNMIDBuffer(Buffer *buf);
#else
#define chkNMID nulcmd
#endif
extern void rFrame(void);
extern void extbrz(void);
extern void linkbrz(void);
extern void curlno(void);
extern void execCmd(void);
#ifdef USE_IMAGE
extern void dispI(void);
extern void stopI(void);
#else
#define dispI nulcmd
#define stopI nulcmd
#endif
#ifdef USE_ALARM
extern void setAlarm(void);
extern AlarmEvent *setAlarmEvent(AlarmEvent * event, int sec, short status,
				 int cmd, void *data);
#else
#define setAlarm nulcmd
#endif
extern void reinit(void);
extern void defKey(void);
extern void newT(void);
extern void closeT(void);
extern void nextT(void);
extern void prevT(void);
extern void tabA(void);
extern void tabURL(void);
extern void tabrURL(void);
extern void tabR(void);
extern void tabL(void);
extern void ldDL(void);
extern void linkLst(void);
#ifdef USE_MENU
extern void linkMn(void);
extern LinkList *link_menu(Buffer *buf);
extern void accessKey(void);
extern Anchor *accesskey_menu(Buffer *buf);
extern void listMn(void);
extern void movlistMn(void);
extern Anchor *list_menu(Buffer *buf);
#else
#define linkMn nulcmd
#define accessKey nulcmd
#define listMn nulcmd
#define movlistMn nulcmd
#endif
extern void undoPos(void);
extern void redoPos(void);

extern int currentLn(Buffer *buf);
extern void tmpClearBuffer(Buffer *buf);
extern char *filename_extension(char *patch, int is_url);
#ifdef USE_EXTERNAL_URI_LOADER
extern void initURIMethods();
extern Str searchURIMethods(ParsedURL *pu);
extern void chkExternalURIBuffer(Buffer *buf);
#endif
extern ParsedURL *schemeToProxy(int scheme);
extern void examineFile(char *path, URLFile *uf);
extern char *acceptableEncoding();
extern int dir_exist(char *path);
extern int is_html_type(char *type);
#ifdef USE_M17N
extern char **get_symbol(wc_ces charset, int *width);
extern char **set_symbol(int width);
extern Str convertLine(URLFile *uf, Str line, int mode, wc_ces * charset,
		       wc_ces doc_charset);
#else
extern char **get_symbol(void);
extern Str convertLine0(URLFile *uf, Str line, int mode);
#define convertLine(uf,line,mode,charset,dcharset) convertLine0(uf,line,mode)
#endif
extern void push_symbol(Str str, char symbol, int width, int n);
extern Buffer *loadFile(char *path);
extern Buffer *loadGeneralFile(char *path, ParsedURL *current, char *referer,
			       int flag, FormList *request);
extern int is_boundary(unsigned char *, unsigned char *);
extern int is_blank_line(char *line, int indent);
extern void push_render_image(Str str, int width, int limit,
			      struct html_feed_environ *h_env);
extern void flushline(struct html_feed_environ *h_env, struct readbuffer *obuf,
		      int indent, int force, int width);
extern void do_blankline(struct html_feed_environ *h_env,
			 struct readbuffer *obuf, int indent, int indent_incr,
			 int width);
extern void purgeline(struct html_feed_environ *h_env);
extern void save_fonteffect(struct html_feed_environ *h_env,
			    struct readbuffer *obuf);
extern void restore_fonteffect(struct html_feed_environ *h_env,
			       struct readbuffer *obuf);
#ifdef USE_IMAGE
extern void deleteImage(Buffer *buf);
extern void getAllImage(Buffer *buf);
extern void loadImage(Buffer *buf, int flag);
extern ImageCache *getImage(Image * image, ParsedURL *current, int flag);
extern int getImageSize(ImageCache * cache);
#endif
extern Str process_img(struct parsed_tag *tag, int width);
extern Str process_anchor(struct parsed_tag *tag, char *tagbuf);
extern Str process_input(struct parsed_tag *tag);
extern Str process_select(struct parsed_tag *tag);
extern Str process_n_select(void);
extern void feed_select(char *str);
extern void process_option(void);
extern Str process_textarea(struct parsed_tag *tag, int width);
extern Str process_n_textarea(void);
extern void feed_textarea(char *str);
extern Str process_form(struct parsed_tag *tag);
extern Str process_n_form(void);
extern int getMetaRefreshParam(char *q, Str *refresh_uri);
extern int HTMLtagproc1(struct parsed_tag *tag,
			struct html_feed_environ *h_env);
extern void HTMLlineproc2(Buffer *buf, TextLineList *tl);
extern void HTMLlineproc0(char *istr, struct html_feed_environ *h_env,
			  int internal);
#define HTMLlineproc1(x,y) HTMLlineproc0(x,y,TRUE)
extern Buffer *loadHTMLBuffer(URLFile *f, Buffer *newBuf);
extern char *convert_size(clen_t size, int usefloat);
extern char *convert_size2(clen_t size1, clen_t size2, int usefloat);
extern void showProgress(clen_t * linelen, clen_t * trbyte);
extern void init_henv(struct html_feed_environ *, struct readbuffer *,
		      struct environment *, int, TextLineList *, int, int);
extern void completeHTMLstream(struct html_feed_environ *,
			       struct readbuffer *);
extern void loadHTMLstream(URLFile *f, Buffer *newBuf, FILE * src,
			   int internal);
extern Buffer *loadHTMLString(Str page);
#ifdef USE_GOPHER
extern Str loadGopherDir(URLFile *uf, ParsedURL *pu, wc_ces * charset);
#endif				/* USE_GOPHER */
extern Buffer *loadBuffer(URLFile *uf, Buffer *newBuf);
#ifdef USE_IMAGE
extern Buffer *loadImageBuffer(URLFile *uf, Buffer *newBuf);
#endif
extern void saveBuffer(Buffer *buf, FILE * f, int cont);
extern void saveBufferBody(Buffer *buf, FILE * f, int cont);
extern Buffer *getshell(char *cmd);
extern Buffer *getpipe(char *cmd);
extern Buffer *openPagerBuffer(InputStream stream, Buffer *buf);
extern Buffer *openGeneralPagerBuffer(InputStream stream);
extern Line *getNextPage(Buffer *buf, int plen);
extern int save2tmp(URLFile uf, char *tmpf);
extern int doExternal(URLFile uf, char *path, char *type, Buffer **bufp,
		      Buffer *defaultbuf);
extern int _doFileCopy(char *tmpf, char *defstr, int download);
#define doFileCopy(tmpf, defstr) _doFileCopy(tmpf, defstr, FALSE);
extern int doFileMove(char *tmpf, char *defstr);
extern int doFileSave(URLFile uf, char *defstr);
extern int checkCopyFile(char *path1, char *path2);
extern int checkSaveFile(InputStream stream, char *path);
extern int checkOverWrite(char *path);
extern char *inputAnswer(char *prompt);
extern int matchattr(char *p, char *attr, int len, Str *value);
extern void readHeader(URLFile *uf, Buffer *newBuf, int thru, ParsedURL *pu);
extern char *checkHeader(Buffer *buf, char *field);
extern TabBuffer *newTab(void);
extern void calcTabPos(void);
extern TabBuffer *deleteTab(TabBuffer * tab);
extern void addDownloadList(pid_t pid, char *url, char *save, char *lock,
			    clen_t size);
extern void stopDownload(void);
extern int checkDownloadList(void);
extern void download_action(struct parsed_tagarg *arg);
extern Buffer *newBuffer(int width);
extern Buffer *nullBuffer(void);
extern void clearBuffer(Buffer *buf);
extern void discardBuffer(Buffer *buf);
extern Buffer *namedBuffer(Buffer *first, char *name);
extern Buffer *deleteBuffer(Buffer *first, Buffer *delbuf);
extern Buffer *replaceBuffer(Buffer *first, Buffer *delbuf, Buffer *newbuf);
extern Buffer *nthBuffer(Buffer *firstbuf, int n);
extern void gotoRealLine(Buffer *buf, int n);
extern void gotoLine(Buffer *buf, int n);
extern Buffer *selectBuffer(Buffer *firstbuf, Buffer *currentbuf,
			    char *selectchar);
extern void reshapeBuffer(Buffer *buf);
extern void copyBuffer(Buffer *a, Buffer *b);
extern Buffer *prevBuffer(Buffer *first, Buffer *buf);
extern int writeBufferCache(Buffer *buf);
extern int readBufferCache(Buffer *buf);
extern void fmTerm(void);
extern void fmInit(void);
extern void displayBuffer(Buffer *buf, int mode);
extern void addChar(char c, Lineprop mode);
#ifdef USE_M17N
extern void addMChar(char *c, Lineprop mode, size_t len);
#endif
extern void record_err_message(char *s);
extern Buffer *message_list_panel(void);
extern void message(char *s, int return_x, int return_y);
extern void disp_err_message(char *s, int redraw_current);
extern void disp_message_nsec(char *s, int redraw_current, int sec, int purge,
			      int mouse);
extern void disp_message(char *s, int redraw_current);
#ifdef USE_MOUSE
extern void disp_message_nomouse(char *s, int redraw_current);
#else
#define disp_message_nomouse disp_message
#endif
extern void set_delayed_message(char *s);
extern void cursorUp0(Buffer *buf, int n);
extern void cursorUp(Buffer *buf, int n);
extern void cursorDown0(Buffer *buf, int n);
extern void cursorDown(Buffer *buf, int n);
extern void cursorUpDown(Buffer *buf, int n);
extern void cursorRight(Buffer *buf, int n);
extern void cursorLeft(Buffer *buf, int n);
extern void cursorHome(Buffer *buf);
extern void arrangeCursor(Buffer *buf);
extern void arrangeLine(Buffer *buf);
extern void cursorXY(Buffer *buf, int x, int y);
extern void restorePosition(Buffer *buf, Buffer *orig);
extern int columnSkip(Buffer *buf, int offset);
extern int columnPos(Line *line, int column);
extern int columnLen(Line *line, int column);
extern Line *lineSkip(Buffer *buf, Line *line, int offset, int last);
extern Line *currentLineSkip(Buffer *buf, Line *line, int offset, int last);
extern int gethtmlcmd(char **s);
#ifndef USE_ANSI_COLOR
#define checkType(a,b,c) _checkType(a,b)
#endif
extern Str checkType(Str s, Lineprop **oprop, Linecolor **ocolor);
extern int calcPosition(char *l, Lineprop *pr, int len, int pos, int bpos,
			int mode);
extern char *lastFileName(char *path);
extern char *mybasename(char *s);
extern char *mydirname(char *s);
extern int next_status(char c, int *status);
extern int read_token(Str buf, char **instr, int *status, int pre, int append);
extern Str correct_irrtag(int status);
#ifdef USE_MIGEMO
extern void init_migemo(void);
#endif
#ifdef USE_M17N
extern char *conv_search_string(char *str, wc_ces f_ces);
#else
#define conv_search_string(str, f_ces)	str
#endif
extern int forwardSearch(Buffer *buf, char *str);
extern int backwardSearch(Buffer *buf, char *str);
extern void pcmap(void);
extern void escmap(void);
extern void escbmap(void);
extern void escdmap(char c);
extern void multimap(void);
extern char *inputLineHistSearch(char *prompt, char *def_str, int flag,
				 Hist *hist, int (*incfunc) (int ch, Str buf,
							     Lineprop *prop));
extern Str unescape_spaces(Str s);
#ifdef USE_HISTORY
extern Buffer *historyBuffer(Hist *hist);
extern void loadHistory(Hist *hist);
extern void saveHistory(Hist *hist, size_t size);
extern void ldHist(void);
#else				/* not USE_HISTORY */
#define ldHist nulcmd
#endif				/* not USE_HISTORY */
extern double log_like(int x);
extern struct table *newTable(void);
extern void pushdata(struct table *t, int row, int col, char *data);
extern int visible_length(char *str);
extern void align(TextLine *lbuf, int width, int mode);
extern void print_item(struct table *t, int row, int col, int width, Str buf);
extern void print_sep(struct table *t, int row, int type, int maxcol, Str buf);
extern void do_refill(struct table *tbl, int row, int col, int maxlimit);
extern void renderTable(struct table *t, int max_width,
			struct html_feed_environ *h_env);
extern struct table *begin_table(int border, int spacing, int padding,
				 int vspace);
extern void end_table(struct table *tbl);
extern void check_rowcol(struct table *tbl, struct table_mode *mode);
extern int minimum_length(char *line);
extern int feed_table(struct table *tbl, char *line, struct table_mode *mode,
		      int width, int internal);
extern void feed_table1(struct table *tbl, Str tok, struct table_mode *mode,
			int width);
extern void pushTable(struct table *, struct table *);
extern struct form_list *newFormList(char *action, char *method, char *charset,
				     char *enctype, char *target, char *name,
				     struct form_list *_next);
extern struct form_item_list *formList_addInput(struct form_list *fl,
						struct parsed_tag *tag);
extern char *form2str(FormItemList *fi);
extern int formtype(char *typestr);
extern void formRecheckRadio(Anchor *a, Buffer *buf, FormItemList *form);
extern void formResetBuffer(Buffer *buf, AnchorList *formitem);
extern void formUpdateBuffer(Anchor *a, Buffer *buf, FormItemList *form);
extern void preFormUpdateBuffer(Buffer *buf);
extern Str textfieldrep(Str s, int width);
extern void input_textarea(FormItemList *fi);
extern void do_internal(char *action, char *data);
extern void form_write_data(FILE * f, char *boundary, char *name, char *value);
extern void form_write_from_file(FILE * f, char *boundary, char *name,
				 char *filename, char *file);
extern MapList *searchMapList(Buffer *buf, char *name);
extern void follow_map(struct parsed_tagarg *arg);
#if defined(MENU_MAP) || defined(USE_IMAGE)
extern MapArea *follow_map_menu(Buffer *buf, char *name, Anchor *a_img, int x,
				int y);
#endif
#ifndef MENU_MAP
extern Buffer *follow_map_panel(Buffer *buf, char *name);
#endif
#ifdef USE_IMAGE
extern int getMapXY(Buffer *buf, Anchor *a, int *x, int *y);
extern MapArea *retrieveCurrentMapArea(Buffer *buf);
#endif
extern Anchor *retrieveCurrentMap(Buffer *buf);
extern MapArea *newMapArea(char *url, char *target, char *alt, char *shape,
			   char *coords);
extern Buffer *page_info_panel(Buffer *buf);
extern struct frame_body *newFrame(struct parsed_tag *tag, Buffer *buf);
extern struct frameset *newFrameSet(struct parsed_tag *tag);
extern void addFrameSetElement(struct frameset *f,
			       union frameset_element element);
extern void deleteFrame(struct frame_body *b);
extern void deleteFrameSet(struct frameset *f);
extern void deleteFrameSetElement(union frameset_element e);
extern struct frameset *copyFrameSet(struct frameset *of);
extern void pushFrameTree(struct frameset_queue **fqpp, struct frameset *fs,
			  Buffer *buf);
extern struct frameset *popFrameTree(struct frameset_queue **fqpp);
extern void resetFrameElement(union frameset_element *f_element, Buffer *buf,
			      char *referer, FormList *request);
extern Buffer *renderFrame(Buffer *Cbuf, int force_reload);
extern union frameset_element *search_frame(struct frameset *fset, char *name);
extern int set_tty(void);
extern void set_cc(int spec, int val);
extern void close_tty(void);
extern char *ttyname_tty(void);
extern void reset_tty(void);
extern MySignalHandler reset_exit(SIGNAL_ARG);
extern MySignalHandler error_dump(SIGNAL_ARG);
extern void set_int(void);
extern void getTCstr(void);
extern void setlinescols(void);
extern void setupscreen(void);
extern pid_t open_pipe_rw(FILE ** fr, FILE ** fw);
extern int initscr(void);
extern void move(int line, int column);
#ifdef USE_M17N
extern void addmch(char *p, size_t len);
#endif
extern void addch(char c);
extern void wrap(void);
extern void touch_line(void);
extern void standout(void);
extern void standend(void);
extern void bold(void);
extern void boldend(void);
extern void underline(void);
extern void underlineend(void);
extern void graphstart(void);
extern void graphend(void);
extern int graph_ok(void);
#ifdef USE_COLOR
extern void setfcolor(int color);
#ifdef USE_BG_COLOR
extern void setbcolor(int color);
#endif				/* USE_BG_COLOR */
#endif				/* USE_COLOR */
extern void refresh(void);
extern void clear(void);
#ifdef USE_RAW_SCROLL
extern void scroll(int);
extern void rscroll(int);
#endif
#if 0
extern void need_clrtoeol(void);
#endif
extern void clrtoeol(void);
extern void clrtoeolx(void);
extern void clrtobot(void);
extern void clrtobotx(void);
extern void no_clrtoeol(void);
extern void addstr(char *s);
extern void addnstr(char *s, int n);
extern void addnstr_sup(char *s, int n);
extern void crmode(void);
extern void nocrmode(void);
extern void term_echo(void);
extern void term_noecho(void);
extern void term_raw(void);
extern void term_cooked(void);
extern void term_cbreak(void);
extern void term_title(char *s);
extern void flush_tty(void);
extern void toggle_stand(void);
extern char getch(void);
extern void bell(void);
extern int sleep_till_anykey(int sec, int purge);
#ifdef USE_IMAGE
extern void touch_cursor();
#endif
extern void initMimeTypes();
extern void free_ssl_ctx();
extern ParsedURL *baseURL(Buffer *buf);
extern int openSocket(char *hostname, char *remoteport_name,
		      unsigned short remoteport_num);
extern void parseURL(char *url, ParsedURL *p_url, ParsedURL *current);
extern void copyParsedURL(ParsedURL *p, ParsedURL *q);
extern void parseURL2(char *url, ParsedURL *pu, ParsedURL *current);
extern Str parsedURL2Str(ParsedURL *pu);
extern int getURLScheme(char **url);
extern void init_stream(URLFile *uf, int scheme, InputStream stream);
Str HTTPrequestMethod(HRequest *hr);
Str HTTPrequestURI(ParsedURL *pu, HRequest *hr);
extern URLFile openURL(char *url, ParsedURL *pu, ParsedURL *current,
		       URLOption *option, FormList *request,
		       TextList *extra_header, URLFile *ouf,
		       HRequest *hr, unsigned char *status);
extern int mailcapMatch(struct mailcap *mcap, char *type);
extern struct mailcap *searchMailcap(struct mailcap *table, char *type);
extern void initMailcap();
extern char *acceptableMimeTypes();
extern struct mailcap *searchExtViewer(char *type);
extern Str unquote_mailcap(char *qstr, char *type, char *name, char *attr,
			   int *mc_stat);
extern char *guessContentType(char *filename);
extern TextList *make_domain_list(char *domain_list);
extern int check_no_proxy(char *domain);
extern InputStream openFTPStream(ParsedURL *pu, URLFile *uf);
#ifdef USE_M17N
extern Str loadFTPDir(ParsedURL *pu, wc_ces * charset);
#else
extern Str loadFTPDir0(ParsedURL *pu);
#define loadFTPDir(pu,charset)	loadFTPDir0(pu)
#endif
extern void closeFTP(void);
extern void disconnectFTP(void);
#ifdef USE_NNTP
extern InputStream openNewsStream(ParsedURL *pu);
#ifdef USE_M17N
extern Str loadNewsgroup(ParsedURL *pu, wc_ces * charset);
#else
extern Str loadNewsgroup0(ParsedURL *pu);
#define loadNewsgroup(pu,charset) loadNewsgroup0(pu)
#endif
extern void closeNews(void);
extern void disconnectNews(void);
#endif
extern AnchorList *putAnchor(AnchorList *al, char *url, char *target,
			     Anchor **anchor_return, char *referer,
			     char *title, unsigned char key, int line,
			     int pos);
extern Anchor *registerHref(Buffer *buf, char *url, char *target,
			    char *referer, char *title, unsigned char key,
			    int line, int pos);
extern Anchor *registerName(Buffer *buf, char *url, int line, int pos);
extern Anchor *registerImg(Buffer *buf, char *url, char *title, int line,
			   int pos);
extern Anchor *registerForm(Buffer *buf, FormList *flist,
			    struct parsed_tag *tag, int line, int pos);
extern int onAnchor(Anchor *a, int line, int pos);
extern Anchor *retrieveAnchor(AnchorList *al, int line, int pos);
extern Anchor *retrieveCurrentAnchor(Buffer *buf);
extern Anchor *retrieveCurrentImg(Buffer *buf);
extern Anchor *retrieveCurrentForm(Buffer *buf);
extern Anchor *searchAnchor(AnchorList *al, char *str);
extern Anchor *searchURLLabel(Buffer *buf, char *url);
extern void reAnchorWord(Buffer *buf, Line *l, int spos, int epos);
extern char *reAnchor(Buffer *buf, char *re);
#ifdef USE_NNTP
extern char *reAnchorNews(Buffer *buf, char *re);
extern char *reAnchorNewsheader(Buffer *buf);
#endif				/* USE_NNTP */
extern void addMultirowsForm(Buffer *buf, AnchorList *al);
extern Anchor *closest_next_anchor(AnchorList *a, Anchor *an, int x, int y);
extern Anchor *closest_prev_anchor(AnchorList *a, Anchor *an, int x, int y);
#ifdef USE_IMAGE
void addMultirowsImg(Buffer *buf, AnchorList *al);
#endif
extern HmarkerList *putHmarker(HmarkerList *ml, int line, int pos, int seq);
extern void shiftAnchorPosition(AnchorList *a, HmarkerList *hl, int line,
				int pos, int shift);
extern char *getAnchorText(Buffer *buf, AnchorList *al, Anchor *a);
extern Buffer *link_list_panel(Buffer *buf);

extern Str decodeB(char **ww);
extern Str decodeQ(char **ww);
extern Str decodeQP(char **ww);
extern Str decodeU(char **ww);
#ifdef USE_M17N
extern Str decodeWord(char **ow, wc_ces * charset);
extern Str decodeMIME(Str orgstr, wc_ces * charset);
#else
extern Str decodeWord0(char **ow);
extern Str decodeMIME0(Str orgstr);
#define decodeWord(ow,charset) decodeWord0(ow)
#define decodeMIME(orgstr,charset) decodeMIME0(orgstr)
#endif
extern Str encodeB(char *a);
extern int set_param_option(char *option);
extern char *get_param_option(char *name);
extern void init_rc(void);
extern Buffer *load_option_panel(void);
extern void panel_set_option(struct parsed_tagarg *);
extern void sync_with_option(void);
extern char *rcFile(char *base);
extern char *etcFile(char *base);
extern char *confFile(char *base);
extern char *auxbinFile(char *base);
extern char *libFile(char *base);
extern char *helpFile(char *base);
extern Str localCookie(void);
extern Str loadLocalDir(char *dirname);
extern void set_environ(char *var, char *value);
extern FILE *localcgi_post(char *, char *, FormList *, char *);
#define localcgi_get(u, q, r) localcgi_post((u), (q), NULL, (r))
extern FILE *openSecretFile(char *fname);
extern void loadPasswd(void);
extern void loadPreForm(void);
extern int find_auth_user_passwd(ParsedURL *pu, char *realm,
				 Str *uname, Str *pwd, int is_proxy);
extern void add_auth_user_passwd(ParsedURL *pu, char *realm,
				 Str uname, Str pwd, int is_proxy);
extern void invalidate_auth_user_passwd(ParsedURL *pu, char *realm,
					Str uname, Str pwd, int is_proxy);
extern char *last_modified(Buffer *buf);
extern Str romanNumeral(int n);
extern Str romanAlphabet(int n);
extern void setup_child(int child, int i, int f);
extern void myExec(char *command);
extern void mySystem(char *command, int background);
extern Str myExtCommand(char *cmd, char *arg, int redirect);
extern Str myEditor(char *cmd, char *file, int line);
extern char *file_to_url(char *file);
#ifdef USE_M17N
extern char *url_unquote_conv(char *url, wc_ces charset);
#else
extern char *url_unquote_conv0(char *url);
#define url_unquote_conv(url, charset) url_unquote_conv0(url)
#endif
extern char *expandName(char *name);
extern Str tmpfname(int type, char *ext);
extern time_t mymktime(char *timestr);
extern void (*mySignal(int signal_number, void (*action) (int))) (int);
#ifdef USE_COOKIE
extern char *FQDN(char *host);
extern Str find_cookie(ParsedURL *pu);
extern int add_cookie(ParsedURL *pu, Str name, Str value, time_t expires,
		      Str domain, Str path, int flag, Str comment, int version,
		      Str port, Str commentURL);
extern void save_cookies(void);
extern void load_cookies(void);
extern void initCookie(void);
extern void cooLst(void);
extern Buffer *cookie_list_panel(void);
extern void set_cookie_flag(struct parsed_tagarg *arg);
extern int check_cookie_accept_domain(char *domain);
#else				/* not USE_COOKIE */
#define cooLst nulcmd
#endif				/* not USE_COOKIE */
#ifdef USE_M17N
extern void docCSet(void);
extern void defCSet(void);
extern void change_charset(struct parsed_tagarg *arg);
#else
#define docCSet nulcmd
#define defCSet nulcmd
#endif

#ifdef USE_MARK
extern void _mark(void);
extern void nextMk(void);
extern void prevMk(void);
extern void reMark(void);
#else				/* not USE_MARK */
#define _mark  nulcmd
#define nextMk nulcmd
#define prevMk nulcmd
#define reMark nulcmd
#endif				/* not USE_MARK */

#ifdef USE_MOUSE
extern void mouse(void);
extern void mouse_init(void);
extern void mouse_end(void);
extern void mouse_active(void);
extern void mouse_inactive(void);
extern void msToggle(void);
extern void movMs(void);
#ifdef USE_MENU
extern void menuMs(void);
#else
#define menuMs nulcmd
#endif
extern void tabMs(void);
extern void closeTMs(void);
#else				/* not USE_MOUSE */
#define mouse nulcmd
#define msToggle nulcmd
#define movMs nulcmd
#define menuMs nulcmd
#define tabMs nulcmd
#define closeTMs nulcmd
#endif				/* not USE_MOUSE */

#ifdef USE_IMAGE
extern void initImage(void);
extern void termImage(void);
extern void addImage(ImageCache * cache, int x, int y, int sx, int sy, int w,
		     int h);
extern void drawImage(void);
extern void clearImage(void);
#endif

extern char *searchKeyData(void);

extern void setKeymap(char *p, int lineno, int verbose);
extern void initKeymap(int force);
extern int getFuncList(char *id);
extern int getKey(char *s);
extern char *getKeyData(int key);
extern char *getWord(char **str);
extern char *getQWord(char **str);
#ifdef USE_MOUSE
extern void initMouseAction(void);
#endif

#ifdef USE_MENU
extern void new_menu(Menu *menu, MenuItem *item);
extern void geom_menu(Menu *menu, int x, int y, int mselect);
extern void draw_all_menu(Menu *menu);
extern void draw_menu(Menu *menu);
extern void draw_menu_item(Menu *menu, int mselect);
extern int select_menu(Menu *menu, int mselect);
extern void goto_menu(Menu *menu, int mselect, int down);
extern void up_menu(Menu *menu, int n);
extern void down_menu(Menu *menu, int n);
extern int action_menu(Menu *menu);
extern void popup_menu(Menu *parent, Menu *menu);
extern void guess_menu_xy(Menu *menu, int width, int *x, int *y);
extern void new_option_menu(Menu *menu, char **label, int *variable,
			    void (*func) ());

extern int setMenuItem(MenuItem *item, char *type, char *line);
extern int addMenuList(MenuList **list, char *id);
extern int getMenuN(MenuList *list, char *id);

extern void popupMenu(int x, int y, Menu *menu);
extern void mainMenu(int x, int y);
extern void mainMn(void);
extern void selMn(void);
extern void tabMn(void);
extern void optionMenu(int x, int y, char **label, int *variable, int initial,
		       void (*func) ());
extern void initMenu(void);
#else				/* not USE_MENU */
#define mainMn nulcmd
#define selMn selBuf
#define tabMn nulcmd
#endif				/* not USE_MENU */

#ifdef USE_DICT
extern void dictword(void);
extern void dictwordat(void);
#else				/* not USE_DICT */
#define dictword nulcmd
#define dictwordat nulcmd
#endif				/* not USE_DICT */
#if 0
extern void reloadBuffer(Buffer *buf);
#endif
extern char *guess_save_name(Buffer *buf, char *file);

extern void wrapToggle(void);
#ifdef USE_BUFINFO
extern void saveBufferInfo(void);
#endif

extern Str getLinkNumberStr(int correction);

extern void dispVer(void);

#ifdef USE_INCLUDED_SRAND48
void srand48(long);
long lrand48(void);
#endif

#include "indep.h"
