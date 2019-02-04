#ifndef _NODE_H_
#define _NODE_H_

#include <string>
using namespace std;

class Node {
	friend class BSTree;
private:
	string dataString;
	int count;
	Node* left;
	Node* right;
	Node* parent;
public:
	Node(string);
	Node& operator=(const Node&data);
};

#endif