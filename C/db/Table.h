#ifndef Rezultat_h
#define Rezultat_h



#include "Row.h"
#include <stdio.h>
#include <stdlib.h>

class Table{
public:
    Table();
    ~Table();
    void add(Row* vrstica);
    Row* get(unsigned int element);
    unsigned int getSize();
    void izpisiVse();
private:   
    Row** vrstice;
    unsigned int size;
};

#endif