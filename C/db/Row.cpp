#include "./Row.h"

Row::Row(){
    elementi = (String**)malloc(0*sizeof(String*));
    size=0;
}

Row::~Row(){
    free(elementi);
}

void Row::add(String* s){
    size++;
    elementi = (String**)realloc(elementi,this->size * sizeof(String*));
    elementi[size-1] = s;
}

String* Row::get(unsigned int fieldNumber){
    return elementi[fieldNumber];
}

unsigned int Row::getNumFields(){
    return size;
}

void Row::izpisiVse(){
    int i;
    for(i=0;i<size;i++){
        elementi[i]->toString();
    }
}