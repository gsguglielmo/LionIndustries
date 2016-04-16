#include "./Table.h"

Table::Table(){
    size= 0;
    vrstice = (Row**)malloc(size*sizeof(Row*));
}

Table::~Table(){
    free(vrstice);
}

void Table::add(Row* vrstica){
    size++;
    vrstice = (Row**)realloc(vrstice,size*sizeof(Row*));
    vrstice[size-1] = vrstica;
}

Row* Table::get(unsigned int element){
    return vrstice[element];
}

unsigned int Table::getSize(){
    return size;
}

void Table::izpisiVse(){
    int i;
    for(i=0;i<size;i++){
        printf("=>Row %d\n",i+1);
        vrstice[i]->izpisiVse();
    }
}

void Table::setEmpty(bool status){
    empty = status;
}

bool Table::isEmpty(){
    return empty;
}

