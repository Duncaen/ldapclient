#ifndef _COMPAT_H_
#define _COMPAT_H_

#include <sys/types.h>
#include <stdint.h>

#ifndef __dead
# define __dead
#endif

#ifndef DEF_WEAK
# define DEF_WEAK(x)
#endif

#ifndef _PATH_TTY
# define _PATH_TTY "/dev/tty"
#endif

#ifndef TCSASOFT
# define TCSASOFT 0
#endif

/* stdlib.h */
#ifndef HAVE_REALLOCARRAY
void * reallocarray(void *, size_t, size_t);
#endif /* HAVE_REALLOCARRAY */
#ifndef HAVE_STRTONUM
long long strtonum(const char *, long long, long long, const char **);
#endif /* !HAVE_STRTONUM */

/* string.h */
#ifndef HAVE_EXPLICIT_BZERO
void explicit_bzero(void *, size_t);
#endif
#ifndef HAVE_STRLCPY
size_t strlcpy(char *, const char *, size_t);
#endif /* !HAVE_STRLCPY */

/* unistd.h */
#ifndef HAVE_PLEDGE
int pledge(const char *, const char *);
#endif /* !HAVE_PLEDGE */


#endif
