#include "IntList.h"
#include <iostream>

// INITIALIZES AN EMPTY LIST W/ DUMMY HEAD AND DUMMY TAIL
IntList::IntList() {
	dummyHead = 0;
	dummyTail = 0;
}

// DEALLOCATES ALL REMAINING DYNAMICALLY ALLOCATED MEMORY (ALL REMAINING INTNODES)
IntList::~IntList() {
	while (dummyHead != 0) {
		pop_front();
	}
}

//INSERTS A DATA VALUE (WITHIN A NEW NODE) AT THE FRONT END OF THE LIST
void IntList::push_front(int value) {
	IntNode* temp = new IntNode(value);
	if (dummyHead == 0) {
		dummyHead = temp;
		dummyTail = temp;
	}

	else {
		temp->next = dummyHead;
		dummyHead->prev = temp;
		dummyHead = temp;
	}
}

void IntList::pop_front() {
	if(dummyHead != 0) {
    	IntNode* temp = dummyHead;
        dummyHead = dummyHead->next;
        if(dummyHead != 0) {
            dummyHead->prev = 0;
         }

        else {
            dummyTail = 0;
        }
        delete temp;
    }
}

void IntList::push_back(int value) {
	IntNode* temp = new IntNode(value);
	if(dummyTail == 0) {
		dummyHead = temp;
		dummyTail = temp;
	}
	else {
		dummyTail->next = temp;
		temp->prev = dummyTail;
		dummyTail = temp;
	}

}

//REMOVES THE NODE AT THE BACK END OF THE LIST (THE NODE BEFORE THE DUMMY TAIL)
//DOES NOTHING IF LIST IS ALR EMPTY, MUST BE O(1) OPERATION
void IntList::pop_back() {
	if (!empty()) {
		IntNode* temp = dummyTail;

		if (dummyTail == dummyHead) {
			delete temp;
			dummyHead = 0;
			dummyTail = 0;
		}

		else {
			dummyTail = dummyTail->prev;
			dummyTail->next = 0;
			delete temp;
		}
	}
}

// RETURNS TRUE IF THE LIST DOES NOT STORE ANY DATA VALUES (ONLY HAS DUMMY)
bool IntList::empty() const {
	if (dummyHead == 0 && dummyTail == 0) {
		return true;
	}

	else {
		return false;
	}
}

// GLOBAL FRIEND FUNC, OUTPUTS TO THE STREAM ALL OF THE INT VALUES WITHIN
// THE LIST ON A SINGLE LINE, EA. SEPARATED BY A SPACE. NO SPACE/NEWLINE AT END
ostream & operator<<(ostream &out, const IntList &rhs) {
	IntNode *info = rhs.dummyHead;
	while (info != 0) {
		out << info->data;
			if (info->next != 0) {
				out << ' ';
			}
		info = info->next;
	}
	return out;
}

// PRINTS TO SINGLE LINE ALL INT VALS STORED IN LIST IN REVERSE, NO SPACE/NEWLINE AT END
void IntList::printReverse() const {
	for (IntNode *temp = dummyTail; temp != 0; temp = temp->prev) {
		cout << temp->data;
		if(temp->prev != 0) {
			cout << " ";
		}
	}
}













