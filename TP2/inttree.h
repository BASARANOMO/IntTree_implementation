// @Author: ZHANG Mofan
// @Edit time: 10/07/2020
//             10/10/2020
//             10/11/2020


#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <errno.h>
using namespace std;

/// Node of a tree containing an integer at each node
class IntTree {
    int data; ///< Node information
    std::vector<IntTree*> sons; ///< Sequence of sons (empty if none)
public:
    IntTree(int d); ///< Create a node with given information
    ~IntTree();     ///< Destruct a node and all its descendants

    int getData() const; ///< Return information of this node
    void setData(int d); ///< Set information of this node

    int nbSons() const; ///< Return the number of sons of this node

    void setSon(int pos, IntTree* newSon); ///< Replace son at pos with newSon
    IntTree* getSon(int pos); ///< Son at pos (left-most son at position 0)
    const IntTree* getSon(int pos) const; ///< See non-const overload

    void addAsLastSon(IntTree* newSon); ///< Add newSon as right-most son
    void removeLastSon(); ///< Remove right-most son of this node

    void display(string prefix = "", string indent = "  ");

    //bonus Exercice 5
    // depth first search (profondeur d'abord)
    void recursivePreOrder();  // similar to display()
    vector<int> recursivePreOrderVec();
    void iterativePreOrder();  // using stack
    vector<int> iterativePreOrderVec();
    void recursivePostOrder();
    vector<int> recursivePostOrderVec();
    void iterativePostOrder();  // two stacks version
    vector<int> iterativePostOrderVec();
    
    // breadth first search (largeur d'abord)
    void iterativeBFS();  // using queue
    vector<int> iterativeBFSVec();

    // max tree depth
    int maxDepth();  // time complexicity: O(N); space complexicity: O(1)

    // min tree depth
    int minDepth();  // BFS (largeur d'abord)
};
