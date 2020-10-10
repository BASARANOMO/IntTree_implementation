#include "inttree.h"
#include <vector>

IntTree::IntTree(int d) {
	data = d;
	sons.clear();
}

IntTree::~IntTree() {
	int depth = sons.size();
	if (depth > 0) {
		for (int i = 0; i < depth; i++) {
			if (sons[i])
				delete sons[i];
		}
	}
}

