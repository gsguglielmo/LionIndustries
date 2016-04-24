#include "../Headers/Mark1.h"
#include "../Headers/Machine.h"
#include "../Headers/VirtualMachine.h"
#include "../db/MarkDatabase.h"
#include "../db/MarkDatabase/Need.h"
#include "../db/MarkDatabase/Receipe.h"
#include "../Headers/Config.h"
#include "../Headers/Logger.h"
#include <unistd.h>

int wait(int loadTime,int dropTime,int qty);
bool isRunning();

int main(int argc,char* argv[]){
    Config* conf = new Config(new String("/etc/mark/config.conf"));
    Logger* l = new Logger(new String("Main"));
    l->initDebugger();
    l->startDebugger(5);
    bool virtualmachine = false;
    if(argc > 1){
        int i;
        for(i=1;i<argc;i++){
            if(strcmp(argv[i],"--config")==0){
                l->debug(1,"Config mode");
                if(isRunning()){
                    printf("Mark process already running\n");
                    return 1;
                }
                conf->change();
                return 0;
            }
            if(strcmp(argv[i],"--start")==0){
                l->initDebugger(new String("/etc/mark/mark.log"));
                l->debug(1,"Deamon mode started");
            }
            if(strcmp(argv[i],"--stop")==0){
                system("/etc/mark/kill.sh");
                return 0;
            }
            if(strcmp(argv[i],"--demo")==0){
                l->debug(1,"Demo mode started");
                virtualmachine = true;
            }
            if(strcmp(argv[i],"--help")==0){
                printf("[--config]    Configure machine\n[--start]     Starts the program in deamon mode\n[--demo]      Simulates Arduino\n[--debug n]   Sets the debugging level to n (Default 1)\n");
                return 0;
            }
            if(strcmp(argv[i],"--debug")==0){
                int level = atoi(argv[i+1]);
                l->stopDebugger();
                l->startDebugger(level);
                i++;
                virtualmachine = true;
            }
        }
    }
    if(isRunning()){
        printf("Mark process already running\n");
        return 1;
    }
    l->debug(1,"Initializing");
    l->debug(2,"Connectiong to Arduino");
    l->debug(3,"Device=%s",conf->getDevice()->getString());
    l->debug(3,"Baud=9600");
    Machine* dev;
    if(virtualmachine){
        dev = new VirtualMachine(6,6);
    }else{
        dev = new Mark1(conf->getDevice()->getString(),9600);
    }
    l->debug(2,"Connection to Arduino successfull");
    l->debug(2,"Connectiong to Database");
    l->debug(3,"Address=%s",conf->getDatabaseAddress()->getString());
    l->debug(3,"Username=%s",conf->getDatabaseUsername()->getString());
    l->debug(3,"Password=%s",conf->getDatabasePassword()->getString());
    l->debug(3,"Database=%s",conf->getDatabaseName()->getString());
    MarkDatabase* data = new MarkDatabase(conf->getDatabaseAddress()->getString(),conf->getDatabaseUsername()->getString(),conf->getDatabasePassword()->getString(),conf->getDatabaseName()->getString());
    l->debug(2,"Connection to database successfull");
    bool stat = true;
    dev->moveOn(0);
    l->debug(1,"Initialized");
    while(true){
        try{
            Queue* next = data->getNext();
            Receipe* tmp =next->getReceipe();
            l->debug(1,"Found element");
            l->debug(2,"Queue id %d",next->getID());
            l->debug(2,"User id %d",next->getUserID());
            l->debug(2,"Receipe = %s",tmp->getName()->getString());
            Need* need = tmp->getNeed();
            Ingredient* ing;
            while(need != NULL){
                ing = need->getIngredient();
                l->debug(3,"Ingredient=%s",ing->getName()->getString());
                l->debug(3,"Qty needed=%d",need->getQTY());
                l->debug(3,"Load time=%d",ing->getLoadTime());
                l->debug(3,"Drop time=%d",ing->getDropTime());
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
            }
            data->setCompleted();
            dev->moveOn(0);
            stat = true;
        }catch(int a){
            if(a==1 && stat){
                l->debug(1,"Waiting element");
                stat = false;
            }else if(a!=1){
                l->error("Returned value %d",a);
            }
        }
        usleep(500000);
    }
}

bool isRunning(){
    return false;
}

int wait(int loadTime,int dropTime,int qty){
    int tmp = 1000*loadTime;
    tmp += (1000*dropTime)*(qty/10);
    return tmp;
}
