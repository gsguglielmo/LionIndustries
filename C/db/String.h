#ifndef String_h
#define String_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class String{
public:
    String(char* charArray,int length);
    String(const char charArray[]);
    String(String* s);
    ~String();
    int getLength();
    char charAt(int position);
    void addChar(char newChar);
    void removeChar();
    void setChar(char newChar,int position);
    void concatenate(String* s);
    char* getString();
    bool compare(String* s);
    void toString();
private:
      char* string;
      int size;
};

#endif