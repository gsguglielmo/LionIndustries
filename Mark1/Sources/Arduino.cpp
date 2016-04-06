#include "../Headers/Arduino.h"

Arduino::Arduino(const char* serialPort,int baud){
    this->feed = serialport_init(serialPort,baud);
    if(this->feed == -1){
        throw 0x01;
    }
    usleep(2000000);
}

bool Arduino::isConnected(){
    return !(this->feed == -1);
}

void Arduino::flush(){
    if(!isConnected()){
        throw 0x04;
    }
    serialport_flush(this->feed);
}

void Arduino::sendByte(char byte){
    if(!isConnected()){
        throw 0x04;
    }
    if(serialport_writebyte(this->feed,byte)==-1){
        throw 0x02;
    }
}

char Arduino::getByte(){
    if(!isConnected()){
        throw 0x04;
    }
    char rez[1];
    if(serialport_read_until(this->feed,rez,'\n',1,-1)!=0){
        throw 0x03;
    }
    return rez[0];
}

void Arduino::close(){
    if(!isConnected()){
        throw 0x04;
    }
    serialport_close(this->feed);
}

Arduino::~Arduino(){
    close();
}