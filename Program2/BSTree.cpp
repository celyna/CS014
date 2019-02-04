#include <iostream>
#include <string>
#include "BSTree.h"
#include "Node.h"

BSTree::BSTree() {
	root = 0;
}

Node* BSTree::search(const string &data, Node* curr) const {
    if(curr != 0) {
        if(data == curr->dataString) {
            return curr;
        }
        else {
            if(data < curr->dataString) {
                return search(data, curr->left);
            }
            else {
                return search(data, curr->right);
            }
        }
    }
    else {
        return 0;
    }
}

void BSTree::inOrder(Node *curr) const {
	if(curr != 0) {
		inOrder(curr->left);
		cout << curr->dataString << '(' << curr->count << "), ";
		inOrder(curr->right);
	}
}

void BSTree::postOrder(Node *curr) const {
	if(curr != 0) {
		postOrder(curr->left);
		postOrder(curr->right);
		cout << curr->dataString << '(' << curr->count << "), ";
	}
}

void BSTree::preOrder(Node *curr) const {
	if(curr != 0) {
		cout << curr->dataString << '(' << curr->count << "), ";
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void BSTree::remove(Node *data) {
	Node *curr = data;
	Node *succ = 0;

	if(curr->left == 0 && curr->right == 0) {
		if(curr->parent != 0) {
			if(curr->parent->left == curr) {
				curr->parent->left = 0;
			}
			else {
				curr->parent->right = 0;
			}
		}
		else {
			root = 0;
		}
		delete curr;
	}
	else if(curr->left != 0) {
		succ = curr->left;
		while(succ->right != 0) {
			succ = succ->right;
		}
		*curr = *succ;
		remove(succ);
	}
	else {
		succ = curr->right;
		while(succ->left != 0) {
			succ = succ->left;
		}
		*curr = *succ;
		remove(succ);
	}
}

void BSTree::insert(const string &data) {
	Node *curr = root;
	if(search(data)) {
		curr = search(data, root);
		curr->count = curr->count + 1;
	}
	else {
		Node *newNode = new Node(data);
		if(root == 0) {
			root = newNode;
		}
		else {
			while(1) {
				if(data < curr->dataString) {
					if(curr->left == 0) {
						curr->left = newNode;
						newNode->parent = curr;

						return;
					}
					else {
						curr = curr->left;
					}
				}
				else {
					if(curr->right == 0) {
						curr->right = newNode;
						newNode->parent = curr;
						return;
					}
				else {
					curr = curr->right;
				}
				}
			}
		}
	}
}

bool BSTree::search(const string& data) const {
	return search(data, root);
}

string BSTree::largest() const {
	Node* curr = root;
	if(curr == 0) {
		return "";
	}
	else {
		while(1) {
			if(curr->right == 0) {
				return curr->dataString;
			}
			else {
				curr = curr->right;
			}
		}
	}
}

string BSTree::smallest() const {
    Node* curr = root;
    
    if(curr == 0) {
        return "";
    }
    else {
        while(1) {
            if(curr->left == 0) {
                return curr->dataString;
            }
            else {
                curr = curr->left;
            }
        }
    }
}

int BSTree::height(const string &data) const {
    if(!search(data)) {
        return -1;
    }
    Node *curr = search(data, root);
    Node *currLeft = curr;
    Node *currRight = curr;
    int leftCnt = 0;
    int rightCnt = 0;
    
    if(curr->left != 0) {
        currLeft = currLeft->left;
        leftCnt++;
        leftCnt = leftCnt + height(currLeft->dataString);
    }
    if(curr->right != 0) {
        currRight = currRight->right;
        rightCnt++;
        rightCnt = rightCnt + height(currRight->dataString);
    }
    if(leftCnt >= rightCnt) {
        return leftCnt;
    }
    else {
        return rightCnt;
    }
}

void BSTree::remove(const string &data) {
    if(search(data)) {
        Node *curr = search(data, root);
        
        if(curr->count > 1) {
            curr->count = curr->count - 1;
        }
        else {
            remove(curr);
        }
    }
}

void BSTree::preOrder() const {
	preOrder(root);
	cout << endl;
}

void BSTree::inOrder() const {
	inOrder(root);
	cout << endl;
}

void BSTree::postOrder() const {
	postOrder(root);
	cout << endl;
}





















