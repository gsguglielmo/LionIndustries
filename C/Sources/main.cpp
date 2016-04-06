#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include <unistd.h>

int main(void){
    Mark1* dev = new Mark1("/dev/ttyACM0",9600);
    printf("Init ok\n");
    dev->setPump(2,true);
    usleep(35000000);
    dev->setPump(2,false);
    /*
    for(int i=0;i<6;i++){
        printf("Pump %d\n",i);
        dev->setPipe(i,true);
        usleep(2000000);
        dev->setPipe(i,false);
    }*/
    
    
    /*
    Arduino* dev = new Arduino("/dev/ttyACM1",9600);
    printf("Opening\n");
    dev->sendByte(0x0d);
    dev->sendByte(0x48);
    usleep(5000000);
    printf("Closing\n");
    dev->sendByte(0x0d);
    dev->sendByte(0x4c);
    dev->close();
    */
}
