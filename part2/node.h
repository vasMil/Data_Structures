#pragma once
#include "Part2Header.h"

class node {
	node* left;
	node* right;
	node* parent; //8a mporousame na apofigoume to parent, apla diefkoline tis ilopoihseis mas afou mporoume na "kini8oume" toso apo th riza oso kai pros th riza
	int day;
	float avTemp; //probably a double wouldn't hurt, but oh well

public:

	node();
	node(int day, float avtemp);

	void setAvTemp(float temp);
	void setDay(int day);
	void setLeft(node* left);
	void setRight(node* right);
	void setParent(node* parent);

	float getAvTemp();
	int getDay();
	node* getLeft();
	node* getRight();
	node* getParent();

	void printNode();
	void cleanPointers();
};