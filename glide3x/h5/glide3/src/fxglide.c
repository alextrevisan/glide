/* standard */
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* 3dfx */
#include <3dfx.h>
#include <glidesys.h>
#include <gdebug.h>
#include <h3.h>
#include <cpuid.h>
#include <fxglide.h>
extern __inline unsigned long getThreadValueFast (void)
{
 unsigned long t;
 __asm __volatile (" \
       mov %%fs:(%0), %%eax; \
       add %1, %%eax; \
       mov (%%eax), %%eax; \
 ":"=a"(t):"i"(WNT_TEB_PTR), "g"(_GlideRoot.tlsOffset));
 return t;
}