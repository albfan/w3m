/* $Id$ */
/*
 * w3m func.h
 */

#ifndef FUNC_H
#define FUNC_H

#include "textlist.h"
#include "hash.h"

#define KEY_HASH_SIZE 127

#define K_ESC  0x100
#define K_ESCB 0x200
#define K_ESCD 0x400
#define K_MULTI 0x10000000
#define MULTI_KEY(c) (((c) >> 16) & 0x77F)

typedef struct _FuncList {
    char *id;
    void (*func) ();
} FuncList;

#endif				/* not FUNC_H */
