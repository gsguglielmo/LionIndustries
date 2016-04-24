#include "../Headers/Logger.h"

String* Logger::logFile = NULL;
bool Logger::status = false;
int Logger::level = 1;

Logger::Logger(String* location){
    this->location = location;
}

void Logger::initDebugger(){
    logFile = NULL;
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
        FILE* log;
        if(logFile == NULL){
            log = stdout;
        }else{
            log = fopen(logFile->getString(),"a");
            if(log == NULL){
                throw 0x44;
            }
        }
        fprintf(log,"[INFO][%d][%s]",level,location->getString());
        va_list arg;
        va_start(arg,format);
        vfprintf(log,format,arg);
        va_end(arg);
        fprintf(log,"\n");
        if(logFile != NULL){
            fclose(log);
        }
    }
    
}

void Logger::error(char* format,...){
    
    if(status){
        FILE* log;
        
        if(logFile == NULL){
            log = stdout;
        }else{
            log = fopen(logFile->getString(),"a");
        }
        fprintf(log,"[ERROR][%s]",location->getString());
        va_list arg;
        va_start(arg,format);
        vfprintf(log,format,arg);
        va_end(arg);
        fprintf(log,"\n");
        if(logFile != NULL){
            fclose(log);
        }
        
    }
    
}