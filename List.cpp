// List.cpp
// Contains all functions that belong to list

#include "List.h"
#include "Link.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

List::List()
{
    first = NULL;
    last = NULL;
    listSize = 0;
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

// Initailize list of random numbers

void List::initializeList(int _listSize)
{
    srand(time(NULL));

    listSize = _listSize;

    for (int i = 0; i < listSize; i++)
    {
        AddLink(rand()%10+1, last);
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
        last = first;               // To set both values the same , last is top
        first->setNext(NULL);
        first->setPrev(NULL);
    }

    else if (destination == last)
    {
        destination->setNext(_link);
        last = _link;
        last->setNext(NULL);
        last->setPrev(destination);
    }

    else
    {
        destination->getNext()->setPrev(_link);
        _link->setNext(destination->getNext());
        destination->setNext(_link);
        _link->setPrev(destination);
    }

    return;
}

void List::FindLink(int num)
{
    Link* temp = first;
    while (temp != NULL)
    {
        if (temp->getContents() == num)
        {
            cout << num << " has been found. " << endl;
            return;
        }
        else
        {
            cout << num << " has not been found";
            return;
        }
        temp = temp->getNext();
    }
}


void List::displayList()
{
    Link* temp = first;

    while(temp->getNext() != NULL)
    {
        temp->displayLink();
        cout << ", ";
        temp = temp->getNext();
	}

    cout << last->getContents() << endl;

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

void List::DeleteLink(Link* _link)
{
	if (first != NULL && _link != NULL)
	{

		if (first == _link && last == _link)
		{
			first = NULL;
			last = NULL;
		}

		else if (first == _link)
		{
			_link->getNext()->setPrev(NULL);
			first = _link->getNext();
		}

		else if (last == _link)
		{
			_link->getPrev()->setNext(NULL);
			last = _link->getPrev();
		}

		else
		{
			_link->getPrev()->setNext(_link->getNext());
			_link->getNext()->setPrev(_link->getPrev());
		}

		delete(_link);
	}

	return;
}

// Merge and Merge Sort Functions

void List::mergeLists(int low, int mid, int high)
{
    int i, j, k;
    int leftSize = mid - low + 1;
    int rightSize =  high - mid;

    i = 0; // Initial index of first list
    j = 0; // Initial index of second list
    k = low; // Initial index of merged list

    /* create temp lists */

    List left, right;


    // Put data into temp lists

    for (i = 0; i < leftSize; i++)
    {
        left.AddLink(getLinkAt(low + i)->getContents(), left.getLast());              // Split contents into a left list and a right list
    }


    for (j = 0; j < rightSize; j++)
    {
        right.AddLink(getLinkAt(mid + 1 + j)->getContents(), right.getLast());
    }


    i = 0;
    j = 0;


    while (i < leftSize && j < rightSize)
    {
        if (left.getLinkAt(i)->getContents()  <= right.getLinkAt(j)->getContents())
        {
            AddLink(left.getLinkAt(i)->getContents(), getLinkAt(k));    // Compare the values of left and right lists
            DeleteLink(getLinkAt(k));
            i++;
        }
        else
        {
            AddLink(right.getLinkAt(j)->getContents(), getLinkAt(k));
            DeleteLink(getLinkAt(k));
            j++;
        }

        k++;                  // Move the comparing position to the next
    }

    // Copy remaining elements of the left list


    while (i < leftSize)
    {
        AddLink(left.getLinkAt(i)->getContents(), getLinkAt(k));
        DeleteLink(getLinkAt(k));
        i++;
        k++;
    }

    // Copy remaining elements of the right list

    while (j < rightSize)
    {
        AddLink(right.getLinkAt(j)->getContents(), getLinkAt(k));
        DeleteLink(getLinkAt(k));
        j++;
        k++;
    }


}


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
