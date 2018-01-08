#ifndef CHECKINGACCOUNT_H_INCLUDED
#define CHECKINGACCOUNT_H_INCLUDED

#include <iostream>
#include "bankaccount.h"

using namespace std;

class checkingaccount : public bankaccount
{
    public:
    
    using bankaccount::bankaccount;
    
    double fees;
    
    // derived function checks if balance is enough to make withdrawl. If not, a $15 charge is applied.
    void withdrawl(double w)
    {
       if((balance - w) < 0)
       {
           fees += 15;
           balance -= 15;
           cout << "You do not have sufficient funds. A $15 service fee has been charged." << endl;
           cout << "Balance: $" << balance;
           
       }
       else
            bankaccount::withdrawl(w);  
    }
    
    
    // derived function adds $5 plus $.10 for every withdrawl to monthly charges.
    void monthlyProc()
    {
        monthlyCharges = 5 + (0.10*numWithdrawls);
        bankaccount::monthlyProc();
    }
};

#endif