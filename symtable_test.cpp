#include <bits/stdc++.h>
#include "symtable.h"
#include <gtest/gtest.h>

using namespace std; 

// struct SymTableTest: testing::Test{
//     SymTable_t symTable = SymTable_new();
// };


// TEST_F(SymTableTest, SymTableNew){
void test_symtable_new(){
    SymTable_t symTable = SymTable_new();
    assert(symTable!= nullptr);
    cout<<"Test for symTable_new passed: allocated memory for new new symtable" << endl;
    cout <<"Newly allocated memory: "<< symTable << endl;
    SymTable_free(symTable);//freeing the memory allocated
}

void test_symtable_free(SymTable_t symTable){
    assert(symTable != nullptr);
    SymTable_free(symTable);
    cout<<"Test for symTable_free passed: Nothing to check here " << endl;
    
}

void test_symtable_getlength(SymTable_t symTable){
    assert(symTable != nullptr);
    cout <<"Finding length for symtable starting at: "<< symTable << endl;
    if (SymTable_getLength(symTable) == 0){
        cout<<"Test for symTable_getLength passed: length=0 for newly created symtable." << endl;
    }
    else{
        cout<<"Test for symTable_getLength failed"<<endl;
    }
    // SymTable_free(symTable);
}


void printBinding(const char *key, const void *value, void *extra) {
    const int *intValue = static_cast<const int *>(value);
    cout<<"Key: "<<key<< ",Value: "<< *intValue << endl;
}

void test_symtable_map(SymTable_t symTable){
    assert(symTable != nullptr);
	if(SymTable_getLength(symTable) == 0 )
		cout << "No bindings to map => length = 0"<< endl;
	else{
		cout<<"Test for symTable_map passed.\nPrinting the bindings: "<<endl;
        SymTable_map(symTable, printBinding, nullptr);
    }
}

void test_symtable_put (SymTable_t symTable,const char *pcKey, const void *pvValue){
    assert(symTable != nullptr);
    int len1 = SymTable_getLength(symTable);
    int putValue = SymTable_put(symTable,pcKey,pvValue);
    int len2 = SymTable_getLength(symTable);
    if (putValue ==1 && len2-len1 ==1){
        cout << "Test passed: new binding created for this key and value"<<endl;
    }
    else if(putValue ==0 && len2==len1){
        cout << "Test passed: failed to add new binding and returns 0"<<endl;
    }
    else{
        cout << "Test failed for SymTable_put fnction"<<endl;
    }
    
}   

void test_symtable_contains(SymTable_t symTable, const char *pcKey){
    assert(symTable != nullptr);
    assert(pcKey != nullptr);
    // test has been used after using put for the key and value so it should return 1
    if (SymTable_contains(symTable,pcKey)){
        cout << "Test for symTable_contains passed: returns 1 for valid key in symtable "<<endl;
    }
    else{
        cout << "Test failed for symTable_contains"<<endl;
    }
}

void test_symtable_get (SymTable_t symTable,const char *pcKey, const void *pvValue){
    void *val = SymTable_get(symTable, pcKey);
    if (val == pvValue){
        cout << "Test for symtable_get passed: returns the correct binding value "<<endl;
    }
    else{
        cout <<"Test for symtable_get Failed"<<endl;
    }
    
}   

void test_symtable_replace(SymTable_t symTable, const char *pcKey, const void *pvValue){
    void * getValue = SymTable_get(symTable,pcKey);
    void * oldValue = SymTable_replace(symTable,pcKey,pvValue);
    if (oldValue == getValue){
        cout << "Test for Symtable_replace passed: returns pointer to the old value"<<endl;
    }
    else{
        cout << "Test for Symtable_replace failed"<<endl;
    }
}

void test_symtable_remove (SymTable_t symTable, const char *pcKey){
    void * getValue = SymTable_get(symTable,pcKey);
    void * oldValue = SymTable_remove(symTable,pcKey);
    if (oldValue == getValue){
        cout << "Test for Symtable_remove passed: returns pointer to the old value"<<endl;
        if (SymTable_contains(symTable,pcKey) == 0){
            cout << "Binding with the key has been deleted"<<endl;
        }
    }
    else{
        cout << "Test for Symtable_remove failed"<<endl;
    }
}


// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }


int main(){
    test_symtable_new();
    SymTable_t symTable = SymTable_new();
    test_symtable_getlength(symTable);
    test_symtable_map(symTable);
    const char *key = "var";
    int value = 20;
    test_symtable_put(symTable,key,(const void*)&value);
    test_symtable_put(symTable,key,(const void*)&value);
    const char *key1 = "var1";
    int value1 = 74;
    test_symtable_put(symTable,key1,(const void*)&value1);
    test_symtable_contains(symTable,key);
    test_symtable_get(symTable,key1,(const void*)&value1);
    test_symtable_replace(symTable,key,(const void*)&value1);
    test_symtable_remove(symTable,key);
    test_symtable_map(symTable);
    test_symtable_free(symTable);
    return 0;
}