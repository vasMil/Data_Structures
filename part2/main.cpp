#include "Part2Header.h"
#include "node.h"
#include "BST.h"
#include "Hash.h"

int main(int argc, const char* argv[]) {
	std::vector<node> inp;
	GetMyNode("tempm.txt", inp);
	MainMenu(inp);


	/*//________________________________________________________DELETE NODE DEBUG
	//root = deleteNode(root,root);
	for (unsigned int i = 0; i < inp.size(); i++) {
		std::cout << i << ".\t";
		std::cout << inp[i].getAvTemp() << std::endl;
		//inp[i].printNode();
	}
	myTree.getRoot()->printNode();
	std::cout << "left child" << std::endl;
	myTree.getRoot()->getLeft()->printNode();
	std::cout << std::endl;

	std::cout << "right child" << std::endl;
	myTree.getRoot()->getRight()->printNode();
	std::cout << std::endl;
//_______________________________________________________________DELETE NODE DEBUG END*/

/*//____________________________________________________________________________________________________________________________________________________________________________ATTEMPTS TO CHECK IF THE TREE IS A BST
	for (int i = 0; i < inp.size(); i++) {
		
		if (inp[i].getRight() != NULL && inp[i].getDay() < inp[i].getRight()->getDay() && inp[i].getLeft() == NULL) {

		}
		else if (inp[i].getLeft() != NULL && inp[i].getDay() > inp[i].getLeft()->getDay() && inp[i].getRight() == NULL) {

		}
		else if (inp[i].getRight() != NULL && inp[i].getLeft() != NULL && inp[i].getLeft()->getDay() < inp[i].getDay() && inp[i].getRight()->getDay() > inp[i].getDay()) {
			//komple o kombos
		}
		else if (inp[i].getLeft() == NULL && inp[i].getRight() == NULL) {

		}
		else {
			std::cout << "Problem with node: " << i << std::endl;
		}
	}
//___________________________________________________________________________________________________________________________________________________________________________________ATTEMPT END*/
}