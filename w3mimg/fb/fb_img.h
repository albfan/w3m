/* $Id$ */
#ifndef fb_img_header
#define fb_img_header
#include "fb.h"

FB_IMAGE **fb_image_load(char *filename, int w, int h);
void fb_image_set_bg(int r, int g, int b);
int get_image_size(char *filename, int *w, int *h);

#endif
