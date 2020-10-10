#include "inttree.h"

IntTree::IntTree(int d) {
	data = d;
	//std::vector<IntTree*> sons;
	sons.clear();
}

IntTree::~IntTree() {
	int nbrSons = sons.size();
	if (nbrSons > 0) {
		for (int i = 0; i < nbrSons; i++) {
			if (sons[i])
				delete sons[i];
		}
	}
}

int IntTree::getData() const {
	return data;
}

void IntTree::setData(int d) {
	data = d;
}

int IntTree::nbSons() const {
	return sons.size();
}

void IntTree::setSon(int pos, IntTree* newSon) {
	sons[pos] = newSon;
}

IntTree* IntTree::getSon(int pos) {
	return sons[pos];
}

const IntTree* IntTree::getSon(int pos) const {
	return sons[pos];
}

void IntTree::addAsLastSon(IntTree* newSon) {
	sons.push_back(newSon);
}

void IntTree::removeLastSon() {
	sons.pop_back();
}

void IntTree::display(string prefix, string indent) {
	cout << prefix << data << endl;
	int nbrSons = sons.size();
	if (nbrSons > 0) {
		prefix += indent;
		for (int i = 0; i < nbrSons; i++) {
			sons[i]->display(prefix, indent);
		}
	}
}

void IntTree::recursivePreOrder() {
	cout << data << " ";
	int nbrSons = nbSons();
	if (nbrSons > 0) {
		for (int i = 0; i < nbrSons; i++) {
			getSon(i)->recursivePreOrder();
		}
	}
}

void IntTree::iterativePreOrder() {
	stack<IntTree*> nodeStk;
	nodeStk.push(this);
	while (nodeStk.empty() == false) {
		IntTree* node = nodeStk.top();
		cout << node->getData() << " ";
		nodeStk.pop();

		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				nodeStk.push(node->getSon(nbrSons - i - 1));
			}
		}
	}
}

void IntTree::recursivePostOrder() {
	int nbrSons = nbSons();
	if (nbrSons > 0) {
		for (int i = 0; i < nbrSons; i++) {
			getSon(i)->recursivePostOrder();
		}
	}
	cout << data << " ";
}

void IntTree::iterativePostOrder() {

}