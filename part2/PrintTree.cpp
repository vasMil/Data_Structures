#include "Part2Header.h"
#include "node.h"
#include "BST.h"

//Source of the algorithm: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/

void BST::printTree(node* root, int space){
    int const COUNT = 10;

    if (root == NULL){
        return;
    }

    space += COUNT;

    printTree(root->getRight(), space);

    std::cout << std::endl;  
    for (int i = COUNT; i < space; i++)  
        std::cout << " ";  
    std::cout << root->getDay() << "\n";

    printTree(root->getLeft(), space);

}

void BST::createDOTfile(node* root) {
    std::fstream out;
    if (!out.is_open()) {
        out.open("myFile.txt", std::ios::out);

        out << "digraph G {\nnodesep = 1.4;\nranksep = 1.5;\n" << std::endl;
    }
    Traverse(root, out);

    out << "\n}";
    out.close();

}
void BST::Traverse(node* root, std::fstream &dotfile) {
    if (root == NULL) {

        return;
    }

    Traverse(root->getLeft(), dotfile);

    if (root->getParent() != NULL) {
        dotfile << root->getParent()->getDay() << " -> " << root->getDay() << std::endl;
    }

    Traverse(root->getRight(), dotfile);
}

void BST::createDOTfile() {
    createDOTfile(this->root);
}

