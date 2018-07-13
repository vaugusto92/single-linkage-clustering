#include "Node.hpp"

using namespace std;

/**
 * Constructor.
 */
Node::Node() {
    this->value = -1;
    this->rank = 0;
    this->parent = this;
}

/**
 *  Overloaded Constructor.
 */
Node::Node(int value) {
    this->value = value;
    this->rank = 0;
    this->parent = this;
}

/**
 * Destructor.
 */
Node::~Node() {
    delete this;
}

/**
 * Access methods.
 */

void Node::setValue(int value) {
    this->value = value;
}

int Node::getValue() {
    return this->value;
}

void Node::setRank(int rank) {
    this->rank = rank;
}

int Node::getRank() {
    return this->rank;
}

void Node::setParent(Node *p) {
    this->parent = p;
}

Node* Node::getParent() {
    return this->parent;
}