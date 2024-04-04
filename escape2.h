#ifndef ESCAPE2_H
#define ESCAPE2_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ALPHABET_CHARS    "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ1234567890"
#define HEXADECIMAL_CHARS "0123456789abcdef"

static inline int
strcpy_escaped(
    char       *_to       /* Destination buffer. */,
    const char *_fr       /* String to escape. */,
    int         _tosz     /* Destination buffer size. */,
    const char *_escaped  /* Characters to escape. NL is escaped with \n */,
    char        _escape   /* Character to use for escaping, example \ */,
    char        _fold     /* Put this at start and end in destination buffer. */
)
{
	int t = 0, f;
	
	if (_fold) {
		_to[t++] = _fold;
	}
	for (f=0; t<(_tosz-4) && _fr[f]; f++,t++) {
		if ((!_escaped) || (!strchr(_escaped, _fr[f]))) {
			_to[t] = _fr[f];
		} else if (_fr[f] == '\n') {
			_to[t++] = _escape;
			_to[t] = 'n';
		} else {
			_to[t++] = _escape;
			_to[t] = _fr[f];
		}
	}
	if(_fold) {
		_to[t++] = _fold;
	}
	_to[t] = '\0';
	return t;
}

#endif
