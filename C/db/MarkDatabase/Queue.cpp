#include "Queue.h"

Queue::Queue(){
    ID = 0;
    userID = 0;
    nomeRicetta = NULL;
}

int Queue::getID(){
    return ID;
}

int Queue::getUserID(){
    return userID;
}

String* Queue::getReceipeName(){
    return nomeRicetta;
}

void Queue::setID(int id){
    ID = id;
}

void Queue::setUserID(int id){
    userID = id;
}

void Queue::setReceipeName(String* receipe){
    nomeRicetta = receipe;
}