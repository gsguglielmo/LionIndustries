#ifndef Logger_h
#define Logger_h

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../db/String.h"

class Logger{
public:
    Logger(String* location);
    void initDebugger();
    void initDebugger(String* logFile);
    void startDebugger(int level);
    void stopDebugger();
    void debug(int level,char* format,...);
    void error(char* format,...);
private:
    String* location;
    static String* logFile;
    static FILE* log;
    static bool status;
    static int level;
};

#endif