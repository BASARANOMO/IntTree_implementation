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