//Programmer:   Christopher Carney
//Section:      2
//Lab:          15
//Date:         April 15, 2014
//Description:  This is a test driver for the HashTable class

#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable myTable;                          //the hash table to perform tests on

    for (int i = 0; i < 21; i++)
    {
        myTable.hashInsert(i);
    }

    cout << "Searching for 20..." << myTable.hashSearch(20) << " nodes traversed." << endl;
    cout << "Searching for 100..." << myTable.hashSearch(100) << " aka not found." << endl;
    cout << "Searching for 5..." << myTable.hashSearch(5) << " nodes traversed.\n" << endl;

    myTable.drawTable();
    cout << "Load Factor: " << myTable.getLoadFactor() << endl << endl;

    myTable.hashInsert(59);
    myTable.hashInsert(47);
    myTable.hashInsert(98);
    myTable.hashInsert(49);
  
    myTable.drawTable();
    cout << "Load Factor: " << myTable.getLoadFactor() << endl << endl;

    return 0;
}