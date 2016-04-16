#ifndef Queue_h
#define Queue_h

#include "../String.h"
#include "Receipe.h"

class Queue{
public:
    Queue();
    int getID();
    int getUserID();
    Receipe* getReceipe();
    
    void setID(int id);
    void setUserID(int id);
    void setReceipe(Receipe* receipe);
private: 
    int ID;
    int userID;
    Receipe* receipe;
};


#endif