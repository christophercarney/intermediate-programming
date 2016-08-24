//Programmer:   Dylan Fetch & Christopher Carney
//Section:      2
//Lab:          Project 1
//Date:         March 5, 2014
//Description:  This class models a an employee who uses the TimeCard class.

#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

Employee::Employee()
//POST: a default Employee object is constructed with name = "?", jobTitle = "?", 
//      hourly wage = 7.25 in dollars, currentCards = 0, EmployeeCards[0..15] is initialized implicitly
{
    name = "?";
    jobTitle = "?";
    hourlyWage = 7.25;

    currentCards = 0;
    //EmployeeCards[16] -- implicit default constructor call
}

Employee::Employee(string initName, string initJobTitle, double initWage)
//PRE:  initName has been initialized, initJobTitle has been initialized, initWage has been
//          initialized and is in dollars
//POST: An Employee object has been constructed with
//          name = initName, jobTitle = initJobTitle
//          hourlyWage = initWage and hourlyWage is in dollars
//          EmployeeCards[0..15] are initialized implicitly
{
    name = initName;
    jobTitle = initJobTitle;
    hourlyWage = initWage;
    
    currentCards = 0;
    //EmployeeCards[16] -- implicit default constructor call
}

void Employee::giveTimeCard(TimeCard * newCard)
//POST: a pointer to a TimeCard has been added to this Employee's timecards array
{
    if (currentCards < MAX_CARDS)
    {
        EmployeeCards[currentCards] = newCard;        //give this employee the new TimeCard object
        currentCards++;                               
    }
}

void Employee::setHourlyWage(double newWage)
//PRE:  newWage has been initialized, newWage contains the hourly wage of the worker in
//          dollars
//POST: The hourlyWage in this Employee has been set to newWage
{
    hourlyWage = newWage;
}

void Employee::setName(string newName)
//PRE:  newName is initialized && newName is the name of the employee
//POST: The name in this Employee has been set to newName
{
    name = newName;
}

void Employee::setTitle(string newTitle)
//PRE:  newTitle is initialized && newTitle is the job title of the employee
//POST: The jobTitle in this Employee has been set to newName 
{
    jobTitle = newTitle;
}

void Employee::readTimeCards(string fileName, Queue & supervisor)
//PRE:   fileName exists and is set to the exact string name of the .txt file located
//          in the same directory as the program.
//       the .txt file is formatted as 
//       APPROVAL MM DD YYYY Su Mo Tu We Th Fr Sa && Su..Sa correspond to the hours
//          worked on that day 
//       APPROVAL == 0 if unapproved && APPROVAL == 1 if approved
//       1 <= MM <= 12 && is an integer, 1 <= DD <= 31, is an integer, && is valid in the MM
//          0 <= YYYY && is an integer
//       Su..Sa >= 0 && are doubles
//       supervisor has been initialized
//POST:  A pointer to a new TimeCard object  that has been created && the pointer has been added to 
//          this employee's array of TimeCards
//       If the TimeCard is not approved it has been added to the supervisor queue
{
    bool fileApproval;      //the approval status of the timecard from the file
    int fileMonth;          //the starting month of the pay period from the file
    int fileDay;            //the starting day of the pay period from the file
    int fileYear;           //the starting year of the pay period from the file

    double fileHours;       //the temporary variable to read in hours from the file
    int counter;            //a counter to keep track of the current day to read in fileHours
    
    if (currentCards < MAX_CARDS)                //only read in files if there is room in the array
    {
        TimeCard * newCard = new TimeCard;      //create a new pointer to a TimeCard to add to
                                                //    EmployeeCards[]

        ifstream inFile(fileName);              //open the specified file 

        if (inFile == false)                    //if the file cannot be read then return
            return;

        inFile >> fileApproval >> fileMonth >> fileDay >> fileYear;   //read in values to the temp file
                                                                      //    variables 
        (*newCard).setApproval(fileApproval);                         //set the file Approval status
        (*newCard).setMonth(fileMonth);                               //set the starting month
        (*newCard).setDay(fileDay);                                   //set the starting day
        (*newCard).setYear(fileYear);                                 //set the starting year

        int counter = 0;                                       //start the counter on SUNDAY
        while(inFile >> fileHours)                             //read in while there are values in
        {                                                      //    the file.
            (*newCard).setHours(fileHours, counter);           //set the hours of the current day to 
            counter++;                                         //    what they are in the file
        }

        if((*newCard).getApproval() == false)                 //if the file is not approved pointer must
        {                                                     //     be added to the supervisor queue
            supervisor.enqueue(newCard);
        }

        EmployeeCards[currentCards] = newCard;               //add TimeCard pointer to this Employee's
                                                             //      TimeCard pointer array
        currentCards++;

        inFile.close();                                     //close the file
    }
}

int Employee::getNumberOfCards() const
//POST: FCTVAL = currentCards, the number of TimeCards the employee currently has 
//          (the logical size of the TimeCards[] array)
{
    return currentCards;                        
}

string Employee::getName() const
//POST: FCTVAL == name, the name of this employee
{
    return name;
}

double Employee::getGrossPay() const
//POST: FCTVAL = total pay across all timecards from EmployeeCards[0..currentCards-1] in
//          dollars
{
    double grossPay;                            //the money made accross all time cards in dollars

    grossPay = 0;                               //the initial gross pay is $0
    
    for (int i = 0; i < currentCards; i++)                      //go through all the cards this Employee 
    {                                                           //  has, calculating weekly pay
                                                                //  && adding to gross pay
        grossPay += (*EmployeeCards[i]).weekPay(hourlyWage);
    }

    return grossPay;                           
}

double Employee::getHourlyWage() const
//POST: FCTVAL == hourly wage in dollars/hour
{
    return hourlyWage;
}

void Employee::printInfo() const
//POST: Basic info about this Employee has been printed in the format:
//      [name] | [jobTitle] | Hourly Wage: $[hourlyWage] | Current Timecards: [currentCards]
{
    cout << name << " | " << jobTitle << " | Hourly Wage: $";           //details of the employee
    cout << setprecision(2) << fixed << hourlyWage;                     //formatted currency value
    cout << " | " << "Current Timecards: " << currentCards << endl;    
}

void Employee::printAllCards() const
//POST: All TimeCards from EmployeeCards[0..currentCards-1] have been printed in the format
//          [name] | [jobTitle] | Hourly Wage: $[hourlyWage]
//          #[current card] 
//          Pay Period Start Date: MM/DD/YYYY
//          Approved?: [Approval]
//          Hours Worked Per Day:
//          Sunday: [Hours worked SUNDAY]
//          ...
//          Saturday: [Hours worked SATURDAY]
{
    printInfo();                                //print basic heading info a/b employee                                                                        
    
    for (int i = 0; i < currentCards; i++)      //start at the first TimeCard and go from
    {                                           //EmployeeCards[0..currentCards-1] & output all info
        cout << "Card #" << i+1 << endl;        //output which card it is about to display
        (*EmployeeCards[i]).viewCard();         //prints all the info of the card
        cout << endl << endl;                   
    }

    return;
}