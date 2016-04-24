#include "../Headers/Logger.h"

FILE* Logger::log = NULL;
bool Logger::status = false;
int Logger::level = 1;

Logger::Logger(String* location){
    this->location = location;
}

void Logger::initDebugger(){
    log = stdout;
}

void Logger::initDebugger(String* logFile){
    this->logFile = logFile;
}

void Logger::startDebugger(int level){
    this->level = level;
    status = true;
}

void Logger::stopDebugger(){
    status = false;
}

void Logger::debug(int level,char* format,...){
    if(this->level>=level && status){
        fprintf(log,"[%s]",location->getString());
        va_list arg;
        va_start(arg,format);
        vfprintf(log,format,arg);
        va_end(arg);
        fprintf(log,"\n");
    }
}

void Logger::error(char* format,...){
    
}