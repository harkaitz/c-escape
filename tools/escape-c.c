#define _POSIX_C_SOURCE 201000L
#include "../escape.h"
#include <getopt.h>
#include <stdlib.h>
#include <libgen.h>

#define COPYRIGHT_LINE \
    "Bug reports, feature requests to gemini|https://harkadev.com/oss" "\n" \
    "Copyright (c) 2022 Harkaitz Agirre, harkaitz.aguirre@gmail.com" "\n" \
    ""

int main (int _argc, char *_argv[]) {

    int chr, opt, count, open, macro = 0, cols = 0;
    char const *indent = "";
    FILE       *input  = stdin;
    char const *name   = NULL;

    if (_argc > 1 && (!strcmp(_argv[1], "--help") || !strcmp(_argv[1], "-h"))) {
        fprintf(stdout,
                "Usage: %s OPTIONS < DATA"                                            "\n"
                ""                                                                    "\n"
                "Convert data readen from the standard input to a C string."          "\n"
                ""                                                                    "\n"
                "-m        : Consider it to be in a macro, put a \"\\\" before LF."   "\n"
                "-i INDENT : Prefix new lines with INDENT."                           "\n"
                "-c COLS   : Break lines in COLS columns."                            "\n"
                "-d DATA   : Use DATA instead of reading from the standard input."    "\n"
                "-n NAME   : Put '#define NAME ' before the string (Implies -m)."     "\n"
                ""                                                                    "\n"
                COPYRIGHT_LINE, basename(_argv[0]));
        return 0;
    }
    
    while((opt = getopt (_argc, _argv, "mi:c:d:n:")) != -1) {
        switch (opt) {
        case 'm': macro = 1; break;
        case 'i': indent = optarg; break;
        case 'c': cols = strtol(optarg, NULL, 10); break;
        case 'd': input = fmemopen(optarg, strlen(optarg), "r"); break;
        case 'n': name = optarg; macro = 1; break;
        case '?':
        default:
            return 1;
        }
    }

    if (name) {
        count = fprintf(stdout, "#define %s \"", name);
    } else {
        fputc('"', stdout); count = 1;
    }
    
    open = 1;
    
    while ((chr = getc(input))!=EOF) {
        if (!open) {
            if (macro) {
                fputs(" \\", stdout);
            }
            fputc('\n', stdout);
            fputs(indent, stdout); count += strlen(indent);
            fputc('"', stdout); count++;
            open = 1;
        }
        char escape = escape_c_chr(chr);
        if (escape) {
            fputc('\\', stdout);
            fputc(escape, stdout);
            count+=2;
        } else {
            fputc(chr, stdout);
            count+=1;
        }
        if ((cols > 0 && count >= cols) || escape == 'n') {
            if (open) {
                fputc('"', stdout);
            }
            count = open = 0;
        }
    }
    if (open) {
        fputc('"', stdout);
    }
    fputc('\n', stdout);
    return 0;
}
