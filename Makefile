DESTDIR =
PREFIX  =/usr/local
CC      =gcc
CFLAGS  =-Wall -g
all:
clean:
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp escape.h $(DESTDIR)$(PREFIX)/include/str
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp tools/escape-c$(EXE) $(DESTDIR)$(PREFIX)/bin

all: tools/escape-c$(EXE)
tools/escape-c$(EXE): tools/escape-c.c escape.h
	$(CC) -o $@ tools/escape-c.c $(CFLAGS)


## -- license --
ifneq ($(PREFIX),)
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-escape
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-escape
endif
## -- license --
