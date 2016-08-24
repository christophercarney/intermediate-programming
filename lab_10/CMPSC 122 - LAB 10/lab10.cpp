//Programmer:   Christopher Carney
//Section:      2
//Lab:          10
//Date:         March 20, 2014
//Description:  This program calculates the factorial of a number n! by using recursion

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_OF_FACTORIALS = 12;

int factorialRecur(int n)
//PRE:  n has been initialized, n >= 0
//POST: FCTVAL = the factorial of n (n * (n - 1)!) 
{
    cout << "Recieved " << n << endl;
    if (n == 0)             //base case
    {
        cout << "Returning 1" << endl;
        return 1;
    }
    else                    //recursive case
    {
        cout << "Computing " << n << " * factorialRecur(" << n-1 << ")\n";
        return n * factorialRecur(n - 1);
    }
}

int main()
{
    cout << "Table of Factorials from 0 to " << NUM_OF_FACTORIALS << endl;
     
    //prints out factorial values from 0 to the constant NUM_OF_FACTORIALS in a table
    for (int i = 0; i <= NUM_OF_FACTORIALS; i++)
    {
        cout << setw(2) << i  << "! = " << setw(10) << factorialRecur(i) << endl;
    }

    return 0;
}