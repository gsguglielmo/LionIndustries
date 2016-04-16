#include "MarkDatabase.h"

MarkDatabase::MarkDatabase(const char address[],const char username[],const char password[]):Database(address,username,password,"Inebriator"){
    inElaboration = NULL;
    status = false;
}

Queue* MarkDatabase::getNext(){
    return buildNextElement();
}

Queue* MarkDatabase::buildNextElement(){
    Queue* element = new Queue();
    Table* rez = query("SELECT * FROM Queue WHERE 1");
    if(rez == NULL){
        throw 0x10; //Napaka
    }
    if(rez->isEmpty() || rez->getSize() < 1){
       throw 0x01; //Ni novih elementov
    }
    Row* row = rez->get(0);
    int tmp = atoi(row->get(0)->getString());
    element->setID(tmp);
    tmp = atoi(row->get(1)->getString());
    element->setUserID(tmp);
    element->setReceipe(buildReceipe(row->get(2)));
    return element;
}

Receipe* MarkDatabase::buildReceipe(String* receipeName){
    Receipe* receipe = new Receipe();
    String* queryS = new String("SELECT * FROM Receipe WHERE NomeRicetta='");
    queryS->concatenate(receipeName);
    queryS->concatenate(new String("'"));
    receipe->setID(0);
    receipe->setName(receipeName);
    Table* rez = query(queryS->getString());
    if(rez == NULL){
        throw 0x11; //Napaka
    }
    if(rez->isEmpty() || rez->getSize() < 1){
       throw 0x01; //Ni novih elementov
    }
    int i;
    Row* row;
    Need* need;
    
    for(i=0;i<rez->getSize();i++){
        row = rez->get(i);
        need = new Need();
        need->setIngredient(buildIngredient(row->get(2)));
        need->setQTY(atoi(row->get(3)->getString()));   
        receipe->addNeed(need);      
    }
    return receipe;
}

Ingredient* MarkDatabase::buildIngredient(String* ingredientName){
    Ingredient* ingredient = new Ingredient();
    String* queryS = new String("SELECT * FROM ingredients WHERE Name='");
    queryS->concatenate(ingredientName);
    queryS->concatenate(new String("'"));
    Table* rez = query(queryS->getString());
    if(rez == NULL){
        throw 0x11; //Napaka
    }
    if(rez->isEmpty() || rez->getSize() < 1){
       throw 0x01; //Ni novih elementov
    }
    int i;
    Row* row = rez->get(0);;
    ingredient->setID(atoi(row->get(0)->getString()));
    ingredient->setMachineID(atoi(row->get(1)->getString()));
    ingredient->setName(ingredientName);
    ingredient->setPosition(atoi(row->get(3)->getString()));
    ingredient->setFullQTY(atoi(row->get(4)->getString()));
    ingredient->setRemainingQTY(atoi(row->get(5)->getString()));
    return ingredient;
}