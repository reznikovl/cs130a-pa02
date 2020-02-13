#include "Element.h"
#include <vector>

class MinHeap {
    public:
        MinHeap();
        Element* insert(int i);
        int deleteMin(); //returns minimum element 
        void deleteElement(Element* toDelete);
        void print();

        ~MinHeap();
        

    private:
        std::vector<Element*> myHeap;
        int used;

}