CPP = g++
CPPFLAGS = 
GTESTFLAGS = -lgtest -lgtest_main -lpthread
FINAL = symtable_test

all: $(FINAL)

$(FINAL): symtable_link.o symtable_test.o
	$(CPP) $(CPPFLAGS) -o $(FINAL) symtable_link.o symtable_test.o

symtable_link.o: symtable_link.cpp symtable.h
	$(CPP) $(CPPFLAGS) -c symtable_link.cpp

symtable_test.o: symtable_test.cpp symtable.h
	$(CPP) $(CPPFLAGS) -c symtable_test.cpp  

clean:
	rm -rf *.o $(FINAL)
