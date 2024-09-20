#include <bits/stdc++.h>
#include "symtable.h"
#include <gtest/gtest.h>

using namespace std; 

// struct SymTableTest: testing::Test{
//     SymTable symTable = SymTable_new();
// };


// TEST_F(SymTableTest, SymTableNew){
void test_symtable_new(){
    SymTable symTable;
    cout<<"Test for symTable_new passed: allocated memory for new symtable" << endl;
    cout <<"Newly allocated memory: "<< &symTable << endl;
}

// void test_symtable_free(SymTable symTable){
//     assert(symTable != nullptr);
//     SymTable_free(symTable);
//     cout<<"Test for symTable_free passed: Nothing to check here " << endl;
    
// }

void test_symTable_getlength(SymTable &symTable){
    // assert(symTable != nullptr);
    cout <<"Finding length for symtable starting at: "<< &symTable << endl;
    if (symTable.getLength() == 0){
        cout<<"Test for symTable.getLength passed: length=0 for newly created symtable." << endl;
    }
    else{
        cout<<"Test for symTable.getLength failed"<<endl;
    }
    // SymTable_free(symTable);
}


void printBinding(const char *key, const void *value, void *extra) {
    const int *intValue = static_cast<const int *>(value);
    cout<<"Key: "<<key<< ",Value: "<< *intValue << endl;
}

void test_symtable_map(SymTable &symTable){
	if(symTable.getLength() == 0 )
		cout << "No bindings to map => length = 0"<< endl;
	else{
		cout<<"Test for symTable_map passed.\nPrinting the bindings: "<<endl;
        symTable.map(printBinding, nullptr);
    }
}

void test_symtable_put (SymTable &symTable,const char *pcKey, const void *pvValue){
    // assert(symTable != nullptr);
    int len1 = symTable.getLength();
    int putValue = symTable.put(pcKey,pvValue);
    int len2 = symTable.getLength();
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

void test_symtable_contains(SymTable &symTable, const char *pcKey){
    // test has been used after using put for the key and value so it should return 1
    if (symTable.contains(pcKey)){
        cout << "Test for symTable_contains passed: returns 1 for valid key in symtable "<<endl;
    }
    else{
        cout << "Test failed for symTable_contains"<<endl;
    }
}

void test_symTable_get (SymTable &symTable,const char *pcKey, const void *pvValue){
    void *val = symTable.get(pcKey);
    if (val == pvValue){
        cout << "Test for symTable_get passed: returns the correct binding value "<<endl;
    }
    else{
        cout <<"Test for symTable_get Failed"<<endl;
    }
    
}   

void test_symtable_replace(SymTable &symTable, const char *pcKey, const void *pvValue){
    void * getValue = symTable.get(pcKey);
    void * oldValue = symTable.replace(pcKey,pvValue);
    if (oldValue == getValue){
        cout << "Test for Symtable_replace passed: returns pointer to the old value"<<endl;
    }
    else{
        cout << "Test for Symtable_replace failed"<<endl;
    }
}

void test_symtable_remove (SymTable &symTable, const char *pcKey){
    void * getValue = symTable.get(pcKey);
    void * oldValue = symTable.remove(pcKey);
    if (oldValue == getValue){
        cout << "Test for Symtable_remove passed: returns pointer to the old value"<<endl;
        if (symTable.contains(pcKey) == 0){
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
    SymTable symTable;
    test_symtable_new();
    test_symTable_getlength(symTable);
    test_symtable_map(symTable);
    const char *key = "var";
    int value = 20;
    test_symtable_put(symTable,key,(const void*)&value);
    test_symtable_put(symTable,key,(const void*)&value);
    const char *key1 = "var1";
    int value1 = 74;
    test_symtable_put(symTable,key1,(const void*)&value1);
    test_symtable_map(symTable);
    test_symtable_contains(symTable,key);
    test_symTable_get(symTable,key1,(const void*)&value1);
    test_symtable_replace(symTable,key,(const void*)&value1);
    test_symtable_remove(symTable,key);
    test_symtable_map(symTable);
    return 0;
}