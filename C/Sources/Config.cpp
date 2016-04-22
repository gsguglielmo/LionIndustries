#include "../Headers/Config.h"

Config::Config(String* path){
    configPath = path;
    databaseAddress = new String("localhost");
    databaseUsername = new String("inebriator");
    databasePassword = new String("password");
    databaseName = new String("mark1");
    arduinoDevice = new String("/dev/ttyACM0");
    machineID = 0;
    update();
}

void Config::change(){
    buildGUI();
    changePosition();
    /*char test[100];
    mvscanw(3,12,"%s",test);
    attroff(A_STANDOUT);
    int c = getch()*/
    endwin();
}

void Config::save(){
    FILE* f = fopen(configPath->getString(),"w");
    char buff[255];
    if(f == NULL){
        throw 0x20;
    }
    String* tmp = new String("host=");
    tmp->concatenate(databaseAddress);
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    
    tmp = new String("username=");
    tmp->concatenate(databaseUsername);
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    
    tmp = new String("password=");
    tmp->concatenate(databasePassword);
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    
    tmp = new String("database=");
    tmp->concatenate(databaseName);
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    
    tmp = new String("arduino=");
    tmp->concatenate(arduinoDevice);
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    
    char t[100];
    sprintf(t,"%d",machineID);
    tmp = new String("id=");
    tmp->concatenate(new String(t));
    tmp->concatenate(new String("\n"));
    fputs(tmp->getString(),f);
    fclose(f);
}

int Config::nextPos(int pos){
    pos +=2;
    if(pos==11){
        pos = 14;
    }else if(pos==16){
        pos = 19;
    }else if(pos>19){
        pos = 3;
    }
    return pos;
}

int Config::previousPos(int pos){
    pos -=2;
    if(pos<3){
        pos = 19;
    }else if(pos==12){
        pos = 9;
    }else if(pos==17){
        pos = 14;
    }
    return pos;
}

void Config::changePosition(){
    int pos=3;
    move(pos,12+posToString(pos)->getLength());
    while(true){
        int in = getch();
        switch(in){
            case KEY_DOWN:
                pos = nextPos(pos);
                move(pos,12+posToString(pos)->getLength());
            break;
            case 13:
                pos = nextPos(pos);
                move(pos,12+posToString(pos)->getLength());
            break;
            case KEY_UP:
                pos = previousPos(pos);
                move(pos,12+posToString(pos)->getLength());
            break;
            case 127:
                if(pos!=19){
                    posToString(pos)->removeChar();
                    move(pos,12+posToString(pos)->getLength());
                    addstr(" ");
                    move(pos,12+posToString(pos)->getLength());
                }else{
                    String* t = posToString(pos);
                    t->removeChar();
                    move(pos,12+t->getLength());
                    addstr(" ");
                    move(pos,12+t->getLength());
                    
                    machineID = atoi(t->getString());
                }
            break;
            case KEY_F(2):
                return;
            case KEY_F(3):
                save();
                break;
            case KEY_F(4):
                save();
                return;
            default:
                if(pos!=19){
                    addch(in);
                    posToString(pos)->addChar(in);
                    move(pos,12+posToString(pos)->getLength());
                }else{
                    if(in>='0' && in<='9'){
                        String* t = posToString(pos);
                        if(t->getLength() < 7){
                            machineID = atoi(t->getString());
                            if(machineID==0){
                                t->removeChar();
                                move(pos,12+t->getLength());
                                addch(in);
                                t->addChar(in);
                                move(pos,12+t->getLength());
                                machineID = atoi(t->getString());
                            }else{
                                addch(in);
                                t->addChar(in);
                                move(pos,12+t->getLength());
                                machineID = atoi(t->getString());
                            }
                            
                        }
                    }
                }
        }
    }
    
}

String* Config::posToString(int pos){
    switch(pos){
        case 3:
            return databaseAddress;
        case 5:
            return databaseUsername;
        case 7:
            return databasePassword;
        case 9:
            return databaseName;
        case 14:
            return arduinoDevice;
        case 19:
            char t[100];
            sprintf(t,"%d",machineID);
            return new String(t);
    }
}

void Config::buildGUI(){
    initscr();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    mvaddstr(1,1,"Database");
    mvaddstr(12,1,"Arduino");
    mvaddstr(17,1,"Machine");
    attrset(COLOR_PAIR(1));
    mvaddstr(3,2,"Address:");
    mvaddstr(5,2,"Username:");
    mvaddstr(7,2,"Password:");
    mvaddstr(9,2,"Name:");
    mvaddstr(14,2,"Device:");
    mvaddstr(19,2,"ID:");
    mvaddstr(22,0,"     [F2] Exit        [F3] Save      [F4] Save and Exit");
    attron(A_STANDOUT);
    mvaddstr(3,12,"                                                 ");//50 chars
    mvaddstr(5,12,"                                                 ");//50 chars
    mvaddstr(7,12,"                                                 ");//50 chars
    mvaddstr(9,12,"                                                 ");//50 chars
    mvaddstr(14,12,"                                                 ");//50 chars
    mvaddstr(19,12,"                                                 ");//50 chars
    mvaddstr(3,12,posToString(3)->getString());
    mvaddstr(5,12,posToString(5)->getString());
    mvaddstr(7,12,posToString(7)->getString());
    mvaddstr(9,12,posToString(9)->getString());
    mvaddstr(14,12,posToString(14)->getString());
    mvaddstr(19,12,posToString(19)->getString());
}

void Config::update(){
    FILE* f = fopen(configPath->getString(),"r");
    char buff[255];
    String* name;
    String* value;
    if(f == NULL){
        throw 0x20;
    }
    while( fgets(buff,255,f) != NULL){
        name = new String(strtok(buff,"="));
        value = new String(strtok(NULL,"\n"));
        updateParameter(name,value);
    }
    fclose(f);
}

void Config::updateParameter(String* name,String* value){
    
    if(name->compare(new String("host"))){
        databaseAddress = value;
        return;
    }
    if(name->compare(new String("username"))){
        databaseUsername = value;
        return;
    }
    if(name->compare(new String("password"))){
        databasePassword = value;
        return;
    }
    if(name->compare(new String("database"))){
        databaseName = value;
        return;
    }
    if(name->compare(new String("arduino"))){
        arduinoDevice = value;
        return;
    }
    if(name->compare(new String("id"))){
        machineID = atoi(value->getString());
        return;
    }
}

String* Config::getPath(){
    return configPath;
}

String* Config::getDatabaseAddress(){
    return databaseAddress;
}

String* Config::getDatabaseUsername(){
    return databaseUsername;
}

String* Config::getDatabasePassword(){
    return databasePassword;
}

String* Config::getDatabaseName(){
    return databaseName;
}

String* Config::getDevice(){
    return arduinoDevice;
}

int Config::getMachineID(){
    return machineID;
}