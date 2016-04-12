#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include "../Headers/VirtualMachine.h"
#include <unistd.h>

int main(void){
    Machine* dev = new Mark1("/dev/ttyACM1",9600);
    //Machine* dev = new VirtualMachine(6,6);
    printf("Init ok\n");
    usleep(5000000);
    dev->moveOn(0);
    usleep(1000000);
    dev->moveOn(2);
    usleep(1000000);
    dev->moveOn(1);
    usleep(1000000);
    
    dev->moveOn(2);
}
