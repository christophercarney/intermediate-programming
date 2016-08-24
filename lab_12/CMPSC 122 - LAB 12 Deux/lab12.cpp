//Programmer:   Christopher Carney
//Section:      2
//Lab:          12
//Date:         March 27, 2014
//Description:  This program uses binary search to find the subscript of a number in an array
//                  via recursion

#include <iostream>

using namespace std;

int binarySearch(int array1[], int high, int low, int key)
//PRE:  array1[low..high] is initialized, array1[low..high] is sorted in ascending order && 
//          each value of array is unique
//      high is initialized, high is the high bound of the index of the array to search
//      low is initialized, low is the low bound of the index of the array to search
//          high >= low >= 0
//      key is initialized
//POST: FNCTVAL == the subscript of the key found in array1[low..high] ||  
//          -1 if the key is not found
{
    int middle;                                  //the middle subscript between high & low

    middle = (high + low) / 2;                   //the floor of high+low/2

    if (array1[middle] == key)                   //base case: key is found at array[middle]
        return middle;
    else if (low > high)                         //base case: key is not found in array[low..high]
        return -1;
    else if (array1[middle] > key)                               //recursive case: key is less than
        return binarySearch(array1, middle - 1, low, key);       //   upper half of array
    else                                                        //recursive case: key is greater 
        return binarySearch(array1, high, middle + 1, key);      //   than lower half of array
}

int main()
{

    int testArray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};      //a test array with 10 elements

    int testArray2[] = {13, 15, 17, 19, 21};                //a test array with 5 elements

    cout << "Array #1: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}\n";
    cout << "Array #2: {13, 15, 17, 19, 21}\n";

    cout << "Searching for 1 in array 1...: " << binarySearch(testArray1, 9, 0, 1) << endl;
    cout << "Searching for 7 in array 1...: " << binarySearch(testArray1, 9, 0, 7) << endl;
    cout << "Searching for 20 in array 1...: " << binarySearch(testArray1, 9, 0, 20) << endl;

    cout << "\nSearching for 17 in array 2...: " << binarySearch(testArray2, 9, 0, 17) << endl;
    cout << "Searching for 13 in array 2...: " << binarySearch(testArray2, 9, 0, 13) << endl;
    cout << "Searching for 19 in array 2...: " << binarySearch(testArray2, 9, 0, 19) << endl;
    cout << "Searching for 26 in array 2...: " << binarySearch(testArray2, 9, 0, 26) << endl;

    return 0;
}
