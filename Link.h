#ifndef LINK_H
#define LINK_H


class Link
{
    public:
        Link* next;
        Link* prev;
        int contents;
        Link();
        virtual ~Link();
        void displayLink(Link*);

    protected:

    private:

};

#endif // LINK_H
