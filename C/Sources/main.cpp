#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include "../Headers/VirtualMachine.h"
#include <unistd.h>

int main(void){
    //Machine* dev = new Mark1("/dev/ttyACM0",9600);
    Machine* dev = new VirtualMachine(6,6);
    printf("Init ok\n");
    dev->setPump(2,true);
    usleep(35000000);
    dev->setPump(2,false);
}
