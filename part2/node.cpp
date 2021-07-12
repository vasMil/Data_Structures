#include "Part2Header.h"
#include "node.h"

node::node() {
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->day = 0;
	this->avTemp = 0;
}

node::node(int day, float avtemp) {
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->day = day;
	this->avTemp = avtemp;
}

void node::setAvTemp(float temp) {
	this->avTemp = temp;
}

void node::setDay(int day) {
	this->day = day;
}

void node::setLeft(node* left) {
	this->left = left;
}

void node::setRight(node* right) {
	this->right = right;
}

void node::setParent(node* parent) {
	this->parent = parent;
}

float node::getAvTemp() {
	return this->avTemp;
}

int node::getDay() {
	return this->day;
}

node* node::getLeft() {
 	return this->left;
}

node* node::getRight() {
	return this->right;
}

node* node::getParent() {
	return this->parent;
}

void node::printNode() {
	if (this == NULL) {
		std::cout << "I am not in this data structure!\n" << std::endl;
	}
	else {
		std::cout << "Day: " << this->day << "\n" << "Average Temperature: " << this->avTemp << std::endl;
	}
}

void node::cleanPointers() { //oste na mh ginei kanena mperdema an exei ginei klish ths createBST prin
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}