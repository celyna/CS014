#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
	hashTable = new list<WordEntry>[size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
	return s.size() % size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
	 if(contains(s)) {
	 	for(list<WordEntry>::iterator it=hashTable[computeHash(s)].begin(); it != hashTable[computeHash(s)].end(); ++it) {
	 		if(it->getWord() == s) {
	 			it->addNewAppearance(score);
	 		}
	 	}
	 }
	 else {
	 	WordEntry newEntry(s, score);
	 	hashTable[computeHash(s)].push_front(newEntry);
	 }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
	if(contains(s)) {
		for(list<WordEntry>::iterator it=hashTable[computeHash(s)].begin(); it != hashTable[computeHash(s)].end(); ++it) {
			if(it->getWord() == s) {
				return it->getAverage();
			}
		}
	}
	return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
	for(list<WordEntry>::iterator it=hashTable[computeHash(s)].begin(); it != hashTable[computeHash(s)].end(); ++it) {
		if(it->getWord() == s) {
			return true;
		}
	}
	return false;
}

