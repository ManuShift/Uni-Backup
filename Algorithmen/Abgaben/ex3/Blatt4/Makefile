ex3: ex3.o HashTable.o HashTableSkip.o HashTableShift.o
	g++ -o ex3 ex3.o HashTable.o HashTableShift.o HashTableSkip.o
	rm HashTable.o ex3.o HashTableSkip.o HashTableShift.o

ex3.o: ex3.cpp HashTable.h HashTableSkip.h HashTableShift.h
	g++ -c ex3.cpp

HashTable.o: HashTable.h

HashTableSkip.o: HashTableSkip.h HashTable.h

HashTableShift.o: HashTableShift.h HashTable.h
