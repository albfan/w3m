/* $Id$ */
#ifndef TERMS_H
#define TERMS_H

extern int LINES, COLS;
#if defined(__CYGWIN__) && LANG == JA
extern int LASTLINE;
#endif

#define CODE_ASCII	'\0'
#define CODE_EUC	'E'
#define CODE_SJIS	'S'
#define CODE_JIS_n	'n'
#define CODE_JIS_m	'm'
#define CODE_JIS_N	'N'
#define CODE_JIS_j	'j'
#define CODE_JIS_J	'J'
#define CODE_INNER_EUC	'I'

#define STR_ASCII	"US_ASCII"
#define STR_EUC		"EUC-JP"
#define STR_SJIS	"Shift_JIS"
#define STR_JIS_n	"ISO-2022-JP (JIS X 0208 + US_ASCII)"
#define STR_JIS_m	"ISO-2022-JP (JIS C 6226 + US_ASCII)"
#define STR_JIS_N	"ISO-2022-JP (JIS X 0208 + JIS X 0201)"
#define STR_JIS_j	"ISO-2022-JP (JIS C 6226 + JIS X 0201)"
#define STR_JIS_J	"ISO-2022-JP (JIS C 6226 + '\033(H')"
#define STR_INNER_EUC	"EUC-JP (internal)"

#define CODE_JIS(x) ((x)==CODE_JIS_n||(x)==CODE_JIS_m||(x)==CODE_JIS_N||(x)==CODE_JIS_j||(x)==CODE_JIS_J)

#ifdef USE_MOUSE
/* Addition:mouse event */
#define MOUSE_BTN1_DOWN 0
#define MOUSE_BTN2_DOWN 1
#define MOUSE_BTN3_DOWN 2
#define MOUSE_BTN4_DOWN_RXVT 3
#define MOUSE_BTN5_DOWN_RXVT 4
#define MOUSE_BTN4_DOWN_XTERM 64
#define MOUSE_BTN5_DOWN_XTERM 65
#define MOUSE_BTN_UP 3
#define MOUSE_BTN_RESET -1
#endif

#ifdef __CYGWIN__
#ifdef USE_MOUSE
extern int cygwin_mouse_btn_swapped;
#endif
#ifdef SUPPORT_WIN9X_CONSOLE_MBCS
extern void enable_win9x_console_input(void);
extern void disable_win9x_console_input(void);
#endif
#endif

#endif				/* not TERMS_H */
