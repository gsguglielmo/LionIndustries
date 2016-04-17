#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include "../Headers/VirtualMachine.h"
#include "../db/MarkDatabase.h"
#include "../db/MarkDatabase/Need.h"
#include "../db/MarkDatabase/Receipe.h"
#include <unistd.h>

int main(void){
    /*
    Machine* dev = new Mark1("/dev/ttyACM0",9600);
    //Machine* dev = new VirtualMachine(6,6);
    printf("Init ok\n");
    usleep(5000000);
    dev->moveOn(0);
    usleep(4000000);
    dev->moveOn(2);
    usleep(1000000);
    dev->moveOn(1);
    usleep(2000000);
    dev->moveOn(2);
    usleep(1000000);
    dev->moveOn(1);
    usleep(2000000); 
    dev->moveOn(2);   
    */
    MarkDatabase* data = new MarkDatabase("localhost","inebriator","a53DGCY3qcE5vpyE");
    try{
        
        Queue* next = data->getNext();
        Receipe* tmp =next->getReceipe();
        printf("Queue id %d\nUser id => %d\nReceipe => %s\n",next->getID(),next->getUserID(),tmp->getName()->getString());
        Need* need = tmp->getNeed();
        Ingredient* ing;
        while(need != NULL){
            printf("Need = %d\n",need->getQTY());
            ing = need->getIngredient();
            need = tmp->getNeed();
            printf("ID=%d\nMID=%d\nName=%s\nPos=%d\nFQTY=%d\nRQTY=%d\n",ing->getID(),ing->getMachineID(),ing->getName()->getString(),ing->getPosition(),ing->getFullQTY(),ing->getRemainingQTY());
            
        }
        data->setNotCompleted();
    }catch(int a){
        printf("Returned %d\n",a);
    }
    
}
