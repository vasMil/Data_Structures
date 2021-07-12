#include "Part2Header.h"
#include "BST.h"
#include "node.h"

//trivial functions for BST
BST::BST(std::vector<node> &inp, std::string str) {
	
	this->root = createBST(inp, str); //an kanei trow ton hpiame (NEEDS TRY - CATCH)
}

node* BST::getRoot() {
	return this->root;
}
void BST::setRoot(node* newRoot) {
	this->root = newRoot;
}


//functions that are needed for the project
void BST::InOrderTraversal(node* root) {

	if (root == NULL) {
		return;
	}
	InOrderTraversal(root->getLeft());

	root->printNode();

	InOrderTraversal(root->getRight());
}

node* BST::searchTree(int date, node* root) {


	if (root != NULL && root->getDay() == date) {
		//std::cout << "Day found." << "\n" << "Average temperature of the day: " << root->getAvTemp() << std::endl;
		return root;
	}
	else if (root != NULL && root->getDay() < date) {
		return searchTree(date, root->getRight());
	}
	else if (root != NULL && root->getDay() > date) {
		return searchTree(date, root->getLeft());
	}
	else {
		//std::cout << "There's not a measurment for this day!" << std::endl;
		return NULL;
	}

}

void BST::changeTemp(node* changeMyTemp, float newTemp) {
	changeMyTemp->setAvTemp(newTemp);
	std::cout << std::endl;
	std::cout << "Printing the node, where the change occured:" << std::endl;
	changeMyTemp->printNode();
	std::cout << std::endl;
}


node* BST::getSuccessor(node* deleteMe) {
	node* tempor;
	tempor = deleteMe->getRight();
	while (tempor->getLeft() != NULL) {
		tempor = tempor->getLeft();
	}

	return tempor;
}

void BST::deleteNode(node* deleteMe) { //exei la8os stin periptosi p o deleteMe exei 2 paidia
	node* successor = NULL;


	if (deleteMe->getLeft() == NULL && deleteMe->getRight() == NULL) { //kanena paidi
		if (deleteMe->getParent() == NULL) { //root xoris paidia
			setRoot(NULL);
		}
		else if (deleteMe->getDay() > deleteMe->getParent()->getDay()) {
			deleteMe->getParent()->setRight(NULL);
		}
		else {
			deleteMe->getParent()->setLeft(NULL);
		}

	}
	else if (deleteMe->getLeft() == NULL) { //to deleteMe exei mono de3i paidi
		if (this->root == deleteMe) {											 //to deleteMe einai to root kai exei mono de3i paidi
			this->root = deleteMe->getRight();
		}
		else if (deleteMe->getDay() > deleteMe->getParent()->getDay()) { //to deleteMe einai de3i paidi kai exei mono de3i paidi
			deleteMe->getParent()->setRight(deleteMe->getRight());
		}
		else {															//to deleteMe einai aristero paidi kai exei mono de3i paidi
			deleteMe->getParent()->setLeft(deleteMe->getRight());
		}

		deleteMe->getRight()->setParent(deleteMe->getParent());
	}

	else if (deleteMe->getRight() == NULL) { //to deleteMe exei mono aristero paidi
		if (this->root == deleteMe) {											 //to deleteMe einai to root kai exei mono aristero paidi
			this->root = deleteMe->getLeft();
		}
		else if (deleteMe->getDay() > deleteMe->getParent()->getDay()) { //to deleteMe einai de3i paidi kai exei mono aristero paidi
			deleteMe->getParent()->setRight(deleteMe->getLeft());
		}
		else {															//to deleteMe einai aristero paidi kai exei mono aristero paidi
			deleteMe->getParent()->setLeft(deleteMe->getLeft());
		}

		deleteMe->getLeft()->setParent(deleteMe->getParent());
	}

	else { //2 paidia psaxno inorder successor
		successor = getSuccessor(deleteMe);
		deleteNode(successor); //The node isn't actually deleted, this will just fix the tree in a way successor gets detached from it's current position in the tree
								//this way the pointer still points to the correct node I want to later modify, so it raplaces the node I am removing from the tree

		successor->setParent(deleteMe->getParent());
		successor->setLeft(deleteMe->getLeft());
		successor->setRight(deleteMe->getRight());
		if (deleteMe != this->root && deleteMe->getParent()->getDay() > deleteMe->getDay()) {
			deleteMe->getParent()->setLeft(successor);
		}
		else if (deleteMe != this->root){
			deleteMe->getParent()->setRight(successor);
		}
		else {
			setRoot(successor);
		}
		if (deleteMe->getLeft() != NULL) {
			deleteMe->getLeft()->setParent(successor);
		}
		if (deleteMe->getRight() != NULL) {
			deleteMe->getRight()->setParent(successor);
		}
	}

	deleteMe->setLeft(NULL);
	deleteMe->setRight(NULL);
	deleteMe->setParent(NULL);
}