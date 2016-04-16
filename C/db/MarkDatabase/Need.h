#ifndef Needs_h
#define Needs_h

#include "../String.h"
#include "Ingredient.h"

class Need{
public:
    Need();
    
    Ingredient* getIngredient();
    int getQTY();
    Need* getNext();
    
    void setIngredient(Ingredient* ingredient);
    void setQTY(int qty);    
    void setNext(Need* next);
private:
    Ingredient* ingredient;
    int qty;
    Need* next;
};


#endif