//Programmer:   Christopher Carney
//Section:      2
//Lab:          Extra Credit 
//Date:         January 24, 2014
//Description:  Takes in input from the user and places it in a dynamic array which will size
//                  according to the input of the user. Can also output all elements in the array.

#include <iostream>
#include <iomanip>
using namespace std;

const int DEFAULT_CAPACITY = 5;         //the default physical size of the array

int main()
{
    int * data;                         //pointer to data which will hold values in the array
    int logSize;                        //logical size of the data
    int physSize;                       //physical size of data
    int * temp;                         //temportary copy of data for resizing

    int newValue;                       //the value the user inputs
    char userInput;                     //user's choice at the menu


    physSize = DEFAULT_CAPACITY;        //physical size defaults to this at the beginning
    logSize = 0;                        //no data in the array to start
    data = new int[physSize];           //point to the new array

    //loops as long as the user wants to continue adding or printing out values in the array
    do
    {
        cout << "[I]nsert a new value --- [D]isplay all values --- [Q]uit program" << endl;

        cin >> userInput;
        userInput = toupper(userInput);      //always keep upper case

        if (userInput == 'I')                //user wants to input values
        {

            cout << "Enter your value: ";
            cin >> newValue;

            if(logSize == physSize)         //array is full so more space needed
            {
                physSize *= 2;              //new max size is twice the previous
                temp = new int[physSize];   //create new temp array to hold data while resizing

                //copy everything into the temp array from data[0..logSize-1]
                for (int i = 0; i < logSize; i++)
                {
                    temp[i] = data[i];
                }

                delete [] data;             //delete the 'old' data (smaller)
                data = temp;                //data is now the bigger temp array
            }

            data[logSize] = newValue;       //now the new value can be added to the array
            logSize++;
        }

        if (userInput == 'D')           //print out all the values in the array so far
        {

            //values from data[0..logSize-1] contain values to be printed
            for (int i = 0; i < logSize; i++)
            {
                cout << data[i] << setw(4);
            }

            cout << endl << endl;
        }

    } while(userInput != 'Q');

    cout << "Thank you! \n";

    return 0;

}