#include "Heap.h"
#include <iostream>
#include <algorithm>
using namespace std;

Heap::Heap() {
	numItems = 0;
}

void Heap::enqueue(PrintJob *item) {
	if(numItems < MAX_HEAP_SIZE) {
		arr[numItems] = item;
		trickleUp(numItems);
		numItems++;
	}
}

void Heap::dequeue() {
	if(numItems == 1) {
		arr[0] = 0;
		numItems = 0;
		return;
	}
	if(numItems > 1) {
		arr[0] = arr[numItems-1];
		arr[numItems-1] = 0;
		numItems--;
		trickleDown(0);
	}
}

PrintJob* Heap::highest() {
	if(numItems == 0) {
        return 0;
    }
    return arr[0];
}

void Heap::print() {
	if(numItems == 0) {
        return;
    }
    else {
        cout << "Priority: " << highest()->getPriority();
        cout << ", Job Number: " << highest()->getJobNumber();
        cout << ", Number of Pages: " << highest()->getPages() << endl;
    }
    return;
}

void Heap::trickleDown(int val) {
	for(int j = 0; j < numItems; j++) {
		if(arr[val]->getPriority() < arr[j]->getPriority())
        {
            PrintJob* temp = arr[val];
            arr[val] = arr[j];
            arr[j] = temp;
        }
	}	
}

void Heap::trickleUp(int val) {
	while(val >= 1 && arr[val]->getPriority() > arr[(val-2)/2]->getPriority()) {
         swap(arr[val], arr[(val-1)/2]);
         val = (val-1)/2;
    }
}