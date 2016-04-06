#include "../Headers/Inebriator.h"

Inebriator::Inebriator(const char* serialPort,int baud):Arduino(serialPort,baud){
    pipeNumber = 6;
    pumpNumber = 6;
    pipeStatus = (bool *)malloc(6*sizeof(bool));
    pumpStatus = (bool *)malloc(6*sizeof(bool));
}

Inebriator::Inebriator(const char* serialPort,int baud,int pipe,int pump):Arduino(serialPort,baud){
    pipeNumber = pipe;
    pumpNumber = pump;
    pipeStatus = (bool *)malloc(pipe*sizeof(bool));
    pumpStatus = (bool *)malloc(pump*sizeof(bool));
}

void Inebriator::setPump(int pos,bool status){
    if(pos<0 || pos >= pumpNumber){
        throw "Inebriator:setPump Wrong position";
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

void Inebriator::setPipe(int pos,bool status){
    if(pos<0 || pos >= pipeNumber){
        throw "Inebriator:setPipe Wrong position";
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

bool Inebriator::getPump(int pos){
    return pumpStatus[pos];
}

bool Inebriator::getPipe(int pos){
    return pipeStatus[pos];
}