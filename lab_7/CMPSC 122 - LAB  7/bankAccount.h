// Programmer:    Doug Hogan
// Last Modified: February 18, 2014
// Description:   This class models a simple bank account in terms of just a name and balance.

#include <string>           // string class definition
using namespace std;        // so std:: isn't needed

class bankAccount
{
   public:	
      bankAccount();
      // POST: a default bankAccount object is constructed with 
      //       name == "?" and balance == 0

      void withdraw(int amount);
      // PRE:  amount is in dollars and amount > 0
      // POST: amount has been subtracted from balance

      void deposit(int amount);
      // PRE:  amount is in dollars and amount > 0
      // POST: amount has been added on to balance

      double getBalance();
      // POST: FCTVAL == balance in dollars

   private:
      string name;          // full name of holder of this account
      double balance;       // how much money is in this acct, in dollars
};	
