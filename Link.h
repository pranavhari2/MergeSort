// Link.h

#ifndef LINK_H
#define LINK_H


class Link
{
    public:

        Link();
        virtual ~Link();
        void displayLink();
        void setNext(Link*);
        void setPrev(Link*);
        void setContents(int);
        Link* getNext();
        Link* getPrev();
        int getContents();

    protected:

    private:
        Link* next;
        Link* prev;
        int contents;

};

#endif // LINK_H
