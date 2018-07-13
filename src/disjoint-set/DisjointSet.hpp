#ifndef _INC_DISJOINTSET_H
#define _INC_DISJOINTSET_H

#include "Node.hpp"
#include <unordered_map>
#include <vector>

using namespace std;

/**
 *  Class that represents an disjoint set.
 */
class DisjointSet {

    private:
    
        unordered_map<int, Node*>* forest;
        Node* findSet(Node *x);

    public:

        DisjointSet();
        ~DisjointSet();

        void makeSet(int value);
        int findSet(int id);
        void _union(int x, int y);
        void link(Node *x, Node *y);
};

#endif
