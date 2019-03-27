#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void preOrder();
  void inOrder();
  void postOrder();
  void insert(const string & word);
  void remove(const string & word);
  bool search (const string & word);

private:
  void preOrder(Node* curr);
  void inOrder(Node* curr);
  void postOrder(Node* curr);
  void insert(Node* n, const string & word);
  Node* split(Node* toSplit, const string & word);
  Node* search (Node* curr, const string & word);
  Node* searchIns(Node* curr, const string & word);
};
#endif

