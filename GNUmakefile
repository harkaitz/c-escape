PROJECT =c-escape
VERSION =1.0.0
DESTDIR =
PREFIX  =/usr/local
CC      =gcc
CFLAGS  =-Wall -g
PROGRAMS=tools/escape-c$(EXE)
##
all: $(PROGRAMS)
install:
clean:
##
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp escape.h $(DESTDIR)$(PREFIX)/include/str
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(PROGRAMS) $(DESTDIR)$(PREFIX)/bin
clean:
	rm -f $(PROGRAMS)
tools/escape-c$(EXE): tools/escape-c.c escape.h
	$(CC) -o $@ tools/escape-c.c $(CFLAGS)
## -- BLOCK:license --
install: install-license
install-license: 
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
	cp LICENSE README.md $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
update: update-license
update-license:
	ssnip README.md
## -- BLOCK:license --
## -- BLOCK:man --
update: update-man
update-man:
	make-h-man update
install: install-man
install-man:
## -- BLOCK:man --
