//
// Created by Rusewww on 4/17/21.
//

#ifndef PROGRAMING_DEBUG_H
#define PROGRAMING_DEBUG_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#ifdef DEBUG

int al_debug(const char *time, const char *file, const char *func, int line, const char * format, ...);
#define debug(...) al_debug(__TIME__, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
#else /* IF DEBUG NOT DEFINED*/
#define debug(...) /* DO NOT PRINT ANYTHING IF DEBUG IS NOT PRESENT */
#endif /* END OF DEBUG */


#endif //PROGRAMING_DEBUG_H
