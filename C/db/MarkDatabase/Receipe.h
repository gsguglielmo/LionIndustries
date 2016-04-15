#ifndef Receipe_h
#define Receipe_h

#include "../String.h"
#include "Need.h"

class Receipe{
public:
    Receipe();
    Need* getNeed();
    //  int getNeedsNum();
    int getID();
    String* getName();
    
    void addNeed(Need* need);
    void setID(int id);
    void setName(String* name);
private:
    int ID;
    String* receipeName;
    Need* glava;
    Need* rep;
};

#endif