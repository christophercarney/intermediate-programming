//Programmer:   Christopher Carney
//Section:      2
//Lab:          9
//Date:         March 2, 2014
//Description:  This class models a an employee who uses the TimeCard class.

#include <string>
#include "TimeCard.h"
using namespace std;

class Employee
{
    public:
        Employee();
        //POST: a default Employee object is constructed with name = "?", jobTitle = "?", 
        //      hourly wage = 7.25, currentCards = 0, EmployeeCards[0..16] are initialized implicitly

        Employee(string initName, string initJobTitle, double initWage);
        //PRE:  initName has been initialized, initJobTitle has been initialized, initWage has been
        //          initialized and is in dollars
        //POST: name = initName, jobTitle = initJobTitle
        //      hourlyWage = initWage and hourlyWage is in dollars
        //      EmployeeCards[0..16] are initialized implicitly

        void giveTimeCard(TimeCard newCard);
        //PRE:  newCard has been initialized
        //POST: The next empty slot in the EmployeeCards array now holts the newCard object
        //          && current currentCards is increased by 1

        int getNumberOfCards() const;
        //POST: FCTVAL = currentCards, the number of TimeCards the employee currently has 
        //          (the logical size of the TimeCards[] array)

        double getGrossPay() const;
        //POST: FCTVAL = total pay across all timecards from EmployeeCards[0..currentCards-1] in
        //          dollars

        void printAllCards() const;
        //POST: All TimeCards from EmployeeCards[0..currentCards-1] have been printed in the format
        //          [name] | [jobTitle] | [hourlyWage]
        //          #[current card] | Start Period: MM/DD/YYYY | Weekly Pay: $[] 
        //          Worked | mo: [] | tu: [] | we: [] | th: [] | fr: [] | sa:[] | su:[]

        double getHourlyWage() const;
        //POST: FCTVAL == hourly wage in dollars

        void setHourlyWage(double newWage);
        //PRE:  newWage has been initialized, newWage contains the hourly wage of the worker in
        //          dollars
        //POST: The hourlyWage in this TimeCard has been set to newWage

    private:
        string name;                        //the full name of this employee
        string jobTitle;                    //the job title of this employee
        double hourlyWage;                  //the current houly wage of this employee

        TimeCard EmployeeCards[16];         //the array to hold multiple time cards for this employee
        int currentCards;                   //the logical size of the array which holds time cards
};