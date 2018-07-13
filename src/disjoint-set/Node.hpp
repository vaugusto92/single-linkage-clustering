#ifndef _INC_NODE_H
#define _INC_NODE_H

#include <list>

using namespace std;

class Node {

    private:

        int value;
        int rank;
        Node *parent;

    public:

        Node();
        Node(int value);
        virtual ~Node();

        void setValue(int value);
        int getValue();

        void setRank(int rank);
        int getRank();

        void setParent(Node *p);
        Node* getParent();
};

#endif