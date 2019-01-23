#include "WordLadder.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
   string dictFile, wordBegin, wordEnd, outFile;
   cout << "Enter the name of the dictionary file: ";
   cin >> dictFile;
   cout << endl;
   cout << "Enter the name of the output file: ";
   cin >> outFile;
   cout << endl;
   cout << "Enter the first word: ";
   cin >> wordBegin;
   cout << endl;
   while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> wordEnd;
   cout << endl;
   while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
   }
   
	WordLadder wl(dictFile);
	
	wl.outputLadder(wordBegin, wordEnd, outFile);

   return 0;
}

