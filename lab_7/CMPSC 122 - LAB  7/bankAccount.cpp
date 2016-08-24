// Programmer:    Doug Hogan
// Last Modified: February 18, 2014
// Description:   This class models a simple bank account in terms of just a name and balance.

#include "bankAccount.h"

// Class data dictionary for easy reference:
//      string name;          // full name of holder of this account
//      double balance;       // how much money is in this acct, in dollars

	
bankAccount::bankAccount()
// POST: a default bankAccount object is constructed with 
//       name == "?" and balance == 0
{
   name = "?";
   balance = 0;
}

void bankAccount::withdraw(int amount)
// PRE:  amount is in dollars and amount > 0
// POST: amount has been subtracted from balance
{
   balance -= amount; 
}

void bankAccount::deposit(int amount)
// PRE:  amount is in dollars and amount > 0
// POST: amount has been added on to balance
{
   balance += amount; 
}

double bankAccount::getBalance()
// POST: FCTVAL == balance in dollars
{
   return balance;
}