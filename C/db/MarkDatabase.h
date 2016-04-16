#ifndef MarkDatabase_h
#define MarkDatabase_h

#include "Database.h"
#include "Queue.h"


class MarkDatabase : private Database{
public:
    MarkDatabase(const char address[],const char username[],const char password[]);   
    Queue* getNext();
    void setCompleted();
    void setNotCompleted();
    bool isCompleted();
private:
    Queue* inElaboration;
    bool status;
    
    Queue* buildNextElement();
    
};

#endif