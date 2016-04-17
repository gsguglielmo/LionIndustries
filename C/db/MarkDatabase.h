#ifndef MarkDatabase_h
#define MarkDatabase_h

#include "Database.h"
#include "MarkDatabase/Queue.h"
#include <stdlib.h>

class MarkDatabase : private Database{
public:
    MarkDatabase(const char address[],const char username[],const char password[]);   
    Queue* getNext();
    void setCompleted();
    void setNotCompleted();
    bool isCompleted();
    void updateQty(Need* need);
private:
    Queue* inElaboration;
    bool status;
    void setStatus(int status);
    Queue* buildNextElement();
    Receipe* buildReceipe(String* receipeName);
    Ingredient* buildIngredient(String* ingredientName);
};

#endif