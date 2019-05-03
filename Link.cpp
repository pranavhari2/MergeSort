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
