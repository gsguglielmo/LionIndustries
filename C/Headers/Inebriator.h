#ifndef Inebriator_h
#define Inebriator_h

#include "Arduino.h"
#include <stdlib.h>

class Inebriator : private Arduino{

private:
    bool* pipeStatus;
    bool* pumpStatus;
    unsigned int pipeNumber;
    unsigned int pumpNumber;
    int a;
public:
    Inebriator(const char* serialPort,int baud);
    Inebriator(const char* serialPort,int baud,int pipe,int pump);
    void setPump(int pos,bool status);
    void setPipe(int pos,bool status);
    bool getPump(int pos);
    bool getPipe(int pos);
};

#endif
