#include <iostream>
#include <iomanip>
#include "bankaccount.h"
#include "savingsaccount.h"
#include "checkingaccount.h"

using namespace std;

int main() 
{
                        // Variables
    int selection;
    double amount;
    
    cout << fixed << setprecision(2);           // display to two decimal places
    
    while(selection != 3)
    {
    cout << "WELCOME TO BANQUE D'EARLYSVILLE\n" 
    "********       Main Menu       *********\n"    // Main Menu
    "******* please select an option ********\n"
    "****** 1. Create Savings Account *******\n"
    "****** 2. Create Checking Account ******\n"
    "****** 3. Exit *************************\n";
    cin >> selection;
   
                                                                // Checking for bad input
    while(selection != 1 && selection != 2 && selection != 3)
    {
        cout << "Invalid selection.\nPlease select 1, 2, or 3: ";
        cin >> selection;
    }
   
   
                            // Creating a Savings Account 
    if(selection == 1)
    {
        
        cout << "How much will you deposit today? ";    // get initial deposit
        cin >> amount;
        savingsaccount savings(amount,0.00);            // create object
        
        while(selection != 4)
        {
            cout << "\n*** Savings Account Menu ***\n"            // secondary menu
                "1. Make a deposit\n"
                "2. Make a withdrawl\n"
                "3. Display monthly report\n"
                "4. Exit\n";
            cin >> selection;
            
            while(  selection != 1 &&
                    selection != 2 &&
                    selection != 3 &&
                    selection != 4)
            {   
                cout << "Invalid selection.\nPlease select 1, 2, 3, or 4: ";
                cin >> selection;
            }
            
            if(selection == 1)
            {
                cout << "How much will you deposit today? ";    // make a deposit
                cin >> amount;
                savings.deposit(amount);
            }
            else if(selection == 2)
            {
                cout << "How much to withdraw? ";               // make a withdrawl 
                cin >> amount;
                savings.withdrawl(amount);
            }
            else if(selection == 3)
            {
                    cout << "Running monthly report..." << endl; // monthly report
                    savings.monthlyProc();
            }
            else
                break;
        }
    }
    
    
                            // Creating a Checking Account
    else if(selection == 2)
    {
        cout << "How much will you deposit today? ";        // get initial deposit
        cin >> amount;
        checkingaccount checking(amount,0.00); // create object 
        
        while(selection != 4)
        {
            cout << "\n\n*** Checking Account Menu ***\n"              // secondary menu
                "1. Make a deposit\n"
                "2. Make a withdrawl\n"
                "3. Display monthly report\n"
                "4. Exit\n";
            cin >> selection;
            
            while(  selection != 1 &&
                    selection != 2 &&
                    selection != 3 &&
                    selection != 4)
            {   
                cout << "Invalid selection.\nPlease select 1, 2, 3, or 4: ";
                cin >> selection;
            }
            
            if(selection == 1)
            {
                cout << "How much will you deposit today? "; // making a deposit
                cin >> amount;
                checking.deposit(amount);
            }
            else if(selection == 2)
            {
                cout << "How much to withdraw? ";           // making a withdrawl
                cin >> amount;
                checking.withdrawl(amount);
            }
            else if(selection == 3)
            {
                cout << "Running monthly report..." << endl; // monthly report
                checking.monthlyProc();
            }
            else
                break;
        }
    }
}
    return 0;
}

