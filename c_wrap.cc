/*************************************************************************
 # File Name: c_wrap.c
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2023-08-23 18:44:27
 # Last modified: 2023-08-23 19:15:43
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "./c_api.h"
#include "./log.h"

Logger defaultLogger;

#define __LOG_CALL( LEVEL ) \
    va_list args; \
    va_start(args, msg); \
    defaultLogger._log( LEVEL , msg, args ); \
    va_end(args)

void mysetLevel( int level){
    defaultLogger.setLevel( level );
}

void mydebug(const char *msg, ...){
    __LOG_CALL( DEBUG );
}

void myinfo(const char *msg, ...){
    __LOG_CALL( INFO );
}

void mywarning(const char *msg, ...){
    __LOG_CALL( WARNING );
}

void myerror(const char *msg, ...){
    __LOG_CALL( ERROR );
}

void myfatal(const char *msg, ...){
    __LOG_CALL( FATAL );
}


