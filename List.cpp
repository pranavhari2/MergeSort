#include "List.h"
#include "Link.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

List::List()
{
    //ctor
}

List::~List()
{
    //dtor
}

void List::setFirst(Link* _first)
{
    first = _first;
}

void List::setLast(Link* _last)
{
    last = _last;
}

void List::setSize(int _size)
{
    listSize = _size;
}

Link* List::getFirst()
{
    return first;
}

Link* List::getLast()
{
    return last;
}

int List::getSize()
{
    return listSize;
}

void List::initializeList(int _listSize)
{
    first = NULL;
    srand(time(NULL));

    listSize = _listSize;

    for (int i = 0; i < listSize+1; i++)
    {
        AddLink(rand()%10+1, first);
    }
    return;
}

void List::AddLink(int _contents, Link* destination)
{
    Link* newlink = new Link;
    newlink->setContents(_contents);
    //cout << newlink->contents;
    AddLinkAfter(newlink, destination);
}

void List::AddLinkAfter(Link* _link, Link* destination)
{

    if (destination == NULL)
    {
        first = _link;
        last = first;
        first->setNext(NULL);
        return;
    }

    else
    {
        if (destination->getNext() == NULL)
        {

        while (true)
        {
            if (destination->getNext() == NULL)
            {
                destination->setNext(_link);
                _link->setNext(NULL);
                //last = _link;
                return;
            }
            else
            {
                destination = destination->getNext();
            }

        }
        }


        else
        {
            _link->setNext(destination->getNext());
            destination->setNext(_link);
            _link->setPrev(destination);

            //destination = destination->getNext();
        }

        return;
    }
}

// Unnecessary Functions
/*
Link* List::RemoveLink(Link* _link)
{
    if (_link == first)
    {
        _link->getNext()->setPrev(NULL);
    }
    else if (_link == last)
    {
        _link->getPrev()->setNext(NULL);
    }
    else
    {
        _link->prev->next = _link->next;
        _link->next->prev = _link->prev;
    }
    return _link;
}

void List::FindLink(int num)
{
    Link* temp = first;

    while (temp != NULL)
    {
        if (temp->contents == num)
        {
            cout << num << " has been found. " << endl;
            return;
        }
        else
        {
            cout << num << " has not been found";
            return;
        }
        temp = temp->next;
    }

}
*/

void List::displayList()
{
    Link* temp = first;
    int i = 0;

    while (temp->getNext() != NULL)
    {
        cout << "Element " << i+1 << "" << ":    ";
        temp->displayLink(temp);
        temp = temp->getNext();
        i++;
    }

    return;
}

Link* List::getLinkAt(int pos)
{
    Link* temp = first;

    for (int i = 0; i < pos; i++)
    {
        temp = temp->getNext();
    }
    return temp;
}

void List::Delete(Link* _link)
{
    _link = NULL;
    return;
}

// Merge and Merge Sort Functions

void List::mergeLists(int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of merged subarray

    /* create temp lists */

    List left, right;

    // Split Lists

    for (i = 0; i < n1; i++)
    {
        cout << "Split 1" << endl;
        left.AddLink(getLinkAt(low + i)->getContents(), getFirst());
        cout << endl;
        cout << getLinkAt(low + i)->getContents();
        cout << endl;

    }
    //cout << "Left Side: " << endl;
    //left.displayList();

    for (j = 0; j < n2; j++)
    {
        cout << "Split 2" << endl;
        right.AddLink(getLinkAt(mid + 1 + j)->getContents(), getFirst());
        cout << endl;
        cout << getLinkAt(mid + 1 + j)->getContents();
        cout << endl;
    }

    //cout << "Right Side: " << endl;
    //right.displayList();


    // Merge lists




    while (i < n1 && j < n2)
    {
        if (left.getLinkAt(i)->getContents()  <= right.getLinkAt(j)->getContents())
        {
            //arr[k] = L[i];
            AddLink(left.getLinkAt(i)->getContents(), getLinkAt(k));
            Delete(getLinkAt(k));
            i++;
        }
        else
        {
            AddLink(right.getLinkAt(j)->getContents(), getLinkAt(k));
            Delete(getLinkAt(k));
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        AddLink(left.getLinkAt(i)->getContents(), getLinkAt(k));
        Delete(getLinkAt(k));
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */

    while (j < n2)
    {
        AddLink(right.getLinkAt(j)->getContents(), getLinkAt(k));
        Delete(getLinkAt(k));
        j++;
        k++;
    }
}









/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

void List::mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;

        // Sort first and second halves
        mergeSort(low, mid);
        mergeSort(mid+1, high);

        mergeLists(low, mid, high);
    }
    return;
}
