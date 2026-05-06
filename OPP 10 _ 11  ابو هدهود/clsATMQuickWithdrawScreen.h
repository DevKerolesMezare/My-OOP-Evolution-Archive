#pragma once


#include <iostream>
#include "clsScreen.h"

#include "clsInputValidate.h"
#include "Global_ATM.h"

#include "clsATM.h"



using namespace std; 


class clsATMQuickWithdrawScreen : protected clsScreen
{
private:

    static void _PrintClient(clsATM Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

	static void _PrintAmountINScreen()
	{
        cout << "\t\tQuickWithdraw\n\n";
        cout << "\n\t1 :50\t\t2 :100\t\t3 :150\n";
        cout << "\n\t4: 200\t\t5: 400\t\t6 :600\n";
        cout << "\n\t7: 1000\t\t8: 2000\t\t9: 4000\n\n";
	}

    static void _TransactionQuickWithdraw(clsATM& Client1)
    {
        _PrintAmountINScreen();
        cout << "\n\n\n\t\tPlease choose a Number Between[1 - 9] : ";
        short Number = clsInputValidate::ReadShortNumberBetween(1, 9);

        int arr[9] = { 50 , 100 , 150 , 200 , 400 , 600 ,1000 ,2000 ,4000 };

        int Amount = arr[Number - 1];


        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;

            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }


public:

	static void ShowQuickWithdrawScreen()
	{

        _DrawScreenHeader("\t  Quick Withdraw Screen");

        if(CurrentClient.IsEmpty())
        {    
            return; 
        }


        clsATM Client1 = CurrentClient;
        _PrintClient(Client1); 

        cout << "\n\n\t\tFor the quick withdrawal list, click <1>  To cancel the operation <0> : ";
        char answer = clsInputValidate::ReadShortNumberBetween(0, 1);
        if (answer == 0)
            return;

        system("cls"); 

        _TransactionQuickWithdraw(Client1); 
        
        CurrentClient = Client1;
	}

};

