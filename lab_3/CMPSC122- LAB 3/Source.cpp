//Programmer:   Christopher Carney
//Section:      2
//Lab:          3
//Date:         January 30, 2014
//Description:  This program is simple practice with pointers and does not accomplish
//                   anything except understanding the purpose of pointers.

#include <iostream>
using namespace std;

int main()
{
    double * p1;
    double * p2;
    double x;
    double y;

    //STEP 1
    p1 = &x;
    *p1 = 1.25;
    cout << "Step 1: x = " << x << ", *p1 = " << *p1 << endl;

    //STEP 2
    y = 2.5;
    p1 = &y;
    cout << "Step 2: x = " << x << ", *p1 = " << *p1 << ", y = " << y << endl;

   //STEP 3
    p2 = new double;
    *p2 = 10;
    cout << "Step 3: x = " << x << ", *p1 = " << *p1 << ", y = " << y << ", *p2 = " << *p2 << endl;

    //STEP 4
    p2 = new double;
    *p2 = *p1 * 2;
    cout << "Step 4: x = " << x << ", *p1 = " << *p1 << ", y = " << y << ", *p2 = " << *p2 << endl;

    //STEP 5
    cout << "\n *p2 * *p1 = " << *p2 * *p1 << endl;

}