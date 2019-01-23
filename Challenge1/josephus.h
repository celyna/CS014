#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
	Node *prev;
};

class Josephus
{
private:
	Node* curr;
	
public:
	void final(int, int);
};

#endif