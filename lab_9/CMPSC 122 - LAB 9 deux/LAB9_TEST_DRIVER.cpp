//Programmer:   Christopher Carney
//Section:      2
//Lab:          9
//Date:         March 2, 2014
//Description:  This is a test driver for the Employee class which uses the TimeCard class

#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"

using namespace std;

int main()
{
    TimeCard TC1;
    TimeCard TC2;
    TimeCard TC3;

    Employee newEmploy;
    Employee newEmploy2("Chris Carney", "Software Engineer Intern", 15.25);

    //set hours worked for three time cards to test
    for(int i = 0; i < 5; i++)
    {
        TC1.setHoursWorked(DAY_NAMES[i], 8);
        TC2.setHoursWorked(DAY_NAMES[i], 7);
        TC3.setHoursWorked(DAY_NAMES[i], 8);
    }
    
    newEmploy2.giveTimeCard(TC1);
    newEmploy2.giveTimeCard(TC2);
    newEmploy2.giveTimeCard(TC3);

    cout << "Employee 1's Time Cards: " << endl;
    newEmploy.printAllCards();

    cout << "\nEmployee 2's Time Cards: " << endl;
    newEmploy2.printAllCards();

    cout << "Employee 1 Cards: " <<  newEmploy.getNumberOfCards() << endl;
    cout << "Employee 2 Cards: " <<  newEmploy2.getNumberOfCards() << endl;

    cout << "\nEmployee 1 Gross Pay: $" << setprecision(2) << fixed << newEmploy.getGrossPay();
    cout << "\nEmployee 2 Gross Pay: $" <<  setprecision(2) << fixed << newEmploy2.getGrossPay();

    return 0;
}