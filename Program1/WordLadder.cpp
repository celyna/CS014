#include "WordLadder.h"
#include <iostream>
#include <list>
#include <fstream>
#include <ostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <deque>

WordLadder::WordLadder(const string &inputFile){
    ifstream inFS;
    
    inFS.open(inputFile.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening input file." << endl;
    }

    else {
        string dictWord;
        while(!inFS.eof()) {
            inFS >> dictWord;
            if(dictWord.length() != 5) {
                cout << "Error: Word must have 5 characters." << endl;
                
                return;
            }
            dict.push_back(dictWord);
        }
        inFS.close();
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;
    outFS.open(outputFile.c_str());
    if (!outFS.is_open()) {
        cout << "Opening output file failed." << endl;
    }
 
    queue<stack<string> > initialQueue;
    stack<string> initialStack;
    string word;
    list<string>::iterator diction;
    bool startPos = false; 
    bool endPos = false;
  
    for (diction=dict.begin(); diction!=dict.end(); ++diction) {
        if (*diction == start) {
            startPos = true;
        }
        if (*diction == end) {
            endPos = true;
        }
    }
    if (!startPos || !endPos) {
        cout << "Not found in the dictionary." << endl;
        return;
    }
    if (start == end) {
        outFS<< start;
        outFS.close();
        return;    
    }

    initialStack.push(start);
    initialQueue.push(initialStack);

    dict.remove(start);
    while(!initialQueue.empty()) {
      
        word = initialQueue.front().top();
        for (diction=dict.begin();diction!=dict.end();++diction) {
           
            if (wordCheck(word,*diction)) {
                stack<string> copyStack = initialQueue.front();
                copyStack.push(*diction);
                
                if(*diction == end){
                    outputToFile(copyStack, outFS);
                    return;
                }
                initialQueue.push(copyStack);
                diction = dict.erase(diction);
             
                diction--;
            }
        }
        initialQueue.pop();
    }

    if (outFS.is_open()) {
        outFS << "No Word Ladder Found.";
    
    }
}

bool WordLadder::wordCheck(string word, string dictionaryWord) {
    int character = 0;
    for (int i=0; i<5; i++) {
        if (word[i] == dictionaryWord[i]) { 
            character++; 
            }
        }
    if (character == 4) {
        return true;
    } else {
        return false;
    }
}

void WordLadder::outputToFile(stack<string> stack, ofstream &outFS) {
  
    int i = 0;
    vector<string> ladder;
    

    while (!stack.empty()) {
        ladder.push_back(stack.top());
        stack.pop();
        i++;
    }
  
    if (outFS.is_open()) {
        while (i!=0) {
            i--;
            outFS << ladder.at(i);
     
            if (i != 0) {
                outFS << " ";
                
            }
        }
       
    }
   
  
}
