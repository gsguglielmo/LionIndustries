#include "../Headers/VirtualMachine.h"

VirtualMachine::VirtualMachine(int pipe,int pump){
    pipeNumber = pipe;
    pumpNumber = pump;
    pipeStatus = (bool *)malloc(pipe*sizeof(bool));
    pumpStatus = (bool *)malloc(pump*sizeof(bool));
    log = new Logger(new String("VirtualMachine"));
}

void VirtualMachine::setPump(int pos,bool status){
    if(pos>=pumpNumber){
        throw 0x01;
    }
    pumpStatus[pos] = status;
    log->debug(3,"Setting pump %d to %d",pos,status);
}

void VirtualMachine::setPipe(int pos,bool status){
    if(pos>=pipeNumber){
        throw 0x02;
    }
    pipeStatus[pos] = status;
    log->debug(3,"Setting pipe %d to %d",pos,status);
}

void VirtualMachine::moveOn(int pos){
    position = pos;
    log->debug(3,"Moving to position %d",pos);
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