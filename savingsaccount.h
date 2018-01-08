#ifndef SAVINGSACCOUNT_H_INCLUDED
#define SAVINGSACCOUNT_H_INCLUDED

#include <iostream>
#include "bankaccount.h"

using namespace std;

class savingsaccount : public bankaccount
{
   public:
   
   using bankaccount::bankaccount;
   
   int active;
   
   /* Status Function checks if the balance has fallen below $25. If so, a flag variable is tripped */
   void status()
   {
     if(balance < 25.00)
         active = 0;
      else
         active = 1;
   }
   
   /* derived function checks status before call base class function */
   void withdrawl(double w)
   {
      status();
      if(active == 1)
      {
         bankaccount::withdrawl(w);
      }
      else
      {
         cout << "You do not have enough funds in your account to make a withdrawl." << endl;
      }
         
   }
   
   /* derived function checks status before call base class function */
   void deposit(double d)
   {
      status();
      if(active == 1)
      {
         bankaccount::deposit(d);
      }
      else if(active == 0 && (balance + d) >= 25.00)
         {
           bankaccount::deposit(d);
         }
      else
         cout << "Desposit unsuccessful. Account inactive." << endl;
   }
   
   /* derived function calculates a $1 charge for every withdrawl over 4 */
   void monthlyProc()
   {
      double charges = (numWithdrawls - 4);
      if(numWithdrawls > 4)
      {
         monthlyCharges = charges;
         balance = balance - monthlyCharges;
         cout << "You've been charged $" << charges << " in withdrawl fees." << endl;
      }
      status();
      bankaccount::monthlyProc();
   }
};

#endif