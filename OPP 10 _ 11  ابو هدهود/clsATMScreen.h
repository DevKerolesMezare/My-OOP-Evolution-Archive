#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsMainScreen.h"
#include "clsATMQuickWithdrawScreen.h"
#include "clsATMNormalWithdraw.h"
#include "clsATMDepositScreen.h"
#include "clsATMCheckBalances.h"
#include "clsChangePinCode.h"

using namespace std; 




class clsATMScreen : protected clsScreen
{

private:
	enum enATMMenueOptions
	{
		eQuickWithdraw = 1, eNormalWithdraw = 2,
		eDeposit = 3, eCheckBalance = 4,eChangePassword = 5 
	};

	static short ReadATMMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void GoBackToATMScreen()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowATMScreen();
	}

	static void ShowQuickWithdrawScreen()
	{
		//cout << "QuickWithdrawScreen will be here";

		clsATMQuickWithdrawScreen::ShowQuickWithdrawScreen();
	};

	static void ShowNormalWithdrawScreen()
	{
		//cout << "NormalWithdrawScreen will be here";
		clsATMNormalWithdraw::ShowNormalWithdrawScreen();
	};

	static void ShowDepositScreen()
	{
		//cout << "Deposit will be here";
		clsATMDepositScreen::ShowATMDepositScreen();
	};

	static void ShowCheckBalanceScreen()
	{
		//cout << "CheckBalance screen will be here";
		clsATMCheckBalances::ShowCheckBalances();
	};

	static void ShowUpdatePassword()
	{
		//cout << "\n\nChange Password screen will be here";

		clsChangePinCode::ShowChangePasswordScreen();
	}


    static void _PerformATMMenueOption(enATMMenueOptions Options)
	{

		switch (Options)
		{
		case clsATMScreen::eQuickWithdraw:
			system("cls");
			ShowQuickWithdrawScreen();
			GoBackToATMScreen();
			break;

		case clsATMScreen::eNormalWithdraw:
			system("cls");
			ShowNormalWithdrawScreen();
			GoBackToATMScreen();

			break;

		case clsATMScreen::eDeposit:
			system("cls");
			ShowDepositScreen();
			GoBackToATMScreen();

			break;

		case clsATMScreen::eCheckBalance:
			system("cls");
			ShowCheckBalanceScreen();
			GoBackToATMScreen();

	    case clsATMScreen::eChangePassword:
			system("cls");
			ShowUpdatePassword();
			GoBackToATMScreen();

			break;
		}
	}

public:

	static void ShowATMScreen()
	{
		system("cls");
		_DrawScreenHeader("\tATM Main Menue Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  ATM Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Quick Withdraw.\n";
		cout << setw(37) << left << "" << "\t[2] Normal Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Deposit.\n";
		cout << setw(37) << left << "" << "\t[4] Check Balance.\n";
		cout << setw(37) << left << "" << "\t[5] Change Password.\n";
		cout << setw(37) << left << "" << "\t[6] logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformATMMenueOption((enATMMenueOptions)ReadATMMenueOption());
	};
};

