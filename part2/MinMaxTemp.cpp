#include "Part2Header.h"
#include "node.h"
#include "BST.h"

node* BST::getMin() {
	node* res = this->root;
	while (res->getLeft() != NULL) {
		res = res->getLeft();
	}
	std::cout << std::endl;
	std::cout << "The node with the minimum key (average temperature) is: " << std::endl;
	res->printNode();
	std::cout << std::endl;

	return res;
}

node* BST::getMax() {
	node* res = this->root;
	while (res->getRight() != NULL) {
		res = res->getRight();
	}
	std::cout << std::endl;
	std::cout << "The node with the maximum key (average temperature) is: " << std::endl;
	res->printNode();
	std::cout << std::endl;

	return res;
}

int dateFix(std::string fdate) {
	std::string day;
	auto x = fdate.begin();
	while (x != fdate.end()) {

		if (*x != '-') {
			day = day + *x;
		}
		x++;
	}
	return stoi(day);
}