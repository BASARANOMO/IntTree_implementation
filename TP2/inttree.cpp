// @Author: ZHANG Mofan
// @Edit time: 10/07/2020
//             10/10/2020
//             10/11/2020


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

vector<int> IntTree::recursivePreOrderVec() {
	vector<int> vec;
	vec.push_back(data);
	int nbrSons = nbSons();
	if (nbrSons > 0) {
		for (int i = 0; i < nbrSons; i++) {
			vector<int> vec2 = getSon(i)->recursivePreOrderVec();
			vec.insert(vec.end(), vec2.begin(), vec2.end());
		}
	}
	return vec;
}

void IntTree::iterativePreOrder() {
	stack<IntTree*> nodeStk;
	nodeStk.push(this);
	while (!nodeStk.empty()) {
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

vector<int> IntTree::iterativePreOrderVec() {
	vector<int> vec;
	stack<IntTree*> nodeStk;
	nodeStk.push(this);
	while (!nodeStk.empty()) {
		IntTree* node = nodeStk.top();
		vec.push_back(node->getData());
		nodeStk.pop();

		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				nodeStk.push(node->getSon(nbrSons - i - 1));
			}
		}
	}
	return vec;
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

vector<int> IntTree::recursivePostOrderVec() {
	vector<int> vec;
	int nbrSons = nbSons();
	if (nbrSons > 0) {
		for (int i = 0; i < nbrSons; i++) {
			vector<int> vec2 = getSon(i)->recursivePostOrderVec();
			vec.insert(vec.end(), vec2.begin(), vec2.end());
		}
	}
	vec.push_back(data);
	return vec;
}

void IntTree::iterativePostOrder() {
	stack<IntTree*> nodeStk1;
	stack<IntTree*> nodeStk2;
	nodeStk1.push(this);
	while (!nodeStk1.empty()) {
		IntTree* node = nodeStk1.top();
		nodeStk1.pop();
		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				nodeStk1.push(node->getSon(i));
			}
		}
		nodeStk2.push(node);
	}
	while (!nodeStk2.empty()) {
		cout << nodeStk2.top()->getData() << " ";
		nodeStk2.pop();
	}
}

vector<int> IntTree::iterativePostOrderVec() {
	vector<int> vec;
	stack<IntTree*> nodeStk1;
	stack<IntTree*> nodeStk2;
	nodeStk1.push(this);
	while (!nodeStk1.empty()) {
		IntTree* node = nodeStk1.top();
		nodeStk1.pop();
		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				nodeStk1.push(node->getSon(i));
			}
		}
		nodeStk2.push(node);
	}
	while (!nodeStk2.empty()) {
		vec.push_back(nodeStk2.top()->getData());
		nodeStk2.pop();
	}
	return vec;
}

void IntTree::iterativeBFS() {
	queue<IntTree*> q;
	q.push(this);
	while (!q.empty()) {
		IntTree* node = q.front();
		cout << node->getData() << " ";
		q.pop();
		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				q.push(node->getSon(i));
			}
		}
	}
}

vector<int> IntTree::iterativeBFSVec() {
	vector<int> vec;
	queue<IntTree*> q;
	q.push(this);
	while (!q.empty()) {
		IntTree* node = q.front();
		vec.push_back(node->getData());
		q.pop();
		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				q.push(node->getSon(i));
			}
		}
	}
	return vec;
}

int IntTree::maxDepth() {
	int maxDepth = 0;
	if (nbSons() > 0) {
		for (int i = 0; i < nbSons(); i++) {
			maxDepth = max(maxDepth, getSon(i)->maxDepth());
		}
	}
	return maxDepth + 1;
}

int IntTree::minDepth() {
	queue<IntTree*> q;
	queue<int> qDepth;
	q.push(this);
	qDepth.push(1);
	while (!q.empty()) {
		IntTree* node = q.front();
		int depth = qDepth.front();
		q.pop();
		qDepth.pop();

		int nbrSons = node->nbSons();
		if (nbrSons > 0) {
			for (int i = 0; i < nbrSons; i++) {
				q.push(node->getSon(i));
				qDepth.push(depth + 1);
			}
		}
		else {
			return depth;
		}
	}
}