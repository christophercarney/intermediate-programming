// Programmer:   Dylan Fetch & Christopher Carney
// Section:      2
// Lab:          Project 1
// Date:         March 6, 2014
// Description:  Implementation file for timeCard class

#include "TimeCard.h"
#include <iomanip>

TimeCard::TimeCard()
//POST:   a default timeCard object is constructed with pMonth == 1, pDay == 1, pYear == 2014,
//        hours[0..6] == 0 && isApproved == false
{
    pMonth = 1;
    pDay = 1;
    pYear = 2014;

    for(int i = 0; i <= 6; i++)                //determinate loop to set hours[0..6] to zero
    {
        hours[i] = 0;
    }

    isApproved = false;
}

TimeCard::TimeCard(int initMonth, int initDay, int initYear)
//PRE:    initMonth has been initialized, initDay has been initialized, initYear has been initialized
//        1<=initMonth<=12, 1<=initDay<=31, initYear>=2014 && initDay is valid in initMonth
//POST:   a timeCard object is constructed with pMonth set to initMonth, pDay set to initDay, 
//        pYear set to initYear, hours[0..6] == 0 && isApproved == false
{
    pMonth = initMonth;
    pDay = initDay;
    pYear = initYear;

    for(int i = 0; i <= 6; i++)                //determinate loop to set hours[0..6] to zero
    {
        hours[i] = 0;
    }

    isApproved = false;
}

void TimeCard::setMonth(int month)
//PRE:    month has been initialized, 1 <= month <= 12
//POST:   The pMonth in this timeCard is set to month 
{
    pMonth = month;
}

void TimeCard::setDay(int day)
//PRE:    day has been initialized, 1 <=day<= 31
//POST:   The pDay in this timeCard is set to day
{
    pDay = day;
}

void TimeCard::setYear(int year)
//PRE:    year has been initialied, year >= 0
//POST:   The pYear in this timeCard is set to year 
{
    pYear = year;
}

void TimeCard::setHours(double workHours, int day)
//PRE:    workHours has been initialized, workHours >= 0
//        day has been initialized, day must be a named constant [MONDAY...SUNDAY] || 0 <= day <= 6
//POST:   sets hours[day] to workHours
{
    hours[day] = workHours;
}

void TimeCard::setApproval(bool approval)
//PRE:	approval has been initialized
//       approval is false (0) if unapproved || approval is true (1) if approved
//POST:  isApproved in this TimeCard has been set to approval
{
    isApproved = approval;
}

bool TimeCard::getApproval() const
//POST:   FCTVAL == 0 if unapproved || 1 if approved
{
    return isApproved;
}

double TimeCard::getHours(int day) const
//PRE:    day has been initialized, day must be a named constant [MONDAY...SUNDAY] || 0 <= day <= 6
//POST:   FCTVAL == hours worked on specified day
{
    return hours[day];
}

void TimeCard::printDate() const
//POST:   pay period start date from this TimeCard has been printed in MM/DD/YYYY format
{
    cout << setw(2) << setfill('0') << pMonth << "/" << setw(2) << pDay << "/" << setw(4) << pYear;
}

double TimeCard::weekPay(double wage) const
//PRE:    wage has been initialized, wage is in dollars/hour
//POST:   FCTVAL == gross pay for the week on this TimeCard in dollars
{
    double weeklyPay;                       //the weekly pay of the worker in dollars

    weeklyPay = 0;

    for (int i = 0; i < 7; i++)             //goes through the hours[0..6] array and multiplies the 
    {                                       //  wage by the hours worked that day to get the weekly pay
        weeklyPay += hours[i] * wage;
    }

    return weeklyPay;
}

void TimeCard::viewCard() const
//POST:   all information from timecard has been printed in the format:
//        Pay Period Start Date: MM/DD/YYYY
//        Approved?: [Approval]
//        Hours Worked Per Day:
//        Sunday: [Hours worked SUNDAY]
//        ...
//        Saturday: [Hours worked SATURDAY]
{
    cout << endl << "Pay Period Start Date:";
    printDate();
    cout << endl;

    cout << "Approved?: " << boolalpha << isApproved << endl;
    cout << setfill(' ');
    cout << "Hours Worked Per Day:"<<endl;
    cout << setw(10) << "Sunday:" << setw(9) << fixed << setprecision(2) << hours[0] << endl;
    cout << setw(10) << "Monday:" << setw(9) << fixed << setprecision(2) << hours[1] << endl;
    cout << setw(10) << "Tuesday:" << setw(9) << fixed << setprecision(2) << hours[2] << endl;
    cout << setw(10) << "Wednesday:" << setw(9) << fixed << setprecision(2) << hours[3] << endl;
    cout << setw(10) << "Thursday:" << setw(9) << fixed << setprecision(2) << hours[4] << endl;
    cout << setw(10) << "Friday:" << setw(9) << fixed << setprecision(2) << hours[5] << endl;
    cout << setw(10) << "Saturday:" << setw(9) << fixed << setprecision(2) << hours[6] << endl;
    cout << endl;
}