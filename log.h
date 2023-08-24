/*************************************************************************
 # File Name: log.h
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2023-08-23 16:03:01
 # Last modified: 2023-08-23 19:44:15
 ************************************************************************/

#ifndef __MY_LOG__HEADER_H_
#define __MY_LOG__HEADER_H_
#include <stdlib.h>
#include <stdio.h>

#define CRITICAL 50
#define FATAL CRITICAL
#define ERROR 40
#define WARNING 30
#define WARN WARNING
#define INFO 20
#define DEBUG 10
#define NOTSET 0

struct record{
};

class Logger{
public:
    Logger():m_level( NOTSET ){}
public:
    void setLevel( int level);
    void debug(const char *msg, ...);
    void info(const char *msg, ...);
    void warning(const char *msg, ...);
    void error(const char *msg, ...);
    void fatal(const char *msg, ...);
    void _log( int level, const char *msg, va_list );
private:
    int isEnabledFor( int level ){
        return 0;
    }
    void handle( const record & record );
    void removeHandler();
    void addHandler();
private:
    int m_level;
};

#endif  //__MY_LOG__HEADER_H_

