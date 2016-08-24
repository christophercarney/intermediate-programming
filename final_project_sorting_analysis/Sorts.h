// Programmer:    Dylan Fetch and Christopher Carney
// Section:       2
// Lab:           Final Project
// Date:          April 26, 2014
// Description:   Header file for sorting module

                                        /*/HELPER FUNCTIONS/*/
void Swap(int & a, int & b);
//PRE:    a must be an element of an array, b must be an element of the same array
//POST:   method swaps values of a and b in an array


                                 /*/QUICK SORT MEMBER FUNCTIONS/*/
int PartitionHelper(int A[],int p,int q, int pivot);
//PRE:    p>0, p<=q, A[p..q] must be initialized, pivot must be initialized
//POST:   A[p..FCTVAL] contains all values from A[p..q] at the time of invocation less than or
//        equal to pivot, A[FCTVAL+1..q] contains all values from A[p..q] at the time of invocation
//        greater than pivot

int Partition(int A[],int p,int r);
//PRE:    p>0,p<=r,A[p..r] must be initialized
//POST:   A[p..FCTVAL-1] are less than or equal to A[FCTVAL] at the time of invocation, and 
//        A[FCTVAL+1..r] are greater than A[FCTVAL] at the time of invocation

void QuickSort(int A[],int p,int q);
//PRE:    p>0, p<=q, A[p..q] is initialized
//POST:   A[p..q] contains the values from A[p..q] at the time of invocation in ascending order


                                  /*/MERGE SORT MEMBER FUNCTIONS/*/
void Merge(int A[], int p, int q, int r);
//PRE:    A[p..q] and A[q+1..r] must be sorted in ascending order, p<=q<=r
//POST:   A[p..q] and A[q+1..r] are merged and the resulting sub-array A[p..r] is in ascending
//        order

void MergeSort(int A[], int p, int q);
//PRE:    A[p..q] must be initialized, p<=0, q<=p
//POST:   A[p..q] contains elements of A[p..q] in ascending order


                                 /*/INSERTION SORT MEMBER FUNCTIONS/*/
void InsertionSort(int A[], int logSize);
//PRE:    logSize>0 and A[0..logSize-1] is initialized
//POST:   A[0..logSize-1] is sorted in ascending order


                                   /*/BUBBLE SORT MEMBER FUNCTIONS/*/
void BubbleSort(int A[],int n);
//PRE:    n>1 and A[0..n-1] is initialized
//POST:   A[0..n-1] is sorted in ascending order


                                  /*/SELECTION SORT MEMBER FUNCTIONS /*/
void selectionSort(int data[], int logSize);
//PRE:  data[0..logSize-1] has been initialized, logSize > 0
//POST: data[0..logSize-1] is sorted in ascending order


                                   /*/TREE SORT MEMBER FUNCTIONS/*/
void treeSort(int numbers[], int & logSize);
//PRE:     logSize has been initialized, logSize > 0
//         numbers[0..logSize-1] have been initialized, every value in numbers[0..logSize-1] is
//             unique
//POST:    the values in numbers[0..logSize-1] at the time of invocation have been placed into 
//              numbers[0..logSize-1] sorted in ascending order
