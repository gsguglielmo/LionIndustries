#ifndef Config_h
#define Config_h

#include "../db/String.h"
#include <stdio.h>

class Config{
public:
    Config(String* path);
    void update();
    void change();
    
    String* getPath();
    String* getDatabaseAddress();
    String* getDatabaseUsername();
    String* getDatabasePassword();
    String* getDatabaseName();
    String* getDevice();
    int getMachineID();
    
private:
    void save();
    void updateParameter(String* name,String* value);
    String* configPath;
    String* databaseAddress;
    String* databaseUsername;
    String* databasePassword;
    String* databaseName;
    String* arduinoDevice;
    int machineID;
};

#endif