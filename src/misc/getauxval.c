#include <sys/auxv.h>
#include <errno.h>
#include "libc.h"

unsigned long getauxval(unsigned long item)
{
	size_t *auxv = libc.auxv;
	for (; *auxv; auxv+=2)
		if (*auxv==item) return auxv[1];
	errno = ENOENT;
	return 0;
}
