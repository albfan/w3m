/*
 * Configuration for w3m
 */

#ifndef _CONFIGURED_
#define _CONFIGURED_

/* User Configuration */

/* 
   If you define DICT, you can use dictionary look-up function
   in w3m. See README.dict for detail.
*/
#undef DICT

/*
   If you define USE_MARK, you can use set-mark (C-SPC),
   goto-next-mark (ESC p), goto-next-mark (ESC n) and
   mark-by-regexp (").
*/
#undef USE_MARK

/*
   If you want to load and save URL history.
 */
#define USE_HISTORY

/*
   BG_COLOR enables w3m to set background color.
 */
#define BG_COLOR

/*
   VIEW_UNSEENOBJECTS enables w3m to make a link to unseen objects.
   e.g. background image.
 */
#undef VIEW_UNSEENOBJECTS

/*
   VI_PREC_NUM enables vi-like behavior for '2 SPC' or '2 b'
 */
#undef VI_PREC_NUM

/*
 * Do word fill
 */
#undef FORMAT_NICE

/*
 * Support Gopher protocol
 */
#undef USE_GOPHER

/*
 * Support NNTP
 */
#undef USE_NNTP

/*
 * Support ANSI color escape sequences
 */
#undef ANSI_COLOR

/*
 * Enable id attribute
 */
#define ID_EXT

/*
 * Save Current-buffer Information
 */
#define BUFINFO

/*
 * Support EGD (Entropy Gathering Daemon)
 */
#undef USE_EGD

/*
 * Use Emacs-like key binding for file name completion
 */
#undef EMACS_LIKE_LINEEDIT

/*
 * Remove line trailing spaces in html buffer.
 */
#undef ENABLE_REMOVE_TRAILINGSPACES

/*
 * Move cursor to top line when going to label.
 */
#undef LABEL_TOPLINE

/*
 * Move cursor to top line when moving to next page.
 */
#undef NEXTPAGE_TOPLINE

/**********************************************************/
#ifdef makefile_parameter

BIN_DIR = /usr/local/bin
HELP_DIR = /usr/local/lib/w3m
LIB_DIR = /usr/local/lib/w3m
HELP_FILE = w3mhelp-w3m_ja.html
SYS_LIBRARIES = -lgpm  -lbsd -lnsl -lncurses  -L/usr/lib -L/usr/lib -L/usr/local/ssl/lib -L/usr/local/ssl/lib -lssl -lcrypto 
LOCAL_LIBRARIES = 
CC = gcc
MYCFLAGS = -O -I./gc/include  -I/usr/local/ssl/include/openssl -I/usr/local/ssl/include
GCCFLAGS = -O -I./gc/include -I./$(srcdir)/include -DATOMIC_UNCOLLECTABLE -DNO_SIGNALS -DNO_EXECUTE_PERMISSION -DSILENT -DALL_INTERIOR_POINTERS
KEYBIND_SRC = keybind.c
KEYBIND_OBJ = keybind.o
EXT=
MATHLIB=-lm
Z_CFLAGS=-I/usr/include
ZLIB=-L/usr/lib -lz
EXT_TARGETS=$(BOOKMARKER) $(HELPER) $(INFLATE)
GC_CFLAGS=
GCLIB=gc/gc.a
GCTARGET=gc/gc.a
RANLIB=ranlib
MKDIR=mkdir -p
VERSION=0.2.1-inu-1.5
MODEL=Linux.i686-monster-ja
#else


#define DISPLAY_CODE 'E'
#define SYSTEM_CODE 'E'

#define JA 0
#define EN 1
#define LANG JA
#define KANJI_SYMBOLS
#define COLOR
#define MOUSE
#define USE_GPM
#undef USE_SYSMOUSE
#define MENU
#define USE_COOKIE
#define USE_SSL
#undef USE_SSL_VERIFY
#undef FTPPASS_HOSTNAMEGEN
#undef SHOW_PARAMS

#define DEF_EDITOR "/bin/vi"
#define DEF_MAILER "/bin/mail"
#define DEF_EXT_BROWSER "/usr/bin/netscape"

#define LIB_DIR      "/usr/local/lib/w3m"
#define HELP_DIR     "/usr/local/lib/w3m"
#define HELP_FILE    "w3mhelp.html"
#define W3MCONFIG    "w3mconfig"

#define RC_DIR       "~/.w3m/"
#define BOOKMARK     "bookmark.html"
#define CONFIG_FILE  "config"
#define KEYMAP_FILE  "keymap"
#define MENU_FILE    "menu"
#define COOKIE_FILE  "cookie"
#define HISTORY_FILE "history"

#define USER_MAILCAP RC_DIR "/mailcap"
#define SYS_MAILCAP  "/etc/mailcap"
#define USER_MIMETYPES "~/.mime.types"
#define SYS_MIMETYPES "/usr/local/lib/mime.types"

#define DEF_SAVE_FILE "index.html"

#undef USE_BINMODE_STREAM
#define HAVE_TERMIOS_H
#define HAVE_DIRENT_H
#define HAVE_STRCASECMP
#define HAVE_STRCHR
#define HAVE_STRERROR
#define HAVE_SYS_ERRLIST
#define HAVE_BCOPY
#define HAVE_WAITPID
#define HAVE_WAIT3
#define HAVE_STRFTIME

#define HAVE_GETCWD
#define HAVE_GETWD
#define HAVE_READLINK
#define HAVE_SETENV
#define HAVE_PUTENV
#define HAVE_SRAND48
#define HAVE_SRANDOM

#define SETJMP(env) sigsetjmp(env,1)
#define LONGJMP(env,val) siglongjmp(env,val)
#define JMP_BUF sigjmp_buf

typedef void MySignalHandler;
#define SIGNAL_ARG int _dummy
#define SIGNAL_ARGLIST 0
#define SIGNAL_RETURN return
#define HAVE_SETPGRP

/*
   If you want to use IPv6, define this symbol.
 */
#undef INET6


#undef TABLE_EXPAND
#undef TABLE_NO_COMPACT
#define NOWRAP 1
#define MATRIX 1
#define HAVE_FLOAT_H

#ifndef HAVE_SRAND48
#ifdef HAVE_SRANDOM
#define srand48 srandom
#define lrand48 random
#else /* HAVE_SRANDOM */
#define USE_INCLUDED_SRAND48
#endif /* HAVE_SRANDOM */
#endif

#if defined( __CYGWIN32__ ) && !defined( __CYGWIN__ )
#define __CYGWIN__
#endif

#if defined( __CYGWIN__ ) || defined( __EMX__ )
#define SUPPORT_DOS_DRIVE_PREFIX 1
#endif

#endif /* makefile_parameter */
#endif /* _CONFIGURED_ */

