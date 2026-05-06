
#pragma once


#include <iostream>
#include <string>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsAddStudentScreen.h"
#include "clsFindStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsStudentsListScreen.h"
#include "clsManigerScreen.h"

using namespace std; 



class clsStudentScreen : protected clsScreen
{
private:

	enum enStudentMenueOptions
	{
		eShowStudentList = 1,
		eAddStudent = 2,
		eUpdateStudent = 3,
		eDeleteStudent = 4,
		eFindStudent = 5,
		eManiger = 6,
		eLogout = 7
	};

	static short _ReadStudentMenueOptions()
	{
		cout << setw(38) << "Choose what do you want to do? [1 to 7] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
		return Choice;
	}

	static void _GoBackToStudentMenue()
	{
		cout << "\n\nPress any key to go back to Student Menue...";
		system("pause>0"); 
		ShowStudentScreen();
	}

	static void _ShowListStudentScreen()
    {
		//cout << "\nShow List Student Will Be Here....";

		clsStudentsListScreen::ShowStudentsList();
	};

	static void _AddStudentScreen()
	{
		//cout << "\nShow Add New Student Will Be Here....";
		clsAddStudentScreen::ShowAddStudentScreen();
	};

	static void _FindStudentScreen()
	{
		//cout << "find student will be here/..";
		clsFindStudentScreen::ShowFindStudentScreen();
	}

	static void _UpdateStudentScreen()
	{
		//cout << "\nShow Update Screen Will Be Here....";
		clsUpdateStudentScreen::ShowUpdateStudentScreen();
	};

	static void _DeleteStudentScreen() 
	{
		//cout << "\nShow Delete Screen Will Be Here....";
		clsDeleteStudentScreen::ShowDeleteStudentScreen();
	};

	static void _ShowManigerScreen()
	{
		clsManigerScreen::ShowMangerScreen();
	}

	//static void _Logout() 
	//{
	//	cout << "\nLogout Screen Will Be Here....";

	//};

	static void _PerformStudentMenueOptions(enStudentMenueOptions Option)
	{

		switch (Option)
		{
		case clsStudentScreen::eShowStudentList:
			system("cls");
			_ShowListStudentScreen();
			_GoBackToStudentMenue();
			break;

		case clsStudentScreen::eAddStudent:
			system("cls");
			_AddStudentScreen();
			_GoBackToStudentMenue();
			break;

		case clsStudentScreen::eUpdateStudent:
			system("cls");
			_UpdateStudentScreen();
			_GoBackToStudentMenue();
			break;

		case clsStudentScreen::eDeleteStudent:
			system("cls");
			_DeleteStudentScreen();
			_GoBackToStudentMenue();
			break;

		case clsStudentScreen::eFindStudent:
			system("cls");
			_FindStudentScreen();
			_GoBackToStudentMenue();
			break;	

		case clsStudentScreen::eManiger:
			system("cls");
			_ShowManigerScreen();
			_GoBackToStudentMenue();
			break;	
		
		case clsStudentScreen::eLogout:
			system("cls");
			break;
	
		}
	}


public:
	static void ShowStudentScreen()
	{

		system("cls");
		_DrawScreenHeader("\t  Student Main Screen");

		cout << setw(35) << left << "" << "=========================================\n";
		cout << setw(38) << left << "" << "Student Menue Options...\n";
		cout << setw(35) << left << "" << "=========================================\n";
		cout << setw(38) << left << "" << "[1] List Student.\n";
		cout << setw(38) << left << "" << "[2] Add Student.\n";
		cout << setw(38) << left << "" << "[3] Update Student.\n";
		cout << setw(38) << left << "" << "[4] Delete Student.\n";
		cout << setw(38) << left << "" << "[5] Find Student.\n";
		cout << setw(38) << left << "" << "[6] Managers.\n";
		cout << setw(38) << left << "" << "[7] Logout.\n";
		cout << setw(35) << left << "" << "=========================================\n";
		cout << setw(38) << left << "";
		_PerformStudentMenueOptions((enStudentMenueOptions)_ReadStudentMenueOptions());

	}


};

