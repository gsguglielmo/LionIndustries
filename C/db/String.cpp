#include "./String.h"

String::String(char* charArray,int length){
    int i;
    size = length;
    this->string = (char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++){
        string[i] = charArray[i];
    }
}

String::String(const char charArray[]){
    int i;
    size = strlen(charArray);
    this->string = (char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++){
        string[i] = charArray[i];
    }
}

String::String(String* s){
    int i;
    size = s->getLength();
    this->string = (char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++){
        string[i] = s->charAt(i);
    }
}

String::~String(){
    free(string);
    
}

void String::concatenate(String* s){
    int secondSize = s->getLength();
    int i;
    size += secondSize;
    this->string = (char*)realloc(string,size*sizeof(char));
    for(i=(size-secondSize);i<size;i++){
        string[i] = s->charAt(i-(size-secondSize));
    }
}

char String::charAt(int position){
    if(position>=size){
        throw 1;
    }
    return string[position];
}

void String::setChar(char newChar,int position){
    if(position>=size){
        throw 1;
    }
    string[position] = newChar;
}

int String::getLength(){
    return size;
}

void String::toString(){
    int i;
    for(i=0;i<size;i++){
        printf("%c",string[i]);
    }
    printf("\n");
}

char* String::getString(){
    char* tmp = (char*)malloc((size+1)*sizeof(char));
    int i;
    for(i=0;i<size;i++){
        tmp[i] = string[i];
    }
    tmp[i] = '\0';
    return tmp;
}

bool String::compare(String* s){
    if(this->getLength() != s->getLength()){
        return false;
    }
    int i;
    for(i=0;i<this->getLength();i++){
        if(charAt(i) != s->charAt(i)){
            return false;
        }
    }
    return true;
}