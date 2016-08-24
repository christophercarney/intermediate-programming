//Programmer:   Dylan Fetch & Christopher Carney
//Section:      2
//Lab:          Project 1
//Date:         March 7, 2014
//Description:  This driver uses the Employee, TimeCard, and Queue classes to simulate
//                  a payroll program for a supervisor.

#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

const int MAX_EMPLOYEES = 5;                //the maximum number of employees a supervisor can have

void supervisorCheckEmployee(Employee & selectedEmployee, Queue & supervisor)
//PRE:  selectedEmployee has been initialized
//      supervisor has been initialized
//POST: menu for a single Employee object has been displayed && the user has been prompted to add a 
//          TimeCard to an employee or exit the menu
{
    int select;                                 //the menu option selected by the user
    string fileName;                            //the name of the timecard file
    
    do                                          //continue to display the menu for the specific 
    {                                           //  employee while user d/n want to exit
        cout << "\nSelect an option: \n";

        selectedEmployee.printInfo();           //print name & other basic info for employee

        cout << "1. Add a time card\n";
        cout << "2. Back\n";

        cin >> select;

        switch(select)                          //different cases based on user selection
        {
            case 1:                             //user specifies timecard file to give to employee
                cout << "Please enter the name of the file with the file extension: ";
                cin >> fileName;
                selectedEmployee.readTimeCards(fileName, supervisor);
                break;

            case 2:                             //exits out of the current menu
                return;

            default:                            //otherwise input cannot be understood & re-prompt 
                "\nCould not understand input...please try again: \n";
                cin >> select;
        }

    } while (select != 2);
}

void supervisorEmployeeOptions(Employee currentEmployees[], Queue & supervisor)
//PRE:  currentEmployees[0..MAX_EMPLOYEES] has been initialized
//      supervisor has been initialized
//POST: Each employee's name has been displayed and the user has been prompted for
//          input on which employee to select or to exit the menu
{
    int select;                                     //the option selected by the user

    do                                              //continue to prompt the user until they want
    {                                               //  to go back in the menu system
         cout <<"\tSelect an Employee: \n";

         for (int i = 0; i < MAX_EMPLOYEES; i++)         //display each employee in the supervisor's 
         {                                               //   Employee array by name 
            cout << "\t" << i + 1 << ". " << currentEmployees[i].getName() << endl;
         }

        cout << "\t" << MAX_EMPLOYEES + 1 << ". Back\n";

        cout << "\t";
        cin >> select;

        if (select > MAX_EMPLOYEES + 1 || select <= 0)                          //only usable input 
            cout << "Could not understand input...please try again: ";          //1..MAX_EMPLOYEES+1

        else if (select < (MAX_EMPLOYEES + 1))                                  //if selection is an 
            supervisorCheckEmployee(currentEmployees[select - 1], supervisor);  //  employee go to 
                                                                                //  specific menu
        else                                                                    //otherwise exit menu
            return;

    } while (select != MAX_EMPLOYEES + 1);
}

void supervisorCheckQueue(Queue & supervisor)
//PRE:  supervisor has been initialized
//POST: pending queue has been displayed to the user and each timecard has been prompted for 
//          approval and been removed from the queue.
{
    char approved;                                //the supervisor's option to approve the time card
    
    if (supervisor.isEmpty() == true)            //if the queue is empty nothing needs to execute
    {
        cout << "\nThe pending queue is empty.\n";
        return;        
    }
    else                                        //otherwise display queue 
    {
        while (supervisor.isEmpty() == false)   //while the queue isn't empty, display the next card
        {                                       //   in the queue
            (*supervisor.viewFront()).viewCard();
            cout << "Approve Card? (Y/N)\n";

            cin >> approved;
            approved = toupper(approved);       //make sure all input is uppercase

            switch (approved)                   //diferent cases based on if the timecard is approved
            {                                   //    or not
                case 'Y':                       //if approved set approval to true and dequeue
                    (*supervisor.dequeue()).setApproval(true);
                    break;

                case 'N':                       //if not approved leave approval false and dequeue
                    (*supervisor.dequeue()).setApproval(false);
                    break;

                default:                       //if input not in y/n format then re-prompt
                    cout << "Could not understand input...please try again: ";
                    cin >> approved;
            }
        }
    }
}

void supervisorMainMenu(Employee currentEmployees[], Queue & supervisor)
//PRE:  currentEmployees[0..MAX_EMPLOYEES] has been initialized 
//      supervisor has been initialized
//POST: main menu displaying options to check queue, check employees, and quit program have been
//          displayed && user has been prompted for input
{
    int select;                                 //the option selected by the user

    do                                          //a loop to continue the menu while the user has
    {                                           //    not exited.
        cout << "Enter Menu Numbers: \n";
        cout << "1. Check Queue\n";
        cout << "2. Check Employees\n";
        cout << "3. Quit\n";

        cin >> select;

        switch(select)                          //test cases corresponding to the menu numbers of
        {                                       //      the prompt
            case 1:                             //send superviosor to check the queue 
                supervisorCheckQueue(supervisor);
                break;

            case 2:                             //send supervisor to the employee options menu
                supervisorEmployeeOptions(currentEmployees, supervisor);
                break;

            case 3:                             //exit the program
                return;

            default:                            //if select is not 1..3 then re-try input
                cout << "Could not understand input...please try again: ";
                cin >> select;
        }
    } while (select != 3);
}

int main()
{
    Queue supervisor;                                           //the supervisor's queue to maintain

    Employee currentEmployees[MAX_EMPLOYEES];                   //the supervisor's Employee array 
    
    //hardcode 5 employees for supervisor
    currentEmployees[0].setName("Chris Carney");
    currentEmployees[0].setTitle("Software Engineer");
    
    currentEmployees[1].setName("Dylan Fetch");
    currentEmployees[1].setTitle("Software Engineer");

    currentEmployees[2].setName("John Smith");
    currentEmployees[2].setTitle("Custodian");

    currentEmployees[3].setName("Andrew Ryan");
    currentEmployees[3].setTitle("Marketing Manager");

    currentEmployees[4].setName("Michael James");
    currentEmployees[4].setTitle("Finance Intern");
    
    supervisorMainMenu(currentEmployees, supervisor);           //run the payroll software

    return 0;
}