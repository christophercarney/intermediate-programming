//Programmer:   Christopher Carney
//Section:      2
//Lab:          16
//Date:         April 16, 2014
//Description:  This program implements selection sort and tests it on three different arrays

#include <iostream>
using namespace std;

void selectionSort(int data[], int logSize)
//PRE:  data[0..logSize-1] has been initialized, logSize > 0
//POST: data[0..logSize-1] is sorted in ascending order
{
    int maxIndex;                          //the index of the max value of the unsorted array

    //determinate loop to set the "bottom" of the array, max index of unsorted elements
    //  in the array
    for (int bottom = logSize - 1; bottom > 0; bottom--)
    {
        maxIndex = 0;

        //determinate loop to find the array index of the maximum value of the unsorted array
        for (int i = 1; i <= bottom; i++)
        {
            if (data[i] > data[maxIndex])   //if a number at any index is greater than the current
                maxIndex = i;               //   maxIndex, it becomes the new maxIndex
        }

        swap(data[bottom], data[maxIndex]);  //put the max value at the end of the unsorted array
    }
}

int main()
{
    //Three arrays to test data on
    int array1[] = {10, 38, 95, 31, 22, 4, 18, 100, 40, 12, 1};
    int array2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array3[] = {23, 59, 13, 14, 78, 3, 23, 89, 20, 40};

    cout << "Array 1 (unsorted): " << "10, 38, 95, 31, 22, 4, 18, 100, 40, 12, 1\n";
    cout << "Array 2 (unsorted): " << "20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, ";
    cout << "5, 4, 3, 2, 1\n";
    cout << "Array 3 (unsorted): " << "23, 59, 13, 14, 78, 3, 23, 89, 20, 40\n\n";

    selectionSort(array1, 11);
    selectionSort(array2, 20);
    selectionSort(array3, 10);

    cout << "Array 1 (sorted): ";
    for (int i = 0; i < 11; i++)                //determinate loop to print array 1
    {
        cout << array1[i] << ", ";
    }
    cout << endl;

    cout << "Array 2 (sorted): ";
    for (int i = 0; i < 20; i++)                //determinate loop to print array 2
    {
        cout << array2[i] << ", ";
    }
    cout << endl;

    cout << "Array 3 (sorted): ";
    for (int i = 0; i < 10; i++)                //determinate loop to print array 3
    {
        cout << array3[i] << ", ";
    }
    cout << endl;

    return 0;
}