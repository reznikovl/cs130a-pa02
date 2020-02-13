struct Element {
    int data;
    int count;
    
    Element(int start):data(start), count(1){};
};

struct HeapElement : Element {
    int positionInArray;
    HeapElement(int start, int pos) : Element(start) {
        positionInArray = pos;
    }
};

struct HashElement : Element {
    HeapElement* otherAddress;
    HashElement(int start, HeapElement* other) : Element(start) {
        otherAddress = other;
    }
};
