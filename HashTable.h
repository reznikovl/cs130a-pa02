#include "Element.h"
#include <list>
class HashTable {
    public:
        HashTable();

        int insert(int i, Element* other);//returns count
        int lookup(int i);//returns count
        Element* deleteElement(int i);//returns element to delete from heap

        ~HashTable();
        //HashTable& operator = (HashTable other);
        //HashTable(const HashTable& other);

    private:
        std::list<Element>* myHash; // = new List<Element>[43];
        int hash(int i);//-100%43+43

};