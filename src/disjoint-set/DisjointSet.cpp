#include "DisjointSet.hpp"
#include <iostream>

using namespace std;

/**
 * Constructor.
 */
DisjointSet::DisjointSet() {
    this->forest = new unordered_map<int, Node*>();
}

/**
 * Destructor.
 */
DisjointSet::~DisjointSet() {
    delete this->forest;
}

void DisjointSet::_union(int a, int b) {
    Node *x = findSet((*forest)[a]);
    Node *y = findSet((*forest)[b]);

    link(x,y);
}

void DisjointSet::link(Node *x, Node *y) {  
    if (x->getRank() > y->getRank()) {  
        y->setParent(x);  
    } else {  
        x->setParent(y);  
    }  
    
    if (x->getRank() == y->getRank()) {  
        y->setRank(y->getRank() + 1);  
    }  
}

/**
 * Make Set.
 */
void DisjointSet::makeSet(int value) {
    Node* node = new Node(value);
    this->forest->insert({value, node});
}

/**
 * Finds the representative of the set containing d
 */
int DisjointSet::findSet(int d) {
    Node* node = (*this->forest)[d];
    return findSet(node)->getValue();
}

/**
 * Finds the representative recursively
 * and does path compression as well
 */
Node* DisjointSet::findSet(Node* x) {
    if (x->getParent() != x) {
        x->setParent(findSet(x->getParent()));
    }

    return x->getParent();
}
