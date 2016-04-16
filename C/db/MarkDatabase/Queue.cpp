#include "Queue.h"

Queue::Queue(){
    ID = 0;
    userID = 0;
    receipe = NULL;
}

int Queue::getID(){
    return ID;
}

int Queue::getUserID(){
    return userID;
}

Receipe* Queue::getReceipe(){
    return receipe;
}

void Queue::setID(int id){
    ID = id;
}

void Queue::setUserID(int id){
    userID = id;
}

void Queue::setReceipe(Receipe* receipe){
    this->receipe = receipe;
}