/*************************************************************************
 # File Name: log.cpp
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2023-08-23 16:02:48
 # Last modified: 2023-08-23 19:15:42
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "log.h"

//_levelToName = {
//    CRITICAL: 'CRITICAL',
//    ERROR: 'ERROR',
//    WARNING: 'WARNING',
//    INFO: 'INFO',
//    DEBUG: 'DEBUG',
//    NOTSET: 'NOTSET',
//}
//_nameToLevel = {
//    'CRITICAL': CRITICAL,
//    'FATAL': FATAL,
//    'ERROR': ERROR,
//    'WARN': WARNING,
//    'WARNING': WARNING,
//    'INFO': INFO,
//    'DEBUG': DEBUG,
//    'NOTSET': NOTSET,
//}

void Logger::setLevel(int level){
    this->m_level = level;
}

#define __LOG_CALL( LEVEL ) \
    va_list args; \
    va_start(args, msg); \
    if (this->isEnabledFor(LEVEL) == 0){ \
        this->_log( LEVEL , msg, args ); \
    } \
    va_end(args)

void Logger::debug(const char *msg, ...){
    __LOG_CALL( DEBUG );
}

void Logger::info(const char *msg, ...){
    __LOG_CALL( INFO );
}

void Logger::warning(const char *msg, ...){
    __LOG_CALL( WARNING );
}

void Logger::error(const char *msg, ...){
    __LOG_CALL( ERROR );
}

void Logger::fatal(const char *msg, ...){
    __LOG_CALL( FATAL );
}

void Logger::_log( int level, const char *msg,  va_list arg_ptr ){
    vprintf( msg, arg_ptr);
}

void Logger::handle( const record & re ){
}

void Logger::addHandler(){
}

void Logger::removeHandler(){}

