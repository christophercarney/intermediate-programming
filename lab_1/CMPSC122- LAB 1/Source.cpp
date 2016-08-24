//Programmer:   Christopher Carney
//Section:      2
//Lab:          1
//Date:         January 21, 2014
//Description:  This program asks the user for a length in feet and inches
//              and converts it into meters.

#include <iostream>
using namespace std;


void setFeetInches(double& feet, double& inches)
//PRE:  user has either some input to enter in feet or inches
//POST: user has entered in usable data and the feet is stored in feet
//      and the inches are stored in inches
{
    cout << "How many full feet is your object? ";
    cin >> feet;

    cout << "What is the remaining length in inches? ";
    cin >> inches;

    cout << endl;
}


double convertToMeters(double feet, double inches)
//PRE:  Both feet and inches are positive numbers & feet is in feet &
//      inches are in inches.
//POST: FNCTVAL ==  the length of the object in meters but also == to 
//      the length in feet and inches.
{
    double meters;                      //the length of the object in meters to be returned
    double totalFeet;                   //the total number of feet in the object

    totalFeet = feet + (inches / 12);   //total number of feet (as a decimal)
    meters = totalFeet * 0.3048;        //use conversion factor to change to meters

    return meters;
}

int main()
{
    double feet;                        //the number of whole feet the object has
    double inches;                      //the remaining number of inches
    double result;                      //the converted amount in meters

    //INPUT
    setFeetInches(feet, inches);

    //PROCESS
    result = convertToMeters(feet, inches);

    //OUTPUT
    cout << feet << " feet and " << inches << " inches is " << result << " meters.";
    cout << endl;

    return 0;
}