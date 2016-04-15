#ifndef Needs_h
#define Needs_h

#include "../String.h"

class Need{
public:
    Need();
    
    String* getIngredient();
    float getQTY();
    Need* getNext();
    
    void setIngredient(String* ingredient);
    void setQTY(float qty);    
    void setNext(Need* next);
private:
    String* ingredient;
    float qty;
    Need* next;
};


#endif