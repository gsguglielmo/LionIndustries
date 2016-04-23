#ifndef Database_h
#define Database_h

//DEBUG
#if 0
#define DEBUG(a) printf a
#else
#define DEBUG(a) (void) a
#endif
//DEBUG

#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "Table.h"
#include "String.h"

class Database{
public:

    Database(const char address[],const char username[],const char password[],const char database[]);
    Table* query(const char query[]);
private:
    MYSQL* mysql;
    int numFields;
    int numRows;
};

#endif
