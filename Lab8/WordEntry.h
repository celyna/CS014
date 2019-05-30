#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

 private:
	string word;
	int numAppearances;
	int totalScore;
 public:
	WordEntry(const string &, int);
	void addNewAppearance(int);
	const string & getWord();
	double getAverage();
};
#endif
