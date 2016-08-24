//Programmer:    Dylan Fetch and Christopher Carney
//Section:       2
//Lab:           Final Project
//Date:          April 26, 2014
//Description:   This is the implementation of the "Sorts.h" module

#include "Sorts.h"
#include "BinarySearchTree.h"

                                        /*/HELPER FUNCTIONS/*/

void Swap(int & a, int & b)
//PRE:    a must be an element of an array, b must be an element of the same array
//POST:   method swaps values of a and b in an array
{
    int temp;                      //the temporary variable to hold one value during swap

    temp=a;
    a=b;
    b=temp;
}

                                 /*/QUICK SORT MEMBER FUNCTIONS/*/
int PartitionHelper(int A[],int p,int q, int pivot)
//PRE:    p>0, p<=q, A[p..q] must be initialized, pivot must be initialized
//POST:   A[p..FCTVAL] contains all values from A[p..q] at the time of invocation less than or
//        equal to pivot, A[FCTVAL+1..q] contains all values from A[p..q] at the time of invocation
//        greater than pivot
{
    int m;                             //the index of the last value less than pivot

    m=p-1;

    for(int i=p;i<=q;i++)              //determinate loop to advance through A[p..q]
    {
        if(A[i]<=pivot)                //if the value is less or than equal to pivot, m is advanced
        {                              //   and the value is placed at A[m]
            m=m+1;
            Swap(A[i],A[m]);
        }
    }

    return m;
}

int Partition(int A[],int p,int r)
//PRE:    p>0,p<=r,A[p..r] must be initialized
//POST:   A[p..FCTVAL-1] are less than or equal to A[FCTVAL] at the time of invocation, and 
//        A[FCTVAL+1..r] are greater than A[FCTVAL] at the time of invocation
{
    int m;                             //the index of the last value less than pivot

    m=PartitionHelper(A,p,r-1,A[r]);   //partitions sub-array
    Swap(A[m+1],A[r]);                 //places pivot in its sorted position in the array


    return m+1;                        //return pivot
}

void QuickSort(int A[],int p,int q)
//PRE:    p>0, p<=q, A[p..q] is initialized
//POST:   A[p..q] contains the values from A[p..q] at the time of invocation in ascending order
{
    int k;                             //the index of pivot

    if(q>p)                            //base case is reached when q=p
    {
        k=Partition(A,p,q);            //partitions sub-array and returns index of pivot
        QuickSort(A,p,k-1);            //return quick sort for sub-array less than pivot
        QuickSort(A,k+1,q);            //return quick sort for sub-array greater than pivot
    }
}

                                  /*/MERGE SORT MEMBER FUNCTIONS/*/
void Merge(int A[], int p, int q, int r)
//PRE:    A[p..q] and A[q+1..r] must be sorted in ascending order, 0<=p<=q<=r
//POST:   A[p..q] and A[q+1..r] are merged and the resulting sub-array A[p..r] is in ascending
//        order

{
    int l_ctr;                         //counter that maintains position in A[p..q]
    int r_ctr;                         //counter that maintains position in A[q+1..r]
    int temp_size;                     //physical size of temporary array   
    int temp_count;                    //logical size of temporary array
    int *temp;                         //temporary array to hold values of A[p..r]
    int copy_count;                    //variable to increment copying of temp array to A[p..r]

    l_ctr=p;
    r_ctr=q+1;
    temp_size=r-p+1;
    temp_count=0;

    temp=new int[temp_size];

    while(l_ctr<=q && r_ctr<=r)        //indeterminate loop to advance through subarrays until one
    {                                  //   runs out of values          
        if(A[l_ctr]<=A[r_ctr])         //if the value in subarray L is lower, it is inserted in          
        {                              //   temp         
            temp[temp_count]=A[l_ctr];                 
            l_ctr++;
            temp_count++;
        }
        else                           //else the value from subarray R is inserted in temp          
        {                                        
            temp[temp_count]=A[r_ctr];
            r_ctr++;
            temp_count++;
        }
    }
    while(l_ctr<=q)                    //indeterminate loop to copy the rest of subarray L into
    {                                  //   temp if subarray R is out of values
        temp[temp_count]=A[l_ctr];
        l_ctr++;
        temp_count++;
    }
    while(r_ctr<=r)                    //indeterminate loop to copy the rest of subarray R into
    {                                  //   temp if subarray L is out of values
        temp[temp_count]=A[r_ctr];
        r_ctr++;
        temp_count++;
    }

    copy_count=0;
    for(int i=p;i<=r;i++)              //determinate loop to copy values in temp array into A[p..r]
    {
        A[i]=temp[copy_count];
        copy_count++;
    }

    delete temp;
}

void MergeSort(int A[], int p, int q)
//PRE:  A[p..q] must be initialized, p<=0, p<=q
//POST: A[p..q] contains elements of A[p..q] sorted in ascending order
{
    int m;                                      //the midpoint of A[p..q]

    if (p < q)                                  //base case so recursion stops when the array
    {                                           //  becomes size 1 which is a sorted array
        m = (p + q) / 2;
        MergeSort(A, p, m);
        MergeSort(A,m+1,q);
        Merge(A,p,m,q);
    }
}

                                 /*/INSERTION SORT MEMBER FUNCTIONS/*/
void InsertionSort(int A[], int logSize)
//PRE:    logSize>0 and A[0..logSize-1] is initialized
//POST:   A[0..logSize-1] contains values from A[0..logSize-1] a the time of invocation
//        sorted in ascending order
{
    int key;                       //value that other values in array are compared to
    int i;                         //value used to increment inner loop

    for(int j=1;j<logSize;j++)         //take each element of A[0..logSize-1] and insert it into
    {                                  //   A[0..j-2] where it goes
        key=A[j];

        i=j-1;
        while(i>=0 && A[i]>key)        //shift A[0..j-2] s.t. there's an appropriate slot in
        {                              //   A[0..j-1] for key
            A[i+1]=A[i];
            i=i-1;
        }

        A[i+1]=key;
    }
}

                                   /*/BUBBLE SORT MEMBER FUNCTIONS/*/
void BubbleSort(int A[],int n)
//PRE:    n>1 and A[0..n-1] is initialized
//POST:   A[0..n-1] contains values from A[0..logsize-1] sorted in ascending order
{
    for(int bottom=n-1;bottom>=1;bottom--)  //determinate loop that brings the bottom down
    {
        for(int i=0;i<bottom;i++)           //determinate loop to traverse loop up to bottom
        {
            if(A[i+1]<A[i])                 //if the value is larger than the value after it, the
            {                               //   values are swapped
                Swap(A[i+1],A[i]);
            }
        }
    }
}

                                  /*/SELECTION SORT MEMBER FUNCTIONS /*/
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

        Swap(data[bottom], data[maxIndex]);  //put the max value at the end of the unsorted array
    }
}

                                   /*/TREE SORT MEMBER FUNCTIONS/*/
void treeSort(int numbers[], int & logSize)
//PRE:     logSize has been initialized, logSize > 0
//         numbers[0..logSize-1] have been initialized, every value in numbers[0..logSize-1] is
//             unique
//POST:    the values in numbers[0..logSize-1] at the time of invocation have been placed into 
//              numbers[0..logSize-1] sorted in ascending order
{
    BinarySearchTree myTree = BinarySearchTree(numbers, logSize);  //create a tree object
    myTree.inorderCopy(numbers, logSize);                          //store the list inorder
}
