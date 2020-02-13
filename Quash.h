#include "Element.h"
#include <list>
#include <vector>

class Quash {
    public:
        Quash();
        void insert(int i);
        void lookup(int i);
        void deleteMin();
        void deleteElement(int i);
        void print();

    private:
        std::list<HashElement>* myHash;
        int hash(int i);
        HashElement* lookupAddress(int i);
        void deleteFromHash(int i);

        std::vector<HeapElement*> myHeap;
        //int lastIndex;
        HeapElement* bubbleUp(int index);
        HeapElement* bubbleDown(int index);
        void heapSwap(int index1, int index2);

};