#include "Part2Header.h"
#include "BST.h"
#include "node.h"


node* BST::createBST(std::vector<node>& inp, std::string choice) { //choice == "Day" --> sort by day || choice == "Temperature"
	// need to sort here based on the funcType that will be given as an input (to the template?? maybe)
	if (choice == "Day") {
		SortMaybe<int>(inp, &node::getDay);
	}
	else if (choice == "Temperature") {
		SortMaybe<float>(inp, &node::getAvTemp);
	}
	else {
		std::cout << "That is not a valid operation!" << std::endl;
		throw;
	}
	if (inp[inp.size() / 2].getParent() != NULL) { //An exei 3anaginei kapoio createBST me autous tous kombous, ka8arise ta (proxeirh lush alla ikanopoiei tis anagkes mas --> diskola to root tou bst tou 1ou erothmatos == root tou bst tou 2ou erothmatos) 
												   // (to problhma 8a emfanistei epishs an ginei diagrafh tou root sto A erothma kai meta ginei klisi tou B, parola auta logo ths aplothtas ton zhtoumenon sto B
												   // to problhma de 8a ginei antilipto apo ton xrhsth)
		for (unsigned int i = 0; i < inp.size(); i++) {
			inp[i].cleanPointers();
		}
	}

	return createBST(inp, 0, inp.size() - 1);
}

node* BST::createBST(std::vector<node> &inp, int left, int right) { //should pass the vector by reference so I may not create new nodes, just point to them!
	int size = right - left + 1;
	int mid = left + (int)floor(size / 2);
	node* root;

	//The rest is based to the position of every element on the array so it should be fine.
	if (left > right) {
		return NULL;
	}
		
	root = &inp[mid];
	inp[mid].setLeft(createBST(inp, left, mid - 1));
	if (inp[mid].getLeft() != NULL) {
		inp[mid].getLeft()->setParent(&inp[mid]);
	}
	
	inp[mid].setRight(createBST(inp, mid + 1, right));
	if (inp[mid].getRight() != NULL) {
		inp[mid].getRight()->setParent(&inp[mid]);
	}

	return root;
}
