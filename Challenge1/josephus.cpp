//I worked with Phyllis.
#include "Josephus.h"

#include <iostream>
using namespace std;

void Josephus::final(int ppl, int deport)
{	
	curr = new Node();
	int person = 1;
	curr->value = 1;
	
	Node *temp = curr;
	
	for (int i = 2; i <= ppl; i++) {
		curr->next = new Node();
		curr->next->prev = curr;
		curr = curr->next;
		curr->value = i;
	}
	
	curr->next = temp;
	curr->next->prev = curr;
	curr = curr->next;

	while (curr->next != curr)
	{
		if (person == deport + 1) {
			
			cout << "Deported: Person #" << curr->value << endl;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			Node *next = curr->prev->next;
			
			delete(curr);
			curr = next;
			person = 1;
		}
		else {
			curr = curr->next;
			person++;
		}
	}
	
	cout << "Last person on island: Person #" << curr->value << endl;
	delete(curr);
}