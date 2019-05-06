#ifndef LIST_H
#define LIST_H
#include "Link.h"


class List
{
    public:
        List();
        virtual ~List();
        void setFirst(Link* );
        void setLast(Link*);
        void setSize(int);
        Link* getFirst();
        Link* getLast();
        int getSize();
        void initializeList(int);
        void AddLink(int, Link*);
        void AddLinkAfter(Link*, Link*);
        Link* RemoveLink(Link*);
        void FindLink(int);
        void displayList();
        void mergeLists(int, int, int);
        void mergeSort(int, int);
        Link* getLinkAt(int);
        void Delete(Link*);


    protected:

    private:
        Link* first;
        Link* last;
        int listSize;
};

#endif // LIST_H
