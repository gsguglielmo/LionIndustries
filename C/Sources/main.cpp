#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include "../Headers/VirtualMachine.h"
#include "../db/MarkDatabase.h"
#include "../db/MarkDatabase/Need.h"
#include "../db/MarkDatabase/Receipe.h"
#include "../Headers/Config.h"
#include <unistd.h>

int wait(int loadTime,int dropTime,int qty);

int main(int argc,char* argv[]){
    Config* conf = new Config(new String("config.conf"));
    if(argc == 2){
        if(strcmp(argv[1],"--config")==0){
            conf->change();
            return 0;
        }
    }
    //  Machine* dev = new Mark1(conf->getDevice()->getString(),9600);
    Machine* dev = new VirtualMachine(6,6);
    MarkDatabase* data = new MarkDatabase(conf->getDatabaseAddress()->getString(),conf->getDatabaseUsername()->getString(),conf->getDatabasePassword()->getString(),conf->getDatabaseName()->getString());
    while(true){
        try{
            system("clear");
            dev->moveOn(0);
            Queue* next = data->getNext();
            Receipe* tmp =next->getReceipe();
            printf("Queue id %d\nUser id => %d\nReceipe => %s\n",next->getID(),next->getUserID(),tmp->getName()->getString());
            Need* need = tmp->getNeed();
            Ingredient* ing;
            while(need != NULL){
                ing = need->getIngredient();
                //printf("Need = %d\n",need->getQTY());
                //printf("Load=>%d\nDrop=>%d\n",ing->getLoadTime(),ing->getDropTime());
                if(ing->getPosition()>6){
                    dev->moveOn(0);
                    dev->setPump(ing->getPosition()-7,true);
                    usleep(wait(ing->getLoadTime(),ing->getDropTime(),need->getQTY()));
                    dev->setPump(ing->getPosition()-7,false);
                }else{
                    dev->moveOn(ing->getPosition());
                    dev->setPipe(ing->getPosition(),true);
                    usleep(wait(ing->getLoadTime(),ing->getDropTime(),need->getQTY()));
                    dev->setPipe(ing->getPosition(),false);
                }
                data->updateQty(need);
                need = tmp->getNeed();
                //printf("ID=%d\nMID=%d\nName=%s\nPos=%d\nFQTY=%d\nRQTY=%d\n",ing->getID(),ing->getMachineID(),ing->getName()->getString(),ing->getPosition(),ing->getFullQTY(),ing->getRemainingQTY());
            }
            data->setCompleted();
        }catch(int a){
            if(a==1){
                printf("Queue empty\n");
            }else{
                printf("Returned %d\n",a);
            }
        }
        usleep(500000);
    }
}

int wait(int loadTime,int dropTime,int qty){
    int tmp = 1000*loadTime;
    tmp += (1000*dropTime)*(qty/10);
    return tmp;
}
