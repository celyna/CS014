#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <string>

using namespace std;

class BSTree {

private:
  Node *root;

private:
  Node * search(const string &, Node *) const;
  void inOrder(Node *) const;
  void postOrder(Node *) const;
  void preOrder(Node *) const;
  void remove(Node *);

public:
  BSTree();
  void insert(const string &);
  bool search(const string &) const;
  string largest( ) const;
  string smallest( ) const;
  int height(const string &) const;
  void remove(const string &);

  void preOrder( ) const;
  void inOrder( ) const;
  void postOrder( ) const;
};

#endif