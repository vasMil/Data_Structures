#pragma once
#include "Part2Header.h"
#include "node.h"

class BST {
private:
	node* root;

public:
	BST(std::vector<node> &inp, std::string str = "Day");
	node* getRoot();
	void setRoot(node* newRoot);

	node* createBST(std::vector<node>& inp, std::string choice = "Day");
	node* createBST(std::vector<node>& inp, int left, int right);

	void InOrderTraversal(node* root);
	void InOrderTraversal() {
		InOrderTraversal(this->root);
	}

	node* searchTree(int date, node* root);
	node* searchTree(int date) {
		return searchTree(date, this->root);
	}

	void changeTemp(node* changeMyTemp, float newTemp);
	node* getSuccessor(node* deleteMe);
	void deleteNode(node* deleteMe); //de xreiazetai to parent pedio, diabazontas katalaba oti einai tradeoff memory/speed, gia auto kai 8a diathrhso to pedio auto ston kodika

	node* getMin();
	node* getMax();


	void printTree(node* root, int space);
	void printTree(int space = 0){
		printTree(this->root, space);
	}
	void createDOTfile(node* root);
	void createDOTfile();
	void Traverse(node* root, std::fstream& dotfile);
};