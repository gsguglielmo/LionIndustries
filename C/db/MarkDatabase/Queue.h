#ifndef Queue_h
#define Queue_h

#include "../String.h"

class Queue{
public:
    Queue();
    int getID();
    int getUserID();
    String* getReceipeName();
    
    void setID(int id);
    void setUserID(int id);
    void setReceipeName(String* receipe);
private: 
    int ID;
    int userID;
    String* nomeRicetta;
};


#endif