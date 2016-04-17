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