// Programmer:   Dylan Fetch & Christopher Carney
// Section:      2
// Lab:          Project 1
// Date:         March 5, 2014
// Description:  Header file for timeCard class

#ifndef TimeCard_H
#define TimeCard_H

#include <iostream>
using namespace std;

const int SUNDAY = 0;                    //the named constant for Sunday
const int MONDAY = 1;                    //the named constant for Monday
const int TUESDAY = 2;                   //the named constant for Tuesday
const int WEDNESDAY = 3;                 //the named constant for Wednesday
const int THURSDAY = 4;                  //the named constant for Thursday
const int FRIDAY = 5;                    //the named constant for Friday
const int SATURDAY = 6;                  //the named constant for Saturday
const int DAYS_OF_WEEK=7;                //the constant for the amount of days in a week


class TimeCard
{
    public:
        TimeCard();
        //POST:   a default timeCard object is constructed with pMonth == 1, pDay == 1, pYear == 2014,
        //        hours[0..6] == 0 && isApproved == false

        TimeCard(int initMonth, int initDay, int initYear);
        //PRE:    initMonth has been initialized, initDay has been initialized, initYear has been 
        //          initialized
        //        1<=initMonth<=12, 1<=initDay<=31, initYear>=2014 && initDay is valid in initMonth
        //POST:   a timeCard object is constructed with pMonth set to initMonth, pDay set to initDay, 
        //        pYear set to initYear, hours[0..6] == 0 && isApproved == false

        void setMonth(int month);
        //PRE:    month has been initialized, 1 <= month <= 12
        //POST:   The pMonth in this timeCard is set to month 

        void setDay(int day);
        //PRE:    day has been initialized, 1 <=day<= 31
        //POST:   The pDay in this timeCard is set to day

        void setYear(int year);
        //PRE:    year has been initialied, year >= 0
        //POST:   The pYear in this timeCard is set to year 

        void setHours(double workHours, int day);
        //PRE:    workHours has been initialized, workHours >= 0, day has been initialized &&
        //            day must be a named constant [MONDAY...SUNDAY] || 0 <= day <= 6
        //POST:   sets hours[day] to workHours

        void setApproval(bool approval);
        //PRE:	approval has been initialized
        //       approval is false (0) if unapproved || approval is true (1) if approved
        //POST:  isApproved in this TimeCard has been set to approval

        bool getApproval() const;
        //POST:   FCTVAL == 0 if unapproved || 1 if approved

        double getHours(int day) const;
        //PRE:    day has been initialized, day must be a named constant [MONDAY...SUNDAY] 
        //            || 0 <= day <= 6
        //POST:   FCTVAL == hours worked on corresponing day

        void printDate() const;
        //POST:   pay period start date from this TimeCard has been printed in MM/DD/YYYY format

        double weekPay(double wage) const;
        //PRE:    wage has been initialized, wage is in dollars/hour
        //POST:   FCTVAL == gross pay for the week on this TimeCard in dollars

        void viewCard() const;
        //POST:   all information from timecard has been printed in the format:
        //        Pay Period Start Date: MM/DD/YYYY
        //        Approved?: [Approval]
        //        Hours Worked Per Day:
        //        Sunday: [Hours worked SUNDAY]
        //        ...
        //        Saturday: [Hours worked SATURDAY]

    private:
        int pMonth;                     //the month of the start of the pay period
        int pDay;                       //the day of the start of the pay period
        int pYear;                      //the year of the start of the pay period

        bool isApproved;                //the approval status of the time card

        double hours[DAYS_OF_WEEK];     //the hours worked per day in dollars/hour
};

#endif