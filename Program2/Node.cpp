#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

Node::Node(string data) {
	dataString = data;
	count = 1;
	left = 0;
	right = 0;
	parent = 0;
}

Node& Node::operator=(const Node& data)
{
    if(this != &data)
    {
        this->dataString = data.dataString;
        this->count = data.count;
    }
    
    return *this;
}

