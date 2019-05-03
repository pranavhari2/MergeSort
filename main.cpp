#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "List.h"
#include "Link.h"

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


    return 0;
}
