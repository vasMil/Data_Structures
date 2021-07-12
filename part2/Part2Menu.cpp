#include "Part2Header.h"
#include "node.h"
#include "BST.h"
#include "Hash.h"

void Amenu(std::vector<node>& inp) {
	int Achoice;
	std::string str;
	float newTemp;
	bool backToMain = 0;
	BST bst(inp);

	do {
		std::cout << "____________MENU__________" << std::endl;
		std::cout << "1. Show inorder traversal" << std::endl;
		std::cout << "2. Search for a day" << std::endl;
		std::cout << "3. Change average temperature value in a day" << std::endl;
		std::cout << "4. Delete an entry (node)" << std::endl;
		std::cout << "5. Print the tree" << std::endl;
		std::cout << "6. Print the tree, but really you do most of the job" << std::endl;
		std::cout << "7. Go back" << std::endl;
		std::cin >> Achoice;
		switch (Achoice) {
		case 1:
			std::cout << std::endl;
			bst.InOrderTraversal();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Give date (Format: 2014-XX-XX || 2014XXXX)" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			std::cout << std::endl;
			bst.searchTree(dateFix(str))->printNode();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Give date (Format: 2014-XX-XX || 2014XXXX)" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			std::cout << "New value you want to store:" << std::endl;
			std::cin >> newTemp;
			bst.changeTemp(bst.searchTree(dateFix(str)), newTemp);
			break;
		case 4:
			std::cout << "Give date (Format: 2014-XX-XX || 2014XXXX)" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			bst.deleteNode(bst.searchTree(dateFix(str)));
			break;
		case 5:
			bst.printTree();
			break;
		case 6:
			bst.createDOTfile();
			std::cout << "In the project folder there should now be a new file \"myFile.txt\" , which in reality should have been a .dot file that can be compiled into a graph (ex. png format)" << std::endl;
			std::cout << "You can use: \"https://dreampuf.github.io/GraphvizOnline/\" , in order to compile it and see the graph for yourself. It is by no means perfect or maybe even on the right direction." << std::endl;
			std::cout << "The plan was to have it being rendered on the background via graphviz (or cgraph for c++) and use the windows to open that file. -> It failed miserably XD" << std::endl;
			break;
		case 7:
			backToMain = 1;
			break;
		default:
			std::cout << "That is not a valid input! Try Again!" << std::endl;
		}
	} while (!backToMain);
}


void Bmenu(std::vector<node> &inp) {
	int Bchoice;
	bool backToMain = 0;
	BST bst(inp, "Temperature");
	do{
		std::cout << "_____________________MENU____________________" << std::endl;
		std::cout << "1. Get the day with the minimum temperature" << std::endl;
		std::cout << "2. Get the day with the maximum temperature" << std::endl;
		std::cout << "3. Go back" << std::endl;
		std::cin >> Bchoice;

		switch (Bchoice) {
		case 1:
			bst.getMin();
			break;
		case 2:
			bst.getMax();
			break;
		case 3:
			backToMain = 1;
			break;
		default:
			std::cout << "This is not a valid input! Try again!" << std::endl;
		}
	} while (!backToMain);

}

void Cmenu(std::vector<node>& inp) {
	Hash table(inp);
	int Cchoice;
	bool backToMain = 0;
	std::string str;
	float newtemp;
	do {
		std::cout << "____________MENU__________" << std::endl;
		std::cout << "1. Search the hash table" << std::endl;
		std::cout << "2. Change the temperature of a given date" << std::endl;
		std::cout << "3. Remove a day" << std::endl;
		std::cout << "4. Print the hash_table" << std::endl;
		std::cout << "5. Go back" << std::endl;
		std::cin >> Cchoice;

		switch (Cchoice) {
		case 1:
			std::cout << "Enter the day you wanna search for:" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			std::cout << std::endl;
			table.HashSearch(dateFix(str))->printNode();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Enter the day you wanna change the temperature measurment:" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			std::cout << "What should the new value be?" << std::endl;
			std::cin >> newtemp;
			table.changeTemp(dateFix(str), newtemp);
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Enter the day I should remove from the hash-table:" << std::endl;
			std::cin.ignore();
			getline(std::cin, str);
			table.deleteHashNode(dateFix(str));
			break;
		case 4:
			std::cout << std::endl;
			table.PrintHashTable();
			std::cout << std::endl;
			break;
		case 5:
			backToMain = 1;
			break;
		default:
			std::cout << "This is not a valid input! Try again!" << std::endl;
		}
	} while (!backToMain);
}

void TreeMenu(std::vector<node>& inp) {
	int Tchoice;
	do {
		std::cout << "____________________________MENU_________________________" << std::endl;
		std::cout << "1. Load with day being the key of each node" << std::endl;
		std::cout << "2. Load with temperature being the key of each node" << std::endl;
		std::cin >> Tchoice;

		switch (Tchoice) {
		case 1:
			std::cout << std::endl;
			Amenu(inp);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			Bmenu(inp);
			std::cout << std::endl;
			break;
		default:
			std::cout << "This is not a valid input! Try again!" << std::endl;
			std::cout << std::endl;
		}
	} while (Tchoice != 1 && Tchoice != 2);
}

void MainMenu(std::vector<node>& inp) {
	bool exit = 0;
	int choice;
	do {
		std::cout << "_________________________MAIN MENU_____________________" << std::endl;
		std::cout << "1. Create BST" << std::endl;
		std::cout << "2. Create a hashing table" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			TreeMenu(inp);
			break;
		case 2:
			Cmenu(inp);
			break;
		case 3:
			exit = 1;
			break;
		default:
			std::cout << "This is not a valid input! Try again!" << std::endl;
		}
	} while (!exit);
}