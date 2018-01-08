//Bank account header file

#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED

#include <iostream>

using namespace std;

class bankaccount
{
    protected:
    double initbalance;
    double balance;
    int numDeposits;
    int numWithdrawls;
    double totalDeposits;
    double totalWithdrawls;
    double annualRate;
    double monthlyCharges;
    
    public:
    // Default constructor
    bankaccount()
    {
        balance = 0.00;
        numDeposits = 0;
        numWithdrawls = 0;
        annualRate = 0.00;
        monthlyCharges = 0.00;
        totalDeposits = 0.00;
        totalWithdrawls = 0.00;
    }
    
    // Constructor 2
    bankaccount(double b, double r)
    {
        balance = b;
        annualRate = r;
        initbalance = balance;
        numDeposits = 1;
        totalDeposits = b;
        cout << "Account activated." << endl;
        cout << "Balance: $" << balance << endl;
    }
    
    // Mutator functions
    
        // **deposit function** accepts amount of deposit 
        // and calculates new balance. Also adds 1 to
        // number of deposits
    virtual void deposit(double d)
    {
        balance += d;
        totalDeposits += d;
        numDeposits++;
        cout << "Deposit successful." << endl;
        cout << "Your balance: $" << balance << endl;
    }
        
        // **withdrawl function** accepts amount to withdraw.
        // It subtracts amount from balance.
        // It also adds 1 to number of withdrawls.
    virtual void withdrawl(double w)
    {
        while((balance - w) < 0)
        {
            cout << "You do not have enough funds to make this withdrawl." << endl;
            cout << "How much to withdraw? ";
            cin >> w;
        }
        balance -= w;
        totalWithdrawls += w;
        numWithdrawls++;
        cout << "Withdrawl successful." << endl;
        cout << "Your balance: $" << balance << endl;
    }
    
        // **calcInt** updates the balance by calculating interest earned.
    virtual void calcInt()
    {
        double monthlyInterest;
        double monthlyRate;
        
        monthlyRate = (annualRate/12);
        monthlyInterest = balance * monthlyRate;
        balance = balance + monthlyInterest;
    }
    
    // **monthlyProc** subtracts monthly service charge from balance,
    // calls the calcInt function,
    // and sets the widthdrawls, deposits, and monthly charges to zero.
    virtual void monthlyProc()
    {
       balance = balance - monthlyCharges;
       calcInt();
       cout << "Initial Balance: $" << initbalance << endl;
       cout << "Number of deposits: " << numDeposits << endl;
       cout << "Total amount of deposits: $" << totalDeposits << endl;
       cout << "Number of withdrawls: " << numWithdrawls << endl;
       cout << "Total amount of withdrawls: $" << totalWithdrawls << endl;
       cout << "Service charges: $" << monthlyCharges << endl;
       cout << "Final balance: $" << balance << endl;
       numWithdrawls = 0;
       numDeposits = 0;
       monthlyCharges = 0.00;
    }
};
#endif