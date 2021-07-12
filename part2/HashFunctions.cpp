#include "Part2Header.h"
#include "node.h"
#include "Hash.h"
#include <iomanip>

int Hash::stringToInt_Day(std::string str) { 
	auto i = str.begin();
	std::string clean;
	while (i != str.end()) {
		if (*i != '-') {
			clean = clean + *i;
		}
		i++;
	}
	return stoi(clean);
}


node* Hash::HashSearch(int day) {
	int pos = hashFunc(day);
	node* cur = this->table[pos];
	while (cur != NULL && cur->getDay() != day) {
		cur = cur->getRight();
	}

	if (cur == NULL) {
		//std::cout << "The element is not in the Hash Table" << std::endl;
		return NULL;
	}
	else {
		//std::cout << "Element found! Printing it: " << std::endl;
		//cur->printNode();
		return cur;
	}
}

void Hash::changeTemp(int day, float newTemp) {
	node* changeMyTemp = this->HashSearch(day);
	changeMyTemp->setAvTemp(newTemp);

	std::cout << "Printing the element with the new average temperature:" << std::endl;
	changeMyTemp->printNode();
}

void Hash::deleteHashNode(int day) {
	int pos = hashFunc(day);
	node* deleteMe = table[pos];
	if (deleteMe != NULL && deleteMe->getDay() == day) {
		deleteMe = deleteMe->getRight();
		table[pos] = deleteMe; //An einai monadiko stoixeio, tote to de3i paidi einai NULL
								//An iparxei de3i stoixeio, tote auto 8a ginei proto stoixeio sth diasindedemenh lista
	}
	else if (deleteMe != NULL && deleteMe->getRight() != NULL){
		while (deleteMe->getRight() != NULL && deleteMe->getRight()->getDay() != day) {
			deleteMe = deleteMe->getRight();
		}
		
		if (deleteMe->getRight() == NULL) {
			std::cout << "There is no such element in the hash table!!" << std::endl;
		}
		else {
			deleteMe->setRight(deleteMe->getRight()->getRight());
		}
	}
	else {
		std::cout << "There is no such element in the hash table!!" << std::endl;
	}

}

void Hash::PrintHashTable() {
	node* tempor;
	for (unsigned int i = 0; i < this->table.size(); i++) {
		if (this->table[i] != NULL) {
			std::cout << "|" << "-------------" << "|" << std::endl;
			std::cout << "|";
			std::cout << std::setw(2) << std::setfill('0') << i;
			std::cout << ". " << this->table[i]->getDay() << " |";
		}
		else {
			std::cout << "|" << "-------------" << "|" << std::endl;
			std::cout << "|";
			std::cout << std::setw(2) << std::setfill('0') << i;
			std::cout << ". " << "I AM NULL" << "|";
		}
		tempor = this->table[i];
		while (tempor != NULL) {
			tempor = tempor->getRight();
			if (tempor != NULL) {
				std::cout << " ----> " << tempor->getDay();
			}
		}
		std::cout << std::endl;
	}
	std::cout << "|-------------|" << std::endl;
}