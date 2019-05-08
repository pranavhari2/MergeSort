#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "List.h"
#include "Link.h"
#include <windows.h>

using namespace std;

int main()
{
    List* myList = new List;
    Link* link;
    int listSize;

    cout << "Enter the size of the list you want to create: " << endl;
    cin >> listSize;

    system("CLS");

    myList->initializeList(listSize);

    cout << "Unsorted List:" << endl << endl;
    myList->displayList();
    system("PAUSE");


    system("PAUSE");
    cout << endl;
    myList->mergeSort(0, listSize-1);

    system("PAUSE");
    system("CLS");
    cout << "Sorted List:" << endl << endl;
    myList->displayList();


    return 0;
}
