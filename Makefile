DESTDIR =
PREFIX  =/usr/local
CC      =gcc
CFLAGS  =-Wall -g
PROGRAMS=tools/escape-c$(EXE)
all:
clean:
install: all
	@echo "I include/str/ escape.h"
	@mkdir -p $(DESTDIR)$(PREFIX)/include/str
	@cp escape.h $(DESTDIR)$(PREFIX)/include/str
	@echo "I bin/escape-c$(EXE)"
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp $(PROGRAMS) $(DESTDIR)$(PREFIX)/bin

all: tools/escape-c$(EXE)
tools/escape-c$(EXE): tools/escape-c.c escape.h
	@echo "B tools/escape-c$(EXE) $<"
	@$(CC) -o $@ tools/escape-c.c $(CFLAGS)
clean:
	@echo "D $(PROGRAMS)"
	@rm -f $(PROGRAMS)

## -- license --
install: install-license
install-license: LICENSE
	@echo 'I share/doc/c-escape/LICENSE'
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-escape
	@cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-escape
## -- license --
