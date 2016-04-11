#include "../Headers/VirtualMachine.h"

VirtualMachine::VirtualMachine(int pipe,int pump){
    pipeNumber = pipe;
    pumpNumber = pump;
    pipeStatus = (bool *)malloc(pipe*sizeof(bool));
    pumpStatus = (bool *)malloc(pump*sizeof(bool));
}

void VirtualMachine::setPump(int pos,bool status){
    if(pos>=pumpNumber){
        throw 0x01;
    }
    pumpStatus[pos] = status;
    printf("Setting pump %d to %d\n",pos,status);
}

void VirtualMachine::setPipe(int pos,bool status){
    if(pos>=pipeNumber){
        throw 0x02;
    }
    pipeStatus[pos] = status;
    printf("Setting pipe %d to %d\n",pos,status);
}

void VirtualMachine::moveOn(int pos){
    position = pos;
    printf("Moving to position %d\n",pos);
}

bool VirtualMachine::getPump(int pos){
    if(pos>=pumpNumber){
        throw 0x01;
    }
    return pumpStatus[pos];
}

bool VirtualMachine::getPipe(int pos){
    if(pos>=pipeNumber){
        throw 0x02;
    }
    return pipeStatus[pos];
}

int VirtualMachine::getPosition(){
    return position;
}