#pragma once



#include <iostream>
#include "iomanip"


#include "clsInputValidate.h"
#include "clsString.h"
#include "clsScreen.h"


#include "clsAddNewManigerScreen.h"
#include "clsFindManigerScreen.h"
#include "clsUpdateManigerScreen.h"
#include "clsDeleteManigerScreen.h"
#include "clsListManigersScreen.h"
#include "clsLoginRegisterScreen_Maniger.h"


class clsManigerScreen : protected clsScreen
{
private:

	enum enMangerMenueOptions
	{
		eListManagers = 1,
		eAddManiger = 2,
		eFindManiger = 3,
		eUpdateManiger = 4,
		eDeleteManiger = 5,
		eRegiserLogIn = 6,
		eLogout = 7
	};

	static short _ReadManigerOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,7, "Enter Number between 1 to 7? ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMangerScreen();
	}


	static void _ShowListManigersScreen() 
	{
	//	cout << "\nList Manigers Screen will be here..";

		clsListManigersScreen::ShowListManigersScreen();
	};

	static void _ShowAddManigerScreen() 
	{
		//cout << "\nAdd Maniger Screen will be here..";

		clsAddNewManigerScreen::ShowAddManagerScreen();
	};

	static void _ShowFindManigerScreen() 
	{
		//cout << "\nFind Maniger Screen will be here..";
		clsFindManigerScreen::ShowFindManigerScreen();

	};

	static void _ShowUpdateManigerScreen() 
	{
		//cout << "\nUpdate Maniger Screen will be here..";
		clsUpdateManigerScreen::_ShowUpdateManigerScreen();
	};

	static void _ShowDeleteManigerScreen() 
	{
	//	cout << "\nDelete Maniger Screen will be here..";

		clsDeleteManigerScreen::ShowDeleteManigerScreen();
	};

	static void _ShowRegiserLogInScreen()
	{
		//cout << "\n\t\tRegiserLogIn Screen Will be here.";
		clsLoginRegisterScreen_Maniger::ShowLoginRegisterScreen();
	}


	static void _PerformManagersOptions(enMangerMenueOptions Option)
	{

		switch (Option)
		{
		case clsManigerScreen::eListManagers:
			system("cls");
			_ShowListManigersScreen();
			_GoBackToMainMenue();
			break;

		case clsManigerScreen::eAddManiger:
			system("cls");
			_ShowAddManigerScreen();
			_GoBackToMainMenue();
			break;

		case clsManigerScreen::eFindManiger:
			system("cls");
			_ShowFindManigerScreen();
			_GoBackToMainMenue();
			break;

		case clsManigerScreen::eUpdateManiger:
			system("cls");
			_ShowUpdateManigerScreen();
			_GoBackToMainMenue();
			break;

		case clsManigerScreen::eDeleteManiger:
			system("cls");
			_ShowDeleteManigerScreen();
			_GoBackToMainMenue();

			break;

			case clsManigerScreen::eRegiserLogIn:
			system("cls");
			_ShowRegiserLogInScreen();
			_GoBackToMainMenue();

			break;

		case clsManigerScreen::eLogout:
			system("cls");
			break;
		}

	}


public:

	static void ShowMangerScreen()
	{
		system("cls");


		if (!CheckManigersAccessRights(clsManiger::enPermissions::pManiger))
		{
			return;
		}

		_DrawScreenHeader("\t  Maniger Main Screen..");

		cout << setw(38) << left << "" << "===========================================\n";
		cout << setw(38) << left << "" << "\t\t\Maniger Menue\n";
		cout << setw(38) << left << "" << "===========================================\n";
		cout << setw(38) << left << "" << "\t[1] Show Manigers List.\n";
		cout << setw(38) << left << "" << "\t[2] Add New Maniger.\n";
		cout << setw(38) << left << "" << "\t[3] Find Maniger.\n";
		cout << setw(38) << left << "" << "\t[4] Update Maniger Info.\n";
		cout << setw(38) << left << "" << "\t[5] Delete Maniger.\n";
		cout << setw(38) << left << "" << "\t[6] View Managers Logins.\n";
		cout << setw(38) << left << "" << "\t[7] Logout.\n";
	
		cout << setw(38) << left << "" << "===========================================\n";

		_PerformManagersOptions((enMangerMenueOptions)_ReadManigerOptions());
	}
};

