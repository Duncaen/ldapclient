PROG=		ldap
SRCS=		ldapclient.c aldap.c ber.c log.c
SRCS+=		compat/strlcpy.c compat/pledge.c compat/readpassphrase.c compat/strtonum.c compat/vis.c
LDADD+=		-levent -ltls -lssl -lcrypto -lutil -lresolv
DPADD+=		${LIBEVENT} ${LIBTLS} ${LIBSSL} ${LIBCRYPTO} ${LIBUTIL}

CFLAGS+=	-Wall
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith
CFLAGS+=	-Wsign-compare -Wcast-qual

CFLAGS+=	-D_GNU_SOURCE -include compat/compat.h -isystem compat

PREFIX?=	/usr/local

all: $(PROG)

clean:
	rm -f $(PROG) $(SRCS:.c=.o)

install: $(PROG)
	install -d $(DESTDIR)$(PREFIX)/bin/ $(DESTDIR)$(PREFIX)/share/man/man1/
	install -m0755 $(PROG) $(DESTDIR)$(PREFIX)/bin/
	install -m0644 $(PROG).1 $(DESTDIR)$(PREFIX)/share/man/man1/

$(PROG): $(SRCS:.c=.o)
	$(CC) $(CFLAGS) -o $@ $^ $(LDADD)
