//Programmer:   Christopher Carney
//Section:      2
//Lab:          8
//Date:         February 27, 2014
//Description:  This class models a Time Card for an employee based on the number of hours
//                  worked, period of pay, and the wage of the worker.

#include <string>
using namespace std;

const int DAYS_IN_WEEK = 7;                                             //the no. days in a week
const string DAY_NAMES[] = {"mo", "tu", "we", "th", "fr", "sa", "su"};    //constants for the days  
                                                                          //  of the week

class TimeCard
{
    public:
        TimeCard();
        //POST: a default TimeCard object is constructed with day = 1, month = 1, year = 2000,
        //           hoursWorked[0..6] = 0, and hourlyWage = 7.25

        TimeCard(int month, int day, int year, double initHourlyWage);
        //PRE:  month has been initialized, day has been initialized, year has been initialized where 
        //          1 <= month <= 12, day >= 1 and does not exceed the days in the given month, &&
        //          year >= 0
        //      initHourlyWage has been initialized, initHourlyWage >= 0.00 and 
        //          initHourlyWage is in dollars
        //POST: A TimeCard object is created with startDate set to initStartDate 
        //      hourlyWage has been set to initHourlyWage
        //      and hoursWorked[0..6] = 0

        void setStartDate(int month, int day, int year);
        //PRE:  month has been initialized, day has been initialized, year has been initialized where 
        //          1 <= month <= 12, day >= 1 and does not exceed the days in the given month, &&
        //          year >= 0
        //POST: The startDate in this TimeCard = newStartDate

        void setHoursWorked(string day, double hoursWorkedDay);
        //PRE:  day is initialized, day is the first 2 characters of the day of the week in a string
        //          (e.g. Monday = mo, Tuesday = tu, etc)
        //      hoursWorkedDay is initialized, 0 <= hoursWorkedDay <= 24
        //POST: hoursWorked[] on the subscript parallel to the array week[mo..su] in this TimeCard
        //         has been set to hoursWorkedDay

        void setHourlyWage(double newWage);
        //PRE:  newWage has been initialized, newWage contains the hourly wage of the worker in
        //          dollars
        //POST: The hourlyWage in this TimeCard has been set to newWage

        double getHoursWorked(string day) const;
        //PRE:  day is initialized, day is the first 2 characters of the day of the week in a string
        //          (e.g. Monday = mo, Tuesday = tu, etc)
        //POST: FCTVAL == hours worked on the specified day

        double getHourlyWage() const;
        //POST: FCTVAL == hourly wage in dollars

        void printPayPeriod() const;
        //POST: pay period start date on this TimeCard has been printed in the format "MM/DD/YYYY"

        double calculateWeeklyPay() const;
        //POST: FCTVAL = the gross weekly pay for the worker of this TimeCard in dollars

        void printTimeCard() const;
        //POST: All the data in this TimeCard has been printed in the format
        //          Start Period: MM/DD/YYYY  |  Weekly Pay: $[]  |  Hourly Wage: $[]   
        //          Hours Worked | mo: [] | tu: [] | we: [] | th: [] | fr: [] | sa:[] | su:[]
 

    private:
        int startMonth;                                 //the pay period's start month
        int startDay;                                   //the pay period's start day
        int startYear;                                  ////the pay period's start year

        double hoursWorked[DAYS_IN_WEEK];               //the hours worked for a day in the week
        double hourlyWage;                              //the employee's hourly wage
           
};
