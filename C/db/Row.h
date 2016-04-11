#ifndef Vrstica_h
#define Vrstica_h


#include <stdio.h>
#include <stdlib.h>
#include "String.h"

class Row{
public:
    Row();
    ~Row();
    void add(String* s);
    String* get(unsigned int fieldNumber);
    unsigned int getNumFields();
    void izpisiVse();
private:
    String** elementi;
    unsigned int size;
};

#endif