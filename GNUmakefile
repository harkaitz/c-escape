PROJECT =c-escape
VERSION =1.0.0
DESTDIR =
PREFIX  =/usr/local
CC      =gcc -pedantic-errors -std=c99 -Wall
PROGRAMS=examples/escape-c$(EXE)
##
all: $(PROGRAMS)
install:
clean:
##
install:
	@mkdir -p $(DESTDIR)$(PREFIX)/include/str
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp escape.h $(DESTDIR)$(PREFIX)/include/str
	cp escape2.h $(DESTDIR)$(PREFIX)/include/str
	cp $(PROGRAMS) $(DESTDIR)$(PREFIX)/bin
clean:
	rm -f $(PROGRAMS)
examples/escape-c$(EXE): examples/escape-c.c escape.h
	$(CC) -o $@ examples/escape-c.c $(CFLAGS)
## -- BLOCK:license --
install: install-license
install-license: 
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
	cp LICENSE  $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
## -- BLOCK:license --
