#include "./Database.h"

Database::Database(const char address[],const char username[],const char password[],const char database[]){
    mysql = new MYSQL();
    DEBUG(("[Database]:[Database]=>Initializing database\n"));
    mysql_init(this->mysql);
    DEBUG(("[Database]:[Database]=>Database initialized\n"));
    if( !mysql_real_connect(this->mysql,address,username,password,database,0,NULL,0) ){
        DEBUG(("[Database]:[Database]=>Connection failed\n"));
        throw 0x01;
    }
    DEBUG(("[Database]:[Database]=>Successfully connected\n"));
}

Table* Database::query(const char query[]){
    MYSQL_ROW row;
    MYSQL_RES *result;
    DEBUG(("[Database]:[query]=>%s\n",query));
    if( mysql_query(mysql,query) ){
        DEBUG(("[Database]:[query]=>Query execution failed\n"));
        return NULL;
    }
    result = mysql_store_result(mysql);
    Table* table = new Table();
    if(result==NULL){
        if(mysql_errno(mysql)==0){
            Row* newRow = new Row();
            DEBUG(("[Database]:[query]=>Query execution successfully\n"));
            String* s = new String("Query successfully executed");
            newRow->add(s);
            table->add(newRow);
            return table;
        }
    }
    DEBUG(("[Database]:[query]=>Query execution successfully\n"));
    int fields = mysql_num_fields(result);
    int rows = mysql_num_rows(result);
    DEBUG(("[Database]:[query]=>%d rows\n",rows));
    DEBUG(("[Database]:[query]=>Each one has %d fields\n",fields));
    int i;
    
    while( (row = mysql_fetch_row(result)) ){
        Row* newRow = new Row();
        for(i=0;i<fields;i++){
            String* s = new String((char*)(row[i] ? row[i] : "NULL"));
            newRow->add(s);
        }
        table->add(newRow);
    }
    mysql_free_result(result);
    return table;
}