#include <bits/stdc++.h>
#include "symtable.h"

using namespace std;

struct Binding {
    char* key;
    void* value;
    Binding* next;
};

struct SymTable{
    Binding* head;
    int length;

    SymTable() : head(nullptr),length(0){}

};


// SymTable_new should create a new SymTable structure with no bindings within it. If not enough memory 
// is available, the function will return a NULL pointer, else it will return a pointer to the Structure.
SymTable_t SymTable_new (void){
    SymTable_t symTable = new SymTable();
    if (!symTable){
        return nullptr;
    }
    return symTable;
}

// SymTable_free should free all the memory occupied by the symbol table pointed to by
// oSymTable, including all the allocated structure fields, bindings, and buckets (if applicable)
void SymTable_free (SymTable_t oSymTable){
    assert(oSymTable != nullptr); // assert macro to ensure it is not a void pointer
    Binding* curr = oSymTable->head; // curr = head
    while (curr != nullptr){ // deleting all the nodes in a loop until it is empty
        Binding* next = curr->next;
        delete curr;
        curr = next;
    }
    delete oSymTable;// delete the symtable
}

//SymTable_getLength should return the total number of bindings within oSymTable.
int SymTable_getLength (SymTable_t oSymTable){
    assert(oSymTable != nullptr);
    return oSymTable->length;
}


void SymTable_map (SymTable_t oSymTable, void (*pfApply) (const char *pcKey, const void *pvValue, void *pvExtra), const void *pvExtra){
    assert(oSymTable != nullptr);
    Binding* curr = oSymTable->head; 
    while (curr != nullptr){
        pfApply(curr->key, curr->value, (void *) pvExtra);
        curr = curr->next;
    }
}