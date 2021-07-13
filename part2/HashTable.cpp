#include "Part2Header.h"
#include "node.h"
#include <math.h>

void cleanPointers(node *n) { //oste na mh ginei kanena mperdema an exei ginei klish ths createBST prin
	n->setLeft(NULL);
	n->setRight(NULL);
	n->setParent(NULL);
}

int hashFunc(int day, int numOfBuckets) {
	std::string str = std::to_string(day);
	int sum = 0;
	const int dash = (int)('-');
	auto i = str.begin();
	for (; i != str.end(); i++) {
		sum = sum + (int)*i;
	}
	return (sum + dash) % numOfBuckets;
}

std::vector<node*> HashTable(std::vector<node>& inp) {
	const int HASH_SIZE = 19;	//Se ena etos max hmerominia: 09-29 --> (9 + 2 + 9 = 20) kai min hmerominia: 01-01 (1 + 1 = 2), opote #buckets = 20 - 2 + 1 = 19
	std::vector<node*> vec(HASH_SIZE, NULL); //8a mporouse na einai array
	node* next;
	
	for (int i = 0; i < inp.size(); i++) {
		cleanPointers(&inp[i]);

		int pos = hashFunc(inp[i].getDay(), HASH_SIZE);
		if (vec[pos] == NULL) {
			vec[pos] = &inp[i];
		}
		else {
			next = vec[pos];
			while (next->getRight() != NULL) {
				next = next->getRight();
			}
			next->setRight(&inp[i]);
		}
	}
	return vec;
}