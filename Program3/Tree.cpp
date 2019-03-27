#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree() : root(0) {}
Tree::~Tree( ) {
    
}
//test 1-7 is search and insert and ordering and search
//test 8-15 remove and insert and print //simplier version 
void Tree::insert(const string &word) {
    //maybe have a check for word already there
    insert(root, word);
}

void Tree::insert(Node* in ,const string &word) {
    Node *left = 0;
    Node *leftmid = 0;
    Node *rightmid = 0;
    Node *right = 0;
    if (in == 0) { // root is 0 (meaning nothing there)
        root = new Node(word);
    }
    else if (word < in->small )  {// if word is smaller
        if (in->left == 0) { //empty left
            if (in->small != "" && in->large == "") { // if there is an empty large (so you can insert here/no split)
                in->large = in->small;
                in->small = word;
            }
            else { //have to split because no choice
                split(in, word, left, leftmid, rightmid, right);
            }
        }
        else { //if left is not a new and empty root, insert and since its recursive it will go through
            insert(in, word);
        }
    }
    else if (word > in->small && in->large == "") { //saying that word is greater than samll and large is empty
        in->large = word;
    }
    else if (word > in->small && word < in->large) { //in the middle
        if (in->middle == 0) {
            split(in, word, left, leftmid, rightmid, right);
        }
        else {
            insert(in->middle, word);
        }
    }
    else if (in->large != "" && in->right == 0) { //you have full large but no right
        if (in->right == 0) {
            insert(in->right, word);
        }
        else {
            insert(in->right, word);
        }
    }
    else if (in->large != "" && in->right != 0) { //if large is full but right side isnt, insert to the right
        insert(in->right, word);
    }
}

void Tree::split(Node* n, Node *other, const string &s, string where) {
    bool setRoot = false;
    Node *p, *n1, *n2, *n3, *temp;
    temp = new Node("");
    
    if(n->small == root->small)
    {
        p = new Node("");
        setRoot = true;
    }
    else
    {
        p = n->parent;
    }
    
    
    if(s < n->small)
    {
        n1 = new Node(s);
        n2 = new Node(n->small);
        n3 = new Node(n->large);
    }
    else if(s > n->small && s < n->large)
    {
        n1 = new Node(n->small);
        n2 = new Node(s);
        n3 = new Node(n->large);
    }
    else
    {
        n1 = new Node(n->small);
        n2 = new Node(n->large);
        n3 = new Node(s);
    }
    n->parent = 0;
    n1->parent = p;
    n3->parent = p;
    if(n->left != 0)
    {
        if(where == "left")
        {
                n1->left = other->left;
                other->left->parent = n1;
                n1->right = other->right;
                other->right->parent = n1;
                n3->left = n->middle;
                n->middle->parent = n3;
                n3->right = n->right;
                n->right->parent = n3;
        }
        else if(where == "middle")
        {
                n1->left = n->left;
                n->left->parent = n1;
                n1->right = other->left;
                other->left->parent = n1;
                n3->left = other->right;
                other->right->parent = n3;
                n3->right = n->right;
                n->right->parent = n3;
        }
        else if(where == "right")
        {
                n1->left = n->left;
                n->left->parent = n1;
                n1->right = n->middle;
                n->middle->parent = n1;
                n3->left = other->left;
                other->left->parent = n3;
                n3->right = other->right;
                other->right->parent = n3;
        }
        else 
        {
                cout << "hey this did NOT work fam" << endl;
        }
        
        
    }
    temp->left = n1;
    temp->right = n3;
    string x = n2->small;
    if(p->hasLarge())
    {
        split(p, temp, x, where);
    }
    else
    {
        if(p->small == "")
        {
            p->small = x;
        }
        else if(x < p->small)
        {
            p->large = p->small;
            p->small = x;
        }
        else
        {
            p->large = x;
        }
    }
    
    if(p->left == 0)
    {
            p->left = temp->left;
            p->right = temp->right;
    }
    else if(p->left->small == n->small)
    {

        p->left = temp->left;
        p->middle = temp->right;
    }
    else if(p->right->small == n->small)
    {

        p->middle = temp->left;
        p->right = temp->right;
    }
    
    
    if(setRoot)
    {
        p->left = n1;
        p->right = n3;
        root = p;
    }   
}
void Tree::remove(const string &s) {
    Node* n = search(root, s);
        
        Node *successor, *leafNode;
        if(n)
        {
                if(n->left != 0)
                {
                        if(n->small == s && !n->hasLarge())
                        {
                                successor = inOrderSuccessorSmall(n->right);
                        }
                        else if(n->small == s && n->hasLarge())
                        {
                                successor = inOrderSuccessorSmall(n->middle);
                        }
                        else
                        {
                                successor = inOrderSuccessorSmall(n->right);
                        }
                        
                        string temp = successor->small;
                        if(n->small == s)
                        {
                                successor->small = n->small;
                                n->small = temp;
                        }
                        else 
                        {
                                successor->small = n->large;
                                n->large = temp;
                        }
                        leafNode = successor;
                        
                }
                else
                {
                     leafNode = n;   
                }
                bool leafIsGone = false;
                
                if(s == leafNode->small)
                {

                        if(leafNode->large != "")
                        {
                                string temp1 = leafNode->large;
                                leafNode->small = temp1;
                                leafNode->large = "";
                        }
                        else
                        {
                                leafNode->small = "";
                                leafIsGone = true;
                        }
                }
                else 
                {
                        // cout << "AWWWW" << endl;
                        // cout << leafNode->large << endl;
                        leafNode->large = "";
                }
                
                if(leafIsGone)
                {
                        fix(leafNode);
                }
        }
}








bool Tree::search(const string &word) const {
    return search(root, word);
}

bool Tree::search(Node* curr, const string &word) const {
    if (curr) { //meaning not end of tree/ curr == 0
        if (curr->small == word || curr->large == word) {
            return true;
        }
        else {
            if (word < curr->small) {
                return search(curr->left, word);
            }
            else if (word > curr->large) {
                return search(curr->right, word);
            }
            else {
                return search(curr->middle, word);
            }
        }
    }
    else {
        return false;
    }
}

void Tree::preOrder(Node* root) const {
    if (root == 0) {
        return;
    }
    cout << root->small << " "; //not sure
    cout << root->large << " "; //not sure
    preOrder(root->left);
    preOrder(root->middle);
    preOrder(root->right);
}
void Tree::preOrder( ) const {
    preOrder(root);
    cout << endl;
}

void Tree::inOrder(Node* root) const {
    if (root == 0) {
        return;
    }
    inOrder(root->left);
    cout << root->small << " ";
    inOrder(root->middle);
    cout << root->large << " ";
    inOrder(root->right);
}  
void Tree::inOrder( ) const {
    inOrder(root);
    cout << endl;    
}

void Tree::postOrder(Node* root) const {
    if (root == 0) {
        return;
    }    
    postOrder(root->left);
    postOrder(root->middle);
    postOrder(root->right);
    cout << root->small << " "; //not sure
    cout << root->large << " "; //not sure
    
}  
void Tree::postOrder( ) const {
    postOrder(root);
    cout << endl;    
}
