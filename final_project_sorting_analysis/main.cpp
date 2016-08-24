//Programmer:    Dylan Fetch and Christopher Carney
//Section:       2
//Lab:           Final Project
//Date:          April 26, 2014
//Description:   This is the test driver for the sorts.cpp and the implementation of timing 

#include <iostream>
#include <iomanip>
#include <cstdlib>                  // for random number generator
#include <ctime>                    // for time method so we can seed the generator
#include <time.h>                   // for timer
#include "Sorts.h"
using namespace std;

const int ARRAY_SIZE = 7000;

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

void copyArray(int array1[], int array2[], int logSize)
//PRE:  array1[0..logSize-1] is initialized, array2[0..logSize-1] is initialized
//POST: array2[0..logSize-1] now contains the values from array1[0..logSize-1] in the same 
//          order
{
    for (int i = 0; i < logSize; i++)        //determinate loop to copy elements to the array
    {
        array2[i] = array1[i];
    }
}

double NextRandNum()
// PRE:  random number generator has been initialized with a call to srand()
// POST: FCTVAL == next random number x s.t. x >= 0 and x < 1
{
    return double(rand()%32768)/32768;     // generate "random" number
} 

void generateRandomArray(int array[], int logSize)
//PRE:  array[0..logSize-1] has been initialized, logSize > 0
//POST: array[0..logSize-1] is now filled with random integers 
{ 
    srand(time(0));                                 //seed the generator 
    
    for (int i = 0; i < logSize; i++)
    {                                           
        array[i] = NextRandNum() * 1000;            //enter a random number 0-999
    }
}

void sortAscending(int array[], int logSize)
//PRE:  array[0..logSize-1] is initialized, logSize >= 0
//POST: array[0..logSize-1] is sorted in ascending order
{
    MergeSort(array, 0, logSize - 1);
}

void sortDescending(int A[], int n)
//PRE:  array[0..logSize-1] is initialized, logSize >= 0
//POST: array[0..logSize-1] is sorted in ascending order
{
    for(int bottom=n-1;bottom>=1;bottom--)  //determinate loop that brings the bottom down
    {
        for(int i=0;i<bottom;i++)           //determinate loop to traverse loop up to bottom
        {
            if(A[i+1]>A[i])                 //if the value is larger than the value before it, the
            {                               //   values are swapped
                Swap(A[i+1],A[i]);
            }
        }
    }
}

void timeSorts()
//POST: The six sorts have been printed to the screen along with the number of ticks it took to 
//          execute. This has been printed 3 times for 3 separate trials.
{
    clock_t startTime;             // start time for [whatever] in clock ticks
    clock_t finishTime;            // finish time for [whatever] in clock ticks
    double  elapsedTime;           // number of clock ticks for [whatever] to execute

    int * testArray1;                           //pointer to a test array for quick sort
    int * testArray2;                           //pointer to a test array for merge sort
    int * testArray3;                           //pointer to a test array for insertion sort
    int * testArray4;                           //pointer to a test array for bubble sort
    int * testArray5;                           //pointer to a test array for selection sort
    int * testArray6;                           //pointer to a test array for tree sort
    int logSize = ARRAY_SIZE;                   //the logical size for the tree sort

    //allocate space for the arrays
    testArray1 = new int [ARRAY_SIZE];
    testArray2 = new int [ARRAY_SIZE];
    testArray3 = new int [ARRAY_SIZE];
    testArray4 = new int [ARRAY_SIZE];
    testArray5 = new int [ARRAY_SIZE];
    testArray6 = new int [ARRAY_SIZE];
    
    //determinate loop to generate a random array 3 times, copy it, and use the 6 sorts. 
    //   generates three test runs as to account for variations in random data
    for (int i = 0; i < 3; i++)
    {
        generateRandomArray(testArray1, ARRAY_SIZE);
        //sortAscending(testArray1, ARRAY_SIZE);      //remove comment to test on ascending array
        //sortDescending(testArray1, ARRAY_SIZE);     //remove comment to test on descending array

        copyArray(testArray1, testArray2, ARRAY_SIZE);      //copy the original random array to 
        copyArray(testArray1, testArray3, ARRAY_SIZE);      //  the other arays
        copyArray(testArray1, testArray4, ARRAY_SIZE);  
        copyArray(testArray1, testArray5, ARRAY_SIZE);
        copyArray(testArray1, testArray6, ARRAY_SIZE);

        startTime = clock();                                //starts counting the ticks
        QuickSort(testArray1, 0, ARRAY_SIZE - 1);           //sorts the array
        finishTime = clock();                               //stops counting ticks
        elapsedTime = double(finishTime - startTime);       //calculate elapsed ticks & output
        cout << setw(20) << "Quick Sort = " << elapsedTime << " ticks.\n";

        startTime = clock(); 
        MergeSort(testArray2, 0, ARRAY_SIZE - 1);
        finishTime = clock();
        elapsedTime = double(finishTime - startTime); 
        cout << setw(20) << "Merge Sort = " << elapsedTime << " ticks.\n";

        startTime = clock(); 
        InsertionSort(testArray3, ARRAY_SIZE);
        finishTime = clock();
        elapsedTime = double(finishTime - startTime); 
        cout << setw(20) << "Insertion Sort = " << elapsedTime << " ticks.\n";

        startTime = clock(); 
        BubbleSort(testArray4, ARRAY_SIZE);
        finishTime = clock();
        elapsedTime = double(finishTime - startTime); 
        cout << setw(20) << "Bubble Sort = " << elapsedTime << " ticks.\n";

        startTime = clock(); 
        selectionSort(testArray5, ARRAY_SIZE);
        finishTime = clock();
        elapsedTime = double(finishTime - startTime); 
        cout << setw(20) << "Selection Sort = " << elapsedTime << " ticks.\n";

        startTime = clock(); 
        treeSort(testArray6, logSize);
        finishTime = clock();
        elapsedTime = double(finishTime - startTime); 
        cout << setw(20) << "Tree Sort = "  << elapsedTime << " ticks.\n\n";
    }
    
    delete testArray1, testArray2, testArray3, testArray4, testArray5, testArray6;
}

int main()
{
    //six of the same test arrays unsorted in random order to test
    int test1[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int test2[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int test3[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int test4[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int test5[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int test6[] = {64, 12, 2, 5, 7, 3, 89, 34, 54, 23, 2, 10, 8, 20, 7};
    int logSizeTree = 15;                                                       //logical size of
                                                                                //the array
    QuickSort(test1, 0, 14);
    MergeSort(test2, 0, 14);
    InsertionSort(test3, 15);
    BubbleSort(test4, 15);
    selectionSort(test5, 15);
    treeSort(test6, logSizeTree);

    printArray(test1, 15);
    printArray(test2, 15);
    printArray(test3, 15);
    printArray(test4, 15);
    printArray(test5, 15);
    printArray(test6, 15);

    timeSorts();
}