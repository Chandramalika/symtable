#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>

// typedef struct SymTable*
// SymTable_t;
class SymTable{
public:
    SymTable();
    int getLength ();
    int put (const char *pcKey, const void *pvValue);
    void *replace (const char *pcKey, const void *pvValue);
    int contains (const char *pcKey);
    void *get (const char *pcKey);
    void *remove (const char *pcKey);
    void map (void (*pfApply) (const char *pcKey, const void *pvValue, void *pvExtra), const void *pvExtra);

    ~SymTable();
private: 
    struct Binding {
    char* key;
    void* value;
    Binding* next;
    };
    Binding* head;
    int length;

};
#endif

// SymTable_t SymTable_new(void);
// void SymTable_free (SymTable_t oSymTable);
// int SymTable_getLength (SymTable_t oSymTable);
// int SymTable_put (SymTable_t oSymTable,const char *pcKey, const void *pvValue);
// void *SymTable_replace (SymTable_t oSymTable, const char *pcKey, const void *pvValue);
// int SymTable_contains (SymTable_t oSymTable, const char *pcKey);
// void *SymTable_get (SymTable_t oSymTable, const char *pcKey);
// void *SymTable_remove (SymTable_t oSymTable, const char *pcKey);
// void SymTable_map (SymTable_t oSymTable, void (*pfApply) (const char *pcKey, const void *pvValue, void *pvExtra), const void *pvExtra);
