#ifndef __NODE_H
#define __NODE_H

#include <string>

using namespace std;

class Node {

  friend class AVLTree;

private:
  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

  Node() : small(""), large(""), left(0), middle(0), right(0), parent(0) {}
  Node(const string &small): small(small), large(""), left(0), middle(0), right(0), parent(0) {}
  // Add additional functions/variables here. Remember, you may not add any
  // Node * or string variables.

};

#endif
