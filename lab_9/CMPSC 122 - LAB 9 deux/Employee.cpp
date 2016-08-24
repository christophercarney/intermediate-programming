//Programmer:   Christopher Carney
//Section:      2
//Lab:          9
//Date:         March 2, 2014
//Description:  This class models a an employee who uses the TimeCard class.

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee()
//POST: a default Employee object is constructed with name = "?", jobTitle = "?", 
//      hourly wage = 7.25, currentCards = 0, EmployeeCards[0..16] are initialized implicitly
{
    name = "?";
    jobTitle = "?";
    hourlyWage = 7.25;

    currentCards = 0;
    //EmployeeCards[16] -- implicit default constructor call
}

Employee::Employee(string initName, string initJobTitle, double initWage)
//PRE:   initName has been initialized, initJobTitle has been initialized, initWage has been
//          initialized and is in dollars
//POST: name = initName, jobTitle = initJobTitle
//      hourlyWage = initWage and hourlyWage is in dollars
//      EmployeeCards[0..16] are initialized implicitly
{
    name = initName;
    jobTitle = initJobTitle;
    hourlyWage = initWage;
    
    currentCards = 0;
    //EmployeeCards[16] -- implicit default constructor call
}

void Employee::giveTimeCard(TimeCard newCard)
//POST: a default TimeCard object has been constructed & current TimeCards is increased by 1
{
    EmployeeCards[currentCards] = newCard;                   //give this employee the new TimeCard
                                                             //   object
    currentCards++;                                          //increment employee cards by 1

    return;
}

int Employee::getNumberOfCards() const
//POST: FCTVAL = currentCards, the number of TimeCards the employee currently has 
//          (the logical size of the TimeCards[] array)
{
    return currentCards;                        //return the amount of cards this employee has
}

double Employee::getGrossPay() const
//POST: FCTVAL = total pay across all timecards from EmployeeCards[0..currentCards-1] in
//          dollars
{
    double grossPay;                            //the amount of money made accross all time cards

    grossPay = 0;                               //the initial gross pay is 0
    
    //go through all the cards this Employee currently has, calculating weekly pay for each time card
    //   and adding it to gross pay until there are no cards left
    for (int i = 0; i < currentCards; i++)
    {
        grossPay += EmployeeCards[i].calculateWeeklyPay(hourlyWage);
    }

    return grossPay;                            //return the gross pay
}

void Employee::printAllCards() const
//POST: All TimeCards from EmployeeCards[0..currentCards-1] have been printed in the format
//          [name] | [jobTitle] | [hourlyWage]
//          #[current card] | Start Period: MM/DD/YYYY | Weekly Pay: $[] 
//          Worked | mo: [] | tu: [] | we: [] | th: [] | fr: [] | sa:[] | su:[]
{
    cout << name << " | " << jobTitle << " | Hourly Wage: $" << hourlyWage << endl;     //details of
                                                                                        //  employee
    
    //start at the first TimeCard and go from EmployeeCards[0..currentCards-1] and print out all
    //  the information held for that current card
    for (int i = 0; i < currentCards; i++)
    {
        cout << "Card #" << i+1 << " | ";                //output which card it is about to display
        EmployeeCards[i].printTimeCard(hourlyWage);      //prints all the info of the card
        cout << endl << endl;
    }

    return;
}

double Employee::getHourlyWage() const
//POST: FCTVAL == hourly wage in dollars
{
    return hourlyWage;
}

void Employee::setHourlyWage(double newWage)
//PRE:  newWage has been initialized, newWage contains the hourly wage of the worker in
//          dollars
//POST: The hourlyWage in this TimeCard has been set to newWage
{
    hourlyWage = newWage;                       //set the hourly wage to the requested new wage

    return;
}