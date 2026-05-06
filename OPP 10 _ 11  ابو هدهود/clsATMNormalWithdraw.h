#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsATM.h"
#include "clsInputValidate.h"



class clsATMNormalWithdraw : protected clsScreen
{
private:

	static void _NormalWithdraw(clsATM& Client1)
	{
		int Amount = 0; 
		cout << "Enter an amount multiple of 5's: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount % 5 != 0)
		{
			cout << "\nEnter an amount multiple of 5's: ";
			Amount = clsInputValidate::ReadDblNumber();
		}


		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balances is: " << Client1.AccountBalance;
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

	static void ShowNormalWithdrawScreen()
	{
		_DrawScreenHeader("\t  Normal Withdraw Screen..");
	
		clsATM Client1 = CurrentClient;
		                                      
		_NormalWithdraw(Client1);	

		CurrentClient = Client1;
	}
};
