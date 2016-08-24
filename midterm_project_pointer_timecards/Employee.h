//Programmer:   Dylan Fetch & Christopher Carney
//Section:      2
//Lab:          Project 1
//Date:         March 5, 2014
//Description:  This class models a an employee who uses the TimeCard class.

#ifndef Employee_H
#define Employee_H

#include <string>
#include <fstream>
#include "Timecard.h"
#include "Queue.h"
using namespace std;

const int MAX_CARDS = 16;               //the maximum time cards an employee is allowed to have

class Employee
{
    public:
        Employee();
        //POST: a default Employee object is constructed with name = "?", jobTitle = "?", 
        //      hourly wage = 7.25 in dollars, currentCards = 0, EmployeeCards[0..15] is initialized 
        //      implicitly

        Employee(string initName, string initJobTitle, double initWage);
        //PRE:  initName has been initialized, initJobTitle has been initialized, initWage has been
        //          initialized and is in dollars
        //POST: An Employee object has been constructed with
        //          name = initName, jobTitle = initJobTitle
        //          hourlyWage = initWage and hourlyWage is in dollars
        //          EmployeeCards[0..15] are initialized implicitly

        void giveTimeCard(TimeCard * newCard);
        //POST: a pointer to a TimeCard has been added to this Employee's timecards array
        //POST: The next empty slot in the EmployeeCards array now holts the newCard object
        //          && current currentCards is increased by 1

        void setHourlyWage(double newWage);
        //PRE:  newWage has been initialized, newWage contains the hourly wage of the worker in
        //          dollars
        //POST: The hourlyWage in this Employee has been set to newWage

        void setName(string newName);
        //PRE:  newName is initialized && newName is the name of the employee
        //POST: The name in this Employee has been set to newName

        void setTitle(string newTitle);
        //PRE:  newTitle is initialized && newTitle is the job title of the employee
        //POST: The jobTitle in this Employee has been set to newName 

        void readTimeCards(string fileName, Queue & supervisor);
        //PRE:   fileName exists and is set to the exact string name of the .txt file located
        //          in the same directory as the program.
        //       the .txt file is formatted as 
        //       APPROVAL MM DD YYYY Su Mo Tu We Th Fr Sa && Su..Sa correspond to the hours
        //          worked on that day 
        //       APPROVAL == 0 if unapproved && APPROVAL == 1 if approved
        //          1 <= MM <= 12 && is an integer, 1 <= DD <= 31, is an integer, && is valid in the MM
        //          0 <= YYYY && is an integer
        //       Su..Sa >= 0 && are doubles
        //       supervisor has been initialized
        //POST:  A pointer to a new TimeCard object  that has been created && the pointer has been added
        //          to this employee's array of TimeCards
        //       If the TimeCard is not approved it has been added to the supervisor queue

        int getNumberOfCards() const;
        //POST: FCTVAL == currentCards, the number of TimeCards this employee currently has 
        //          (the logical size of the TimeCards[] array)

        string getName() const;
        //POST: FCTVAL == name, the name of this employee

        double getGrossPay() const;
        //POST: FCTVAL = total pay across all timecards from EmployeeCards[0..currentCards-1] in
        //          dollars

        double getHourlyWage() const;
        //POST: FCTVAL == hourly wage in dollars/hour

        void printInfo() const; 
        //POST: Basic info about this Employee has been printed in the format:
        //      [name] | [jobTitle] | Hourly Wage: $[hourlyWage] | Current Timecards: [currentCards]

        void printAllCards() const;
        //POST: All TimeCards from EmployeeCards[0..currentCards-1] have been printed in the format
        //          [name] | [jobTitle] | Hourly Wage: $[hourlyWage]
        //          #[current card] 
        //          Pay Period Start Date: MM/DD/YYYY
        //          Approved?: [Approval]
        //          Hours Worked Per Day:
        //          Sunday: [Hours worked SUNDAY]
        //          ...
        //          Saturday: [Hours worked SATURDAY]

    private:
        string name;                                //the full name of this employee
        string jobTitle;                            //the job title of this employee
        double hourlyWage;                          //the current houly wage of this employee

        TimeCard * EmployeeCards[MAX_CARDS];        //the array of TimeCard this employee has
        int currentCards;                           //the logical size of the array which holds 
                                                    //   time cards
};

#endif