DESTDIR =
PREFIX  =/usr/local
all:
clean:
install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp escape.h $(DESTDIR)$(PREFIX)/include/str

## -- license --
ifneq ($(PREFIX),)
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-escape
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-escape
endif
## -- license --
