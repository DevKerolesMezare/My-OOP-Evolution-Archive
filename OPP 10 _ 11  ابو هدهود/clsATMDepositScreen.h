#pragma once

#include <iostream>

#include "clsATM.h"
#include "clsScreen.h" 
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std; 


class clsATMDepositScreen :protected clsScreen
{
private: 
	static void _Deposit(clsATM &Client1)
	{
		int Amount; 
		cout << "\nEnter a positive Deposit Amount? "; 
		Amount = clsInputValidate::ReadDblNumberBetween(1 , 1000000);

		char Answer = 'n';
		cout << "\nAre you sure you want perform this transaction? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client1.Deposit(Amount); 	
			cout << "\nDone Successfully. New balance Is: ";
			cout << Client1.AccountBalance;
		}
	}

public:

	static void ShowATMDepositScreen()
	{
		_DrawScreenHeader("\t  Deposit Screen... ");

		clsATM Client1 = CurrentClient;
		_Deposit(Client1);

		CurrentClient = Client1;
	}
};

