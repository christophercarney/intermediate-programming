//Programmer:   Christopher Carney
//Section:      2
//Lab:          8
//Date:         February 27, 2014
//Description:  This program is the test driver for the functions in the TimeCard class

#include <iostream>
#include <iomanip>
#include "TimeCard.h"

using namespace std;

int main()
{

    TimeCard worker1;
    TimeCard worker2(2, 27, 2014, 10.10);

    cout << "Worker 1 Pay Period Start: ";
    worker1.printPayPeriod();
    cout << endl << "Worker 2 Pay Period Start: ";
    worker2.printPayPeriod();

    cout << endl << "Worker 1 Hourly Wage: $" << setprecision(2) << fixed << worker1.getHourlyWage();
    cout << endl << "Worker 2 Hourly Wage: $" << setprecision(2) << fixed << worker2.getHourlyWage();
    

    worker1.setStartDate(8,8,2009);
    cout << endl << "Worker 1 Pay Period Start: ";
    worker1.printPayPeriod();

    worker1.setHourlyWage(20.50);
    cout << endl << "Worker 1 Hourly Wage: $" << setprecision(2) << fixed << worker1.getHourlyWage();

    //fill the hours worked with a standard 8 hour work week
    for (int i = 0; i < 5; i++)
    {
        worker1.setHoursWorked(DAY_NAMES[i], 8);
    }

    //set worker 2 hours worked as a weekend job
    worker2.setHoursWorked("sa", 9.5);
    worker2.setHoursWorked("su", 8.5);

    cout << "\nWorker 1 hours worked on Monday: " << worker1.getHoursWorked("mo") << endl;
    cout << "Worker 2 hours worked on Monday: " << worker2.getHoursWorked("mo") << endl;
    cout << "\nWorker 1 hours worked on Saturday: " << worker1.getHoursWorked("sa") << endl;
    cout << "Worker 2 hours worked on Saturday: " << worker2.getHoursWorked("sa") << endl;

    cout << "\nWorker 1 Weekly Pay: $" << setprecision(2) << fixed << worker1.calculateWeeklyPay();
    cout << "\nWorker 2 Weekly Pay: $" << setprecision(2) << fixed << worker2.calculateWeeklyPay();

    cout << "\nWorker 1's Time Card:\n";
    worker1.printTimeCard();

    cout << "\nWorker 2's Time Card:\n";
    worker2.printTimeCard();


    return 0;
}