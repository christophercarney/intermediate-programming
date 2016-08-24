//Programmer:   Christopher Carney
//Section:      2
//Lab:          9
//Date:         February 27, 2014
//Description:  This class models a Time Card for an employee based on the number of hours
//                  worked, period of pay, and the wage of the worker.

#include "TimeCard.h"
#include <iostream>
#include <iomanip>

using namespace std;

TimeCard::TimeCard()
 //POST: a default TimeCard object is constructed with startDate = {1, 1, 2000},
 //           hoursWorked[0..6] = 0
{
    startMonth = 1;
    startDay = 1;
    startYear = 2000;
    
    //set the hours worked for all values in hoursWorked to 0 (the default)
    for (int i = 0; i < 7; i++)
    {
        hoursWorked[i] = 0;
    }
    
}

TimeCard::TimeCard(int month, int day, int year)
//PRE:  month has been initialized, day has been initialized, year has been initialized where 
//          1 <= month <= 12, day >= 1 and does not exceed the days in the given month, &&
//          year >= 0
//POST: A TimeCard object is created with startDate set to initStartDate 
//      and hoursWorked[0..6] = 0
{
    startMonth = month;
    startDay = day;
    startYear = year;

    //set the hours worked for all values in hoursWorked to 0 (the default)
    for (int i = 0; i < 7; i++)
    {
        hoursWorked[i] = 0;
    }

}

void TimeCard::setStartDate(int month, int day, int year)
//PRE:  month has been initialized, day has been initialized, year has been initialized where 
//          1 <= month <= 12, day >= 1 and does not exceed the days in the given month, &&
//          year >= 0
{
    startMonth = month;
    startDay = day;
    startYear = year;

    return;
}

void TimeCard::setHoursWorked(string day, double hoursWorkedDay)
//PRE:  day is initialized, day is the first 2 characters of the day of the week in a string
//          (e.g. Monday = mo, Tuesday = tu, etc)
//      hoursWorkedDay is initialized, 0 <= hoursWorkedDay <= 24
//POST: hoursWorked[] on the subscript parallel to the array week[mo..su] in this TimeCard
//         has been set to hoursWorkedDay
{
    int dayWorked;                              //the subscript of the day worked

    dayWorked = 0;                                              
    while(day != DAY_NAMES[dayWorked])          //scan through week[] array at subscript dayWorked
    {                                           //  if it matches day, stop, b/c that is the day 
        dayWorked++;                            //  requested that the hoursWorkedDay be filled
    }

    hoursWorked[dayWorked] = hoursWorkedDay;    //set hoursWorked for the given day to the
                                                //  hours worked on that day
    return;
}

double TimeCard::getHoursWorked(string day) const
//PRE:  day is initialized, day is the first 2 characters of the day of the week in a string
//          (e.g. Monday = mo, Tuesday = tu, etc)
//POST: FCTVAL == hours worked on the specified day
{
    int dayWorked;                               //the subscript of the day worked

    dayWorked = 0;                                              
    while(day != DAY_NAMES[dayWorked])          //scan through week[] array at subscript dayWorked
    {                                           //  if it matches day, stop, b/c that is the day 
        dayWorked++;                            //  requested that the hoursWorkedDay be filled
    }

    return hoursWorked[dayWorked];
}

void TimeCard::printPayPeriod() const
//POST: pay period start date on this TimeCard has been printed in the format "MM/DD/YYYY"
{

    cout << setfill('0') << setw(2) << startMonth << "/";   //output month w/ appropriate spacing
    cout << setfill('0') << setw(2) << startDay << "/";     //output day w/ appropriate spacing
    cout << setfill('0') << setw(4) << startYear;           //output year w/ appropriate spacing

    return;
}

double TimeCard::calculateWeeklyPay(double employeeWage) const
//POST: FCTVAL = the gross weekly pay for the worker of this TimeCard in dollars
{
    double totalHoursWorked;                                //the total hours worked in a week
    double weeklyPay;                                       //the total weekly pay

    totalHoursWorked = 0;                                   //original totalHours is zero

    //add up all the elements in the hoursWorked[] array to find total hours worked in the week
    for (int i = 0; i < 7; i++)
    {
        totalHoursWorked += hoursWorked[i];
    }

    weeklyPay = totalHoursWorked * employeeWage;   //calculate weeks pay by multiplying 
                                                            //   hours worked by the hourly wage

    return weeklyPay;
}

void TimeCard::printTimeCard(double employeeWage) const
 //POST: All the data in this TimeCard has been printed in the format
//          Start Period: MM/DD/YYYY  |  Weekly Pay: $[]  |  Hourly Wage: $[]   
//          Hours Worked | mo: [] | tu: [] | we: [] | th: [] | fr: [] | sa:[] | su:[]
{ 
    //The following block outputs the first line of the output
    cout << "Start Period: ";  
    printPayPeriod();                                   
    cout << " | " << "Weekly Pay: $" << setprecision(2) << fixed << calculateWeeklyPay(employeeWage);   

    //THe following block outputs the second line of output
    cout << "\nHours Worked | ";
    for (int i = 0; i < 7; i++)       //print out the values of how many hours worked on the 
    {                                 //    corresponding day in the parallel array
        cout << DAY_NAMES[i] << ":" << setprecision(1) << hoursWorked[i] << " | ";
    }

    cout << endl;

    return;
}