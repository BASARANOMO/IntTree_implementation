// @Author: ZHANG Mofan
// @Edit time: 10/07/2020
//             10/10/2020
//             10/11/2020


#include "inttree.h"
#include <vector>


int main() {
	IntTree* root = new IntTree(12);
	root->addAsLastSon(new IntTree(8));
	root->getSon(0)->addAsLastSon(new IntTree(4));
	root->getSon(0)->addAsLastSon(new IntTree(9));
	root->addAsLastSon(new IntTree(23));
	root->getSon(1)->addAsLastSon(new IntTree(17));
	root->getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));
	root->display("* ");

	// bonus
	cout << endl << endl << "***************************************************" << endl;
	cout << "Test tree tranversal methods." << endl;
	cout << "Recursive pre-order: ";
	root->recursivePreOrder();
	cout << endl << "Iterative pre-order: ";
	root->iterativePreOrder();
	cout << endl << "Recursive post-order: ";
	root->recursivePostOrder();
	cout << endl << "Iterative post-order: ";
	root->iterativePostOrder();
	cout << endl << "Iterative breadth first traversal: ";
	root->iterativeBFS();
	cout << endl << "Max depth: " << root->maxDepth();
	cout << endl << "Min depth: " << root->minDepth();
	
	delete root;

	// error management
	cout << endl << endl << "***************************************************" << endl;
	cout << "Test error management." << endl;
	IntTree* root2 = new IntTree(12);

	try {
		root2->removeLastSon();
	}
	catch (const char* str) {
		cerr << str << endl;
	}

	if (!root2->getSon(-1)) {
		cerr << "NULL pointer returned. The method getSon() received an out-of-range index!" << endl;
	}
	
	root2->addAsLastSon(new IntTree(8));

	if (!root2->getSon(1)) {
		cerr << "NULL pointer returned. The method getSon() received an out-of-range index!" << endl;
	}

	try {
		cout << root2->getSon(1)->getData();
	}
	catch (const char* str) {
		cerr << str << endl;
	}

	try {
		root2->setSon(2, new IntTree(5));
	}
	catch (const char* str) {
		cerr << str << endl;
	}

	delete root2;

	return 0;
}