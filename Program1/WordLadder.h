#ifndef _WORDLADDER_H_
#define _WORDLADDER_H_

#include <string>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class WordLadder {

  private:
    list<string> dict;        //list of possible words in ladder
    
    bool wordCheck(string, string);
    void outputToFile(stack<string>, ofstream &);
  public:
    /* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
    WordLadder(const string &);

    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
    void outputLadder(const string &start, const string &end, const string &outputFile);
};

#endif