#ifndef _STR_ESCAPE_H
#define _STR_ESCAPE_H

#include <string.h>
#include <stdio.h>

static inline char
escape_c_chr(char _c) {
    switch(_c) {
    case '\0': return '0';
    case '\\': return '\\';
    case '\r': return 'r';
    case '\n': return 'n';
    case '\t': return 't';
    case '"' : return '"';
    default  : return '\0';
    }
}

static inline size_t
escape_c(char _d[], size_t _dsz, char const _f[]) {
    size_t r = 0;
    for (char const *ptr = _f; *ptr; ptr++) {
        char escape = escape_c_chr(*ptr);
        if (escape) {
            if (r < _dsz) _d[r++] = '\\';
            if (r < _dsz) _d[r++] = escape;
        } else {
            if (r < _dsz) _d[r++] = *ptr;
        }
    }
    if (r < _dsz) _d[r] = '\0';
    return r;
}

static inline void
escape_c_fp(FILE *_fp, char const _f[]) {
    for (char const *ptr = _f; *ptr; ptr++) {
        char escape = escape_c_chr(*ptr);
        if (escape) {
            fputc('\\', _fp);
            fputc(escape, _fp);
        } else {
            fputc(*ptr, _fp);
        }
    }
}




#endif
