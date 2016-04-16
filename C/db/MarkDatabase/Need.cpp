#include "Need.h"

Need::Need(){
    ingredient = NULL;
    qty = 0;
    next = NULL;
}

Ingredient* Need::getIngredient(){
    return ingredient;
}

float Need::getQTY(){
    return qty;
}

Need* Need::getNext(){
    return next;
}

void Need::setIngredient(Ingredient* ingredient){
    this->ingredient = ingredient;
}

void Need::setQTY(float qty){
    this->qty = qty;
}

void Need::setNext(Need* next){
    this->next = next;
}