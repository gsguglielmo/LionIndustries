#include "Ingredient.h"

Ingredient::Ingredient(){
    ID = 0;
    machineID = 0;
    name = new String("");
    position = 0;
    fullQTY = 0;
    remainingQTY = 0;
}

void Ingredient::setID(int ID){
    this->ID = ID;
}

void Ingredient::setMachineID(int ID){
    this->machineID = ID;
}

void Ingredient::setName(String* name){
    this->name = name;
}

void Ingredient::setPosition(int position){
    this->position = position;
}

void Ingredient::setFullQTY(int qty){
    this->fullQTY = qty;
}

void Ingredient::setRemainingQTY(int qty){
    this->remainingQTY = qty;
}

int Ingredient::getID(){
    return ID;
}

int Ingredient::getMachineID(){
    return machineID;
}

String* Ingredient::getName(){
    return name;
}

int Ingredient::getPosition(){
    return position;
}

int Ingredient::getFullQTY(){
    return fullQTY;
}

int Ingredient::getRemainingQTY(){
    return remainingQTY;
}