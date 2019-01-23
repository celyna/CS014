//
//  main.cpp
//  LAB 3
//
//  Created by Celyna Su on 1/22/19.
//  Copyright © 2019 Celyna Su. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned int min = index;
    for (unsigned int i = index; i < vals.size(); i++) {
        if (vals.at(i) < vals.at(min)) {
            min = i;
        }
    }
    return min;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    int i, j, first, sz = vals.size();
    for (i = sz-1; i > 0; i--) {
        first = 0;
        for (j = 1; j <= i; j++) {
            if (vals.at(j) > vals.at(first)) {
                first = j;
            }
        }
        swap(vals.at(first), vals.at(i));
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){
    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch (out_of_range& excpt) {
        cout << "Out of range exception occurred." << endl;
    }
    return 0;
}

