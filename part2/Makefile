CC=g++
CFLAGS=-c -Wall

all: part2

part2: BST.o createBST.o GetMyNodes.o Hash.o HashFunctions.o HashTable.o main.o MinMaxTemp.o node.o Part2Menu.o PrintTree.o
	$(CC) BST.cpp createBST.cpp GetMyNodes.cpp Hash.cpp HashFunctions.cpp HashTable.cpp main.cpp MinMaxTemp.cpp node.cpp Part2Menu.cpp PrintTree.cpp -o part2.exe

BST.o: BST.cpp
	$(CC) $(CFLAGS) BST.cpp
	
createBST.o: createBST.cpp
	$(CC) $(CFLAGS) createBST.cpp

GetMyNodes.o: GetMyNodes.cpp
	$(CC) $(CFLAGS) GetMyNodes.cpp

Hash.o: Hash.cpp
	$(CC) $(CFLAGS) Hash.cpp

HashFunctions.o: HashFunctions.cpp
	$(CC) $(CFLAGS) HashFunctions.cpp

HashTable.o: HashTable.cpp
	$(CC) $(CFLAGS) HashTable.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

MinMaxTemp.o: MinMaxTemp.cpp
	$(CC) $(CFLAGS) MinMaxTemp.cpp

node.o: node.cpp
	$(CC) $(CFLAGS) node.cpp

Part2Menu.o: Part2Menu.cpp
	$(CC) $(CFLAGS) Part2Menu.cpp

PrintTree.o: PrintTree.cpp
	$(CC) $(CFLAGS) PrintTree.cpp

clean:
	rm -rf *.o