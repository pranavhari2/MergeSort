#include "Link.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Link::Link()
{
    //ctor
}

Link::~Link()
{
    //dtor
}


void Link::displayLink(Link* _link)
{
    cout << _link->contents << endl << endl;
}

void Link::setNext(Link* _next)
{
    next = _next;
    return;
}

void Link::setPrev(Link* _prev)
{
    prev = _prev;
    return;
}

void Link::setContents(int num)
{
    contents = num;
    return;
}

Link* Link::getNext()
{
    return next;
}

Link* Link::getPrev()
{
    return prev;
}

int Link::getContents()
{
    return contents;
}
