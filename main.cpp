// main.cpp
// Project Title:		Merge Sort
// Project Description:	Merge Sort algorithm using Linked Lists
// Date Created:		April 30, 2019
// Last Modified:		May 11, 2019
// Author:			    Pranav Hari

// Comments: The program sometimes does not put the right
// items into each list and does not sort it properly.

#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "List.h"
#include "Link.h"
#include <windows.h>

using namespace std;

int main()
{
    string restart;
    int listSize;

    do
    {

        List* myList = new List;
        Link* link;

        system("CLS");
        cout << "Enter the size of the list you want to create: " << endl;
        cin >> listSize;

        if (listSize <= 0)
        {
            cout << "Invalid Size" << endl;
        }
        else
        {
            system("CLS");

            myList->initializeList(listSize);

            cout << endl;
            cout << "Unsorted List: " << endl << endl;
            myList->displayList();
            cout << endl;


            system("PAUSE");
            cout << endl;
            myList->mergeSort(0, myList->getSize()-1);

            system("PAUSE");
            system("CLS");
            cout << "Sorted List: " << endl << endl;
            myList->displayList();


            }
            cout << endl << endl;
            cout << "Restart Program? (Y/N)" << endl;
            cin >>  restart;


    }while(restart == "Y");


    return 0;
}
