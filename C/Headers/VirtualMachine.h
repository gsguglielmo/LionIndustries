#ifndef VirtualMachine_h
#define VirtualMachine_h

#include "Machine.h"
#include <stdio.h>
#include <stdlib.h>

class VirtualMachine: public Machine{
private:
    bool* pipeStatus;
    bool* pumpStatus;
    unsigned int pipeNumber;
    unsigned int pumpNumber;  
    unsigned int position;      
public:
    VirtualMachine(int pipe,int pump);
    void setPump(int pos,bool status);
    void setPipe(int pos,bool status);
    void moveOn(int pos);
    bool getPump(int pos);
    bool getPipe(int pos);
    int getPosition();
};

#endif