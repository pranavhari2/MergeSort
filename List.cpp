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

void List::initializeList(int listSize)
{
    first = NULL;
    srand(time(NULL));

    for (int i = 0; i < listSize+1; i++)
    {
        AddLink(rand()%10+1);
    }
    return;
}

void List::AddLink(int _contents)
{
    Link* newlink = new Link;
    newlink->contents = _contents;
    //cout << newlink->contents;
    AddLinkAfter(newlink);
}

void List::AddLinkAfter(Link* _link)
{

    Link* temp = first;

    if (temp == NULL)
    {
        first = _link;
        first->next = NULL;
        return;
    }

    else if (temp->next == NULL)
    {
        temp->next = _link;
        _link->next = NULL;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                temp->next = _link;
                _link->next = NULL;
                return;
            }
            else
            {
                temp = temp->next;
            }

        }
        return;
    }

}

Link* List::RemoveLink(Link* _link)
{
    if (_link == first)
    {
        _link->next->prev = NULL;
    }
    else if (_link == last)
    {
        _link->prev->next = NULL;
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

void List::displayList()
{
    Link* temp = first;
    int i = 0;

    while (temp->next != NULL)
    {
        cout << "Element " << i+1 << "" << ":    ";
        temp->displayLink(temp);
        temp = temp->next;
        i++;
    }

    return;
}

// Merge and Merge Sort Functions

void List::mergeLists(int l, int m, int r)
{
    Link* temp = first;



    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp lists */

    List* list1 = new List;
    List* list2 = new List;

    /* Copy data to temp lists */

    for (i = 0; i < n1; i++)
    {
        list1->AddLink(temp->contents);
        temp = temp->next;
    }

    for (j = 0; j < n2; j++)
    {
        list2->AddLink(temp->contents);

    }


    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray


    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}









/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

void List::mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l+r)/2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);

        mergeLists(l, m, r);
    }
}
