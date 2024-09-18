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
    cout<<"Key: "<<key<< ",Value: "<< value << endl;
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

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }


int main(){
    test_symtable_new();
    SymTable_t symTable = SymTable_new();
    test_symtable_getlength(symTable);
    test_symtable_map(symTable);
    
    test_symtable_free(symTable);
    return 0;
}