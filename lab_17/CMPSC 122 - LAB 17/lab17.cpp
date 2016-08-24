//Programmer:   Christopher Carney
//Section:      2
//Lab:          17
//Date:         April 22, 2014
//Description:  This lab implements the Insertion Sort in a method and tests it on arrays

#include <iostream>
using namespace std;

void insertionSort(int data[], int logSize)
//PRE:  logSize is initialized, logSize > 0
//      data[0..logSize-1] is initialized
//POST: data[0..logSize-1] is sorted in ascending order
{
    int subscript;                  //the variable used to hold the new subscript
                                    //  of the highest value
    int key;                        //the variable to hold the value of the highest value in the
                                    //  unsorted array 

    for (int j = 1; j < logSize; j++)     //outer loop to take each element of data[0..logSize-1]
    {                                     //     and insert it into data[0..j-1]
        key = data[j];

        subscript = j - 1;               
        while(subscript >= 0 && data[subscript] > key)    //inner loop to shift data[0..j-1] s.t. 
        {                                                 //  there's an appropriate slot for key
            data[subscript + 1] = data[subscript];
            subscript--;
        }
        data[subscript + 1] = key;
    }
}

void printArray(int array[], int logSize)
//PRE:  logSize is initialized, logSize > 0
//      array[0..logSize-1] is initialized
//POST: array[0..logSize-1] has been printed to the screen with a space between each element
{
    for (int i = 0; i < logSize; i++)           //determinate loop to print every element in 
    {                                           //  the array with a space in between
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};          //the array in sorted ascending order
    int array2[] = {7, 4, 2, 9, 0, 1, 3, 8, 6, 5};          //the array in mixed order
    int array3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};          //the array in descending order

    cout << "Before sorting: \n";
    printArray(array1, 10);
    printArray(array2, 10);
    printArray(array3, 10);

    insertionSort(array1, 10);
    insertionSort(array2, 10);
    insertionSort(array3, 10);

    cout << "\nAfter sorting: \n";
    printArray(array1, 10);
    printArray(array2, 10);
    printArray(array3, 10);

    return 0;
}