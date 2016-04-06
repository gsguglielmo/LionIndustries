#include "../Headers/Mark1.h"

Mark1::Mark1(const char* serialPort,int baud):Arduino(serialPort,baud){
    pipeNumber = 6;
    pumpNumber = 6;
    pipeStatus = (bool *)malloc(6*sizeof(bool));
    pumpStatus = (bool *)malloc(6*sizeof(bool));
}

Mark1::Mark1(const char* serialPort,int baud,int pipe,int pump):Arduino(serialPort,baud){
    pipeNumber = pipe;
    pumpNumber = pump;
    pipeStatus = (bool *)malloc(pipe*sizeof(bool));
    pumpStatus = (bool *)malloc(pump*sizeof(bool));
}

void Mark1::setPump(int pos,bool status){
    if(pos<0 || pos >= pumpNumber){
        throw "Mark1:setPump Wrong position";
    }
    pos += 8;
    sendByte(pos);
    if(status){
        sendByte(0x48);
    }else{
        sendByte(0x4c);
    }
    pumpStatus[pos-8] = status;
    flush();
}

void Mark1::setPipe(int pos,bool status){
    if(pos<0 || pos >= pipeNumber){
        throw "Mark1:setPipe Wrong position";
    }
    pos +=2;
    sendByte(pos);
    if(status){
        sendByte(0x48);
    }else{
        sendByte(0x4c);
    }
    pipeStatus[pos] = status;
    flush();
}

bool Mark1::getPump(int pos){
    return pumpStatus[pos];
}

bool Mark1::getPipe(int pos){
    return pipeStatus[pos];
}

void Mark1::moveOn(int pos){
    printf("Moving on %d\n",pos);
}

int Mark1::getPosition(){
    return 1;
}