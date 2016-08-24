//Programmer:   Christopher Carney
//Section:      2
//Lab:          14
//Date:         April 8, 2014
//Description:  This is the main and test driver for the BinarySearchTree class as well as the 
//                  implementation of a TreeSort function

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

void treeSort(int numbers[], int & logSize)
 //PRE:     logSize has been initialized, logSize > 0
 //         numbers[0..logSize-1] have been initialized, every value in numbers[0..logSize-1] is
 //             unique
 //POST:    the values in numbers[0..logSize-1] have been printed to the screen from least to 
 //             greatest
{
    BinarySearchTree myTree = BinarySearchTree(numbers, logSize);  //create a tree object
    myTree.inorderCopy(numbers, logSize);                          //store the list inorder
}

int main()
{

    int testClass[] = {6, 4, 8, 2, 5, 7, 9};

    int testSort[] = {20, 9, 4, 1, 5, 6, 2, 10, 15, 3, 18, 7};
    int logSize = 12;

    treeSort(testSort, logSize);

    for (int i = 0; i < 12; i++)
        cout << testSort[i] << " ";

    return 0;
}