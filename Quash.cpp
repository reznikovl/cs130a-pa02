#include "Quash.h"
#include <iostream>
#include <iterator>
using namespace std;

Quash::Quash() {
    myHash = new list<HashElement>[43];
}

void Quash::insert(int i) {
    HashElement* current = lookupAddress(i);
    if(current) {
        current->count++;
        current->otherAddress->count++;
        cout << "item successfully inserted, count = " << current->count << endl;
        return;
    }

    HeapElement* toInsert = new HeapElement(i, myHeap.size());
    myHeap.push_back(toInsert);
    HeapElement* temp = this->bubbleUp(myHeap.size()-1);

    myHash[hash(i)].push_front(HashElement(i, temp));
    cout << "item successfully inserted, count = 1" << endl;
}

void Quash::lookup(int i) {
    HashElement* check = this->lookupAddress(i);
    if(check == NULL)
        cout << "item not found" << endl;
    else
        cout << "item found, count = " << check->count << endl;
}

void Quash::deleteMin() {
    if(myHeap.empty()) {
        cout << "min item not present since table is empty" << endl;
        return;
    }

    HeapElement* min = myHeap[0];
    deleteFromHash(min->data);
    cout << "min item = " << min->data << ", ";

    if(min->count > 1) {
        min->count--;
        cout << "count decremented, new count = " << min->count << endl;
        return;
    }
    this->heapSwap(0, myHeap.size()-1);
    delete myHeap[myHeap.size()-1];
    myHeap.pop_back();
    bubbleDown(0);
    cout << "min item " << min->data << " successfuly deleted" << endl;
}

void Quash::deleteElement(int i) {
    HashElement* check = this->lookupAddress(i);
    if(check == NULL) {
        cout << "item not present in the table" << endl;
        return;
    }
    if(check->count > 1) {
        check->count--;
        check->otherAddress->count--;
        cout << "item count decremented, new count = " << check->count << endl;
        return;
    }

    HeapElement* currentHeap = check->otherAddress;
    deleteFromHash(i);

    int currPos = currentHeap->positionInArray;

    heapSwap(currPos, myHeap.size()-1);
    delete myHeap[myHeap.size()-1];
    myHeap.pop_back();

    if(currPos == 0 || myHeap[currPos]->data > myHeap[(currPos-1)/2]->data) {
        bubbleDown(currPos);
    }
    else {
        bubbleUp(currPos);
    }

    cout << "item successfully deleted" << endl;
}

void Quash::print() {
    for(vector<HeapElement*>::iterator ptr = myHeap.begin(); ptr != myHeap.end(); ptr++) {
        cout << (*ptr)->data << " ";
    }
    cout << endl;
}

int Quash::hash(int i) {
    if(i < 0)
        return i % 43 + 43;

    return i % 43;
}

HashElement* Quash::lookupAddress(int i) {
    if(myHeap.empty()) return nullptr;
    int hashIndex = hash(i);
    
    for(list<HashElement>::iterator ptr = myHash[hashIndex].begin(); ptr != myHash[hashIndex].end(); ptr++) {
        if(ptr->data == i)
            return &(*ptr);
    }
    return nullptr;
}


void Quash::deleteFromHash(int i) {
    int hashIndex = hash(i);
    for(list<HashElement>::iterator ptr = myHash[hashIndex].begin(); ptr != myHash[hashIndex].end(); ptr++) {
        if(ptr->data == i) {
            if(ptr->count > 1) {
                ptr->count--;
                return;
            }
            else {
                myHash[hashIndex].erase(ptr);
                return;
            }
        }
    }
}

HeapElement* Quash::bubbleUp(int index) {
    if(index <= 0) {
        return myHeap[index];
    }
    int parent = (index-1)/2;
    if(myHeap[parent]->data > myHeap[index]->data) {
        heapSwap(parent, index);
        return bubbleUp(parent);
    }
    return myHeap[index];
}

HeapElement* Quash::bubbleDown(size_t index) {
    if(myHeap.size() == 0) return nullptr;
    if(index*2+1 > myHeap.size()-1) {
        return myHeap[index];
    }
    int parent = myHeap[index]->data;
    int leftChild = myHeap[index*2+1]->data;
    if(index*2+1 == myHeap.size()-1) {
        if(leftChild < parent) {
            heapSwap(index*2+1, index);
        }
        return myHeap[index];
    }
    int rightChild = myHeap[index*2+2]->data;
    if(rightChild < leftChild && rightChild < parent) {
        heapSwap(index, index*2+2);
        return bubbleDown(index*2+2);
    }
    else if(leftChild < parent) {
        heapSwap(index, index*2+1);
        return bubbleDown(index*2+1);
    }
    return myHeap[index];
}

void Quash::heapSwap(int index1, int index2) {

    HeapElement* first = myHeap[index1];
    HeapElement* second = myHeap[index2];

    first->positionInArray = index2;
    second->positionInArray = index1;
    myHeap[index1] = second;
    myHeap[index2] = first;
}

Quash::~Quash() {
    delete[] myHash;
    for(vector<HeapElement*>::iterator i = myHeap.begin(); i != myHeap.end(); i++) {
        delete *i;
    }
}






