DESTDIR =
PREFIX  =/usr/local
CC      =gcc
CFLAGS  =-Wall -g
PROGRAMS=tools/escape-c$(EXE)
all: $(PROGRAMS)
clean:
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp escape.h $(DESTDIR)$(PREFIX)/include/str
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(PROGRAMS) $(DESTDIR)$(PREFIX)/bin
clean:
	rm -f $(PROGRAMS)
tools/escape-c$(EXE): tools/escape-c.c escape.h
	$(CC) -o $@ tools/escape-c.c $(CFLAGS)
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-escape
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-escape
## -- license --
