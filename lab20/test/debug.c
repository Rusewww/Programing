#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "debug.h"
#define __WRAP_FUNCTION__
#ifdef DEBUG

int al_debug(const char *time, const char *file, const char *func, int line, const char *format, ...)
{
    int done=0;
    va_list arg;
    va_start(arg, format);
    done = fprintf(stdout, "%s :%s:%s:%d: ", time, file, func, line);
    done += vfprintf(stdout, format, arg);
    va_end(arg);

    return done;
}

#endif
