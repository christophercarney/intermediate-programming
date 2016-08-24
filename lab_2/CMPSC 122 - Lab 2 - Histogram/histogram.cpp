//Programmer:   Christopher Carney
//Section:      2
//Lab:          2
//Date:         January 24, 2014
//Description:  This program takes numbers in an array of a specified
//                 length and creates a histogram of data visually of 
//                 different length bars in a data range and shows the 
//                 frequency of the data in that range.

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_VALS = 100;           //constant for the max number of categories in a histogram

void generateHistogram(double data[], double highBound, double lowBound, int intervals, int logicalSize)
//PRE:  data[0..logicalSize-1] is initialized
//      highBound > lowBound
//      intervals > 0
//      logicalSize > 0, logicalSize is the number of data points in data[]
//POST: one asterik (*) has been printed for all values within data[0..logicalSize-1] for all k s.t.
//      lowBound <= k <= highBound
//      a histogram has been printed with lines of output == intervals, each line begins with the bounds
//          of input for each category
//      intervals is the even spacing between the lowBound and highBound
//      frequency amount in data range is printed next to the last asterik in a row in parenthesis
{
    double arrayIntervals[MAX_VALS];    //the intervals for the histogram starting at lowBound and 
                                        //    ending at highBound
    int arrayFrequency[MAX_VALS];       //a parallel array to arrayIntervals which contains the freq.
                                        //  of a value in the corresponding subscript to the interval
    double deltaX;                      // space between each interval from lowBound to highBound


    //PROCESS
    deltaX = (highBound - lowBound) / intervals;  //basic "change in" formula

    //initialize the values in arrayFrequency[0..intervals-1] = 0
    for (int i = 0; i < intervals; i++)
    {
         arrayFrequency[i] = 0;
    }

    //set arrayIntervals[0...intervals] to the data range according to deltaX
    for (int i = 0; i <= intervals; i++)
    {
        if (i == 0)                         //arrayIntervals[0] is always lowBound
            arrayIntervals[i] = lowBound;
        else if (i == intervals)        //arrayIntervals[intervals] = last interval, it is the highBound
            arrayIntervals[i] = highBound;
        else                                //subscripts in arrayIntervals[0..intervals] = deltaX apart
            arrayIntervals[i] = arrayIntervals[i-1] + deltaX;
    }

    //go through the values of data[0..logicalSize - 1] and determine the frequency in each interval
    for (int i = 0; i < logicalSize; i++)
    {
        
        //check the value of data[i] against the ranges of arrayIntervals[0..intervals - 1] to 
        //  see if it is in that data range
        for (int b = 0; b < intervals; b++)
        {
            if (data[i] >= arrayIntervals[b] && data[i] < arrayIntervals[b + 1])
                arrayFrequency[b]++;        //data[i] fits the data range then increment the 
                                            //  frequency of that interval by 1
        }
    }

    //OUTPUT
    //outputs lines equal to the number of intervals, their data ranges, an aseterisks for every 
    //  value within  the range, and the frequency
    for (int i = 0; i < intervals; i++)
    {
        cout.precision(2);                                  //always show atleast 2 decimal places

        cout << fixed << setw(7) << arrayIntervals[i] << " to ";        //outputs intervals with 
        cout << fixed << setw(7) << arrayIntervals[i + 1] << " : ";     //  appropriate whitespace

        //outputs 1 asterisks the numer in arrayFrequency[i], so arrayFrequency[i] = 3, outputs ***
        for (int b = 0; b < arrayFrequency[i]; b++)
        {
            cout << "*";
        }
        
        cout << "  (" << arrayFrequency[i] << ") \n";      //outputs the frequency at the end of a bar

    }
    
    cout << endl;

}

int main()
{
    double exampleDataOne[] = { 0, 2, 3.8, 5, 9, 16, 16.2, 
                                    17, 18, 19, 19.5 };     //data set test
    double exampleDataTwo[] = { -2.3, -5, -4.2, 0.7, 6, 9.9, 
                                    -9.3, 8.4, 5.5, 3, 1, 0,
                                     8.9, 2.4, -7.3, -1.1, -3,
                                     5, 3.8, 4.4 };         //user generated data set

    //INPUT
    cout << "Histogram for original data set: \n";
    generateHistogram(exampleDataOne, 20, 0, 5, 11);

    cout << "Histogram for second data set: \n";
    generateHistogram(exampleDataTwo, 10, -10, 10, 20);

    cout << "Histogram for modified parameters on second data set: \n";
    generateHistogram(exampleDataTwo, 7, -4, 8, 20);

    return 0;
}