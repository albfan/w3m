/* $Id$ */

#include "w3mimg/w3mimg.h"

w3mimg_op *w3mimg_open() {
    w3mimg_op *w_op = NULL;
#ifdef USE_W3MIMG_X11
    if (w_op == NULL)
	w_op = w3mimg_x11open();
#endif
#ifdef USE_W3MIMG_FB
    if (w_op == NULL)
	w_op = w3mimg_fbopen();
#endif
    return w_op;
}
