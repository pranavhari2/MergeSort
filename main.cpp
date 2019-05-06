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

    myList->initializeList(listSize);

    myList->displayList();
    system("PAUSE");
    system("CLS");


    system("PAUSE");
    myList->mergeSort(0, listSize);

    system("PAUSE");
    system("CLS");
    myList->displayList();


    return 0;
}
