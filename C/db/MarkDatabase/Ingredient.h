#ifndef Ingredient_h
#define Ingredient_h

#include "../String.h"

class Ingredient{
public:
    Ingredient();
    void setID(int ID);
    void setMachineID(int ID);
    void setName(String* name);
    void setPosition(int position);
    void setFullQTY(int qty);
    void setRemainingQTY(int qty);
    
    int getID();
    int getMachineID();
    String* getName();
    int getPosition();
    int getFullQTY();
    int getRemainingQTY();
private:
    int ID;
    int machineID;
    String* name;
    int position;
    int fullQTY;
    int remainingQTY;
};

#endif