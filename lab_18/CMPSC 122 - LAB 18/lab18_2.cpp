//Programmer:   Christopher Carney
//Section:      2
//Lab:          18
//Date:         April 24, 2014
//Description:  This program is an implementation of merge sort & also test drives it

#include <iostream>
using namespace std;

void merge(int L[], int l_size, int R[], int r_size, int A[])
//PRE:  l_size has been initialized & l_size > 0, r_size has been initialized & r_size > 0
//      L[0..l_size-1] has been initialized and is sorted in ascending order
//      R[0..r_size-1] has been initialized and is sorted in ascending order
//      A is allocated to a size atleast l_size + r_size
//POST: A[0..l_size + r_size - 1] contains the values from R[0..r_size-1] and 
//          L[0..l_size-1] sorted in ascending order
{
    int l_ctr;                          //the variable to count elements in the L array
    int r_ctr;                          //the variable to count elements in the R array
    int a_size;                         //the current size of the A array

    l_ctr = l_size;                          //initial values taken from L & R arrays is zero
    r_ctr = r_size;
    a_size = 0;                         //start at subscript 0 for the combined array

    //indeterminate loop while there are still elements in one of the two L or R arrays
    //  whenever one runs out of elements before the other the loop terminates
    while (l_ctr < l_size && r_ctr < r_size)
    {
        if (L[l_ctr] <= R[r_ctr])                   //check if L element is smaller
        {
            A[a_size] = L[l_ctr];                   //add smaller one to the combined array
            l_ctr++;
        }
        else                                        //otherwise R is smaller
        {
            A[a_size] = R[r_ctr];
            r_ctr++;
        }
        
        a_size++;
    }

    if (l_ctr < l_size)                          //after loop terminates if there are 
    {                                            // uncopied elements in the L array
        //determinate: copy the remaining elements from the L array to the combined one
        for (int i = l_ctr; i < l_size; i++)
        {
            A[a_size] = L[i];
            a_size++;
        }
    }
    else                                        //otherwise there are still elements 2in R
    {
        //determinate: copy the remaining elements from the R array to the combined one
        for (int i = r_ctr; i < r_size; i++)
        {
            A[a_size] = R[i];
            a_size++;
        }
    }
}

void mergeSort(int array[], int p, int q)
//PRE:  p >= 0, p is the subscript of the first element to be sorted in the array[p..q]
//      q >= p, q is the subscript of the last element to be sorted in the array[p..q]
//POST: array[p..q] from the time of invocation is sorted in ascending order
{
    int m;                          //the median value between p and q
    
    if (p < q)                      //RECURSIVE CASE: there are still arrays to be broken
    {                               //      down into smaller ones
        m = (p + q) / 2;

        mergeSort(array, p, m);
        mergeSort(array, m+1, q);
        merge(array, m - p + 1, array, q - m, array); 
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
    //three test arrays in descending, random, and ascending order
    int test[] = {2, 1};
    int test1[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7};
    int test2[] = {4, 1, 3, 9, 45, 23, 2, 34, 1, 12, 7};
    int test3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array2[20];

    cout << "Before sorting: \n";
    printArray(test1, 14);
    printArray(test2, 11);
    printArray(test3, 9);

    mergeSort(test, 0, 1)
    //mergeSort(test1, 0, 13);
    //mergeSort(test2, 0, 10);
    //mergeSort(test3, 0, 8);

    cout << "\nAfter sorting: \n";
    printArray(test, 2);
    printArray(test2, 11);
    printArray(test3, 9);
}