#include "Part2Header.h"
#include "node.h"

class Hash {
private:
	std::vector<node*> table;
public:
	Hash(std::vector<node>& inp);
	std::vector<node*> HashTable(std::vector<node>& inp);
	int hashFunc(int day, int numOfBuckets = 19); //The hash function used to determine the position of each node. Sum of all ascii characters of the string, module 19;

	int stringToInt_Day(std::string str); // dateFix() does the same 
	node* HashSearch(int day);
	void changeTemp(int day, float newTemp);
	void deleteHashNode(int day);
	void PrintHashTable();

};