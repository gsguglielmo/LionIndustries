#include "Receipe.h"

Receipe::Receipe(){
    glava = NULL;
    rep = NULL;
    ID = 0;
    receipeName = NULL;
}

Need* Receipe::getNeed(){
    if (glava == NULL){
        return NULL;
    }
    Need* tmp = glava;
    glava = tmp->getNext();
    tmp->setNext(NULL);
    return tmp;
}

int Receipe::getID(){
    return ID;
}

String* Receipe::getName(){
    return receipeName; 
}

void Receipe::addNeed(Need* need){
    if(glava == NULL){
        glava = need;
        rep = need;
        return;
    }
    rep->setNext(need);
    rep = need;
}

void Receipe::setID(int id){
    ID = id;
}

void Receipe::setName(String* name){
    receipeName = name;
}