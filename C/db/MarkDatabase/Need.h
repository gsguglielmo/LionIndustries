#ifndef Needs_h
#define Needs_h

#include "../String.h"
#include "Ingredient.h"

class Need{
public:
    Need();
    
    Ingredient* getIngredient();
    float getQTY();
    Need* getNext();
    
    void setIngredient(Ingredient* ingredient);
    void setQTY(float qty);    
    void setNext(Need* next);
private:
    Ingredient* ingredient;
    float qty;
    Need* next;
};


#endif