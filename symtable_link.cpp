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
    while (curr){ // deleting all the nodes in a loop until it is empty
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

int SymTable_contains (SymTable_t oSymTable, const char *pcKey){
    assert(oSymTable != nullptr);
    assert(pcKey != nullptr);

    Binding *curr = oSymTable->head;
    while (curr){
        if (curr->key == pcKey) return 1;// key already exists
        curr = curr->next;
    }
    return 0;
}

int SymTable_put (SymTable_t oSymTable,const char *pcKey, const void *pvValue){
    assert(oSymTable != nullptr);
    assert(pcKey != nullptr);
    assert(pvValue != nullptr);
    if (SymTable_contains(oSymTable, pcKey)==0){
        Binding *newBinding = new Binding;
        if (!newBinding) return 0;//failed mem allocation
        newBinding->key = (char*)pcKey;
        newBinding->value = (void*)pvValue;
        newBinding->next = oSymTable->head;
        oSymTable->head = newBinding;//newbinding is the new head
        oSymTable->length += 1;
        return 1;
    }
    return 0;//key not found
}   


void *SymTable_get (SymTable_t oSymTable, const char *pcKey){
    assert(oSymTable != nullptr);
    assert(pcKey != nullptr);
    Binding *curr = oSymTable->head;
    while (curr){
        if (strcmp(pcKey,curr->key)==0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return nullptr;
}

void *SymTable_replace (SymTable_t oSymTable, const char *pcKey, const void *pvValue){
    assert(oSymTable != nullptr);
    assert(pcKey != nullptr);
    assert(pvValue != nullptr);
    Binding *curr = oSymTable->head;
    while (curr){
        if (curr->key == pcKey){//if equal
            void *oldValue = curr->value; // pointer to the original value
            curr->value = const_cast<void *>(pvValue);// new value for the binding
            return oldValue;// returns pointer to the old value
        }
        curr = curr->next;
    }
    return nullptr;

}


void *SymTable_remove (SymTable_t oSymTable, const char *pcKey){
    assert(oSymTable != nullptr);
    assert(pcKey != nullptr);
    Binding* curr = oSymTable->head; // curr = head
    Binding* prev = nullptr;
    while (curr){ 
        if (curr->key == pcKey) {
            if (prev == nullptr) {
                oSymTable->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            void* oldValue = curr->value;
            delete curr;
            oSymTable->length--;
            return oldValue; // Return the old value
        }
        prev = curr;
        curr = curr->next;
    }
    return nullptr;

}