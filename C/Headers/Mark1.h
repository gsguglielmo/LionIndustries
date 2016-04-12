#ifndef Mark1_h
#define Mark1_h

#include "Machine.h"
#include "Arduino.h"

#include <stdlib.h>

class Mark1 : public Arduino,public Machine{

private:
    bool* pipeStatus;
    bool* pumpStatus;
    unsigned int pipeNumber;
    unsigned int pumpNumber;
    void left();
    void right();
    void stop();
public:
    Mark1(const char* serialPort,int baud);
    Mark1(const char* serialPort,int baud,int pipe,int pump);
    void setPump(int pos,bool status);
    void setPipe(int pos,bool status);
    void moveOn(int pos);
    bool getPump(int pos);
    bool getPipe(int pos);
    int getPosition();
};

#endif
