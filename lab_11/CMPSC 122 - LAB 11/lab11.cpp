//Programmer:   Christopher Carney
//Section:      2
//Lab:          11
//Date:         March 24, 2014
//Description:  This program demonstrates how to use recursion in order to solve a how many
//                  stars should be printed on one line, and then printing those stars

#include <iostream>

using namespace std;

int const LINES_TO_PRINT = 54;                   //the constant for the number of lines to print

void printStars(int starsToPrint)
//PRE:  starsToPrint is initialized, starsToPrint >= 0
//POST: the number asterisks thats have been printed to the console = starsToPrint
{
    //determinate loop to print out the number of stars = starsToPrint
    for (int i = 0; i < starsToPrint; i++)
    {
        cout << "*";
    }
}

int starLine(int lineNumber)
//PRE:  lineNumber is initialized, lineNumber >= 1 & is contains the value for the line which to 
//          calculate the number of stars on
//POST: FCTVAL == the number of stars on the line lineNumber
{
    if (lineNumber == 1)                            //base case when the line to print is 1
        return 1;
    else if (lineNumber == 2)                       //base case when the line to print is 2
        return 2;
    else if (lineNumber == 3)                       //base case when the line to print is 3
        return 3;
    else if (lineNumber % 3 == 0)                   //recursive case when the line to print is an
                                                    //   exact multiple of 3. Find 2 times the 
        return 2 * starLine(lineNumber /3 );   //   number of stars 2/3 up the screen
    else                                            //recursive case for all other values to
                                                    //   find 2 more than the preceeding line
        return starLine(lineNumber - 1) + 2;

}

double RecurTable(double A[][100], int r, int c)
{
    if (r == 0 && c == 0)
        A[0][0] = 2;
    else if (r > 0 && c == 0)
        A[r][0] = RecurTable(A, r-1, 0) + pow(2, r);
    else if (r == 0 && c > 0)
        A[0][c] = RecurTable(A, 0, c-1) + 4;
    else
        A[r][c] = RecurTable(A, r-1, c-1) + (RecurTable(A, r-1, c) + RecurTable(A, r, c-1)) / 2;

    cout << flush << A[r];
    return A[r][c];       
}

int main()
{
    int lines;                      //the number of stars to print on a line
    double A[100][100];

    //RecurTable(A, 50, 75);

    //determinate loop to print out stars for lines 1-54 recursively
    for (int i = 1; i <= LINES_TO_PRINT; i++)
    {
        lines = starLine(i);

        printStars(lines);
        cout << " (" << lines << ")\n\n";
    }

    return 0;
}