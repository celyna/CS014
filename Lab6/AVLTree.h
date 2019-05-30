#include "Node.h" 
#include <iostream> 
#include <string> 
#include <fstream> 
#include <sstream> 
#include <cstdlib>

using namespace std; 

class AVLTree { 
    private:
      Node *root;
      
    public:
      AVLTree();
      void insert(const string &); 
      int balanceFactor(Node*) const;  
      void printBalanceFactors() const;  
      void visualizeTree(const string &);  
      
    private: 
      void rotate(Node *); 
      void rotateLeft(Node *); 
      void rotateRight(Node *);  
      void insert(Node *,Node *);
      void printBalanceFactors(Node *) const;
      void visualizeTree(ofstream &, Node *);  
      int height(Node *) const;
      void height(int, int &, Node *) const;  
      void setChild(Node *, string, Node *); 
      void replaceChild(Node *, Node *,Node *);
};