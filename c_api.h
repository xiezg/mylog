/*************************************************************************
 # File Name: log_export.h
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2023-08-23 17:31:22
 # Last modified: 2023-08-24 15:38:09
 ************************************************************************/

#ifndef __LOG__EXPORT_HEADER__
#define __LOG__EXPORT_HEADER__

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void mysetLevel( int level);
void mydebug(const char*msg, ...);
void myinfo(const char *msg, ...);
void mywarning(const char *msg, ...);
void myerror(const char *msg, ...);
void myfatal(const char *msg, ...);

#ifdef __cplusplus
}
#endif

#endif // __LOG__EXPORT_HEADER__

