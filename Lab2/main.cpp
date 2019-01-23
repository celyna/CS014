#include "IntList.h"
#include <iostream>
using namespace std;

int main() {
	IntList Sample;

	cout << "IntList push_front() called with value of 4" << endl;
	Sample.push_front(4);
	cout << Sample << endl;

	cout << "IntList push_back() called with value of 2" << endl;
	Sample.push_back(2);
	cout << Sample << endl;

	cout << "IntList push_back() called with value of 3" << endl;
	Sample.push_back(3);
	cout << Sample << endl;

	cout << "IntList push_front() called with value of 4" << endl;
	Sample.push_front(2);
	cout << Sample << endl;

	cout << "IntList pop_back() called" << endl;
	Sample.pop_back();
	cout << Sample << endl;

	cout << "IntList pop_front() called" << endl;
	Sample.pop_front();
	cout << Sample << endl;

	cout << "IntList printReverse() called" << endl;
	Sample.printReverse();
	cout << endl;

	return 0;
}