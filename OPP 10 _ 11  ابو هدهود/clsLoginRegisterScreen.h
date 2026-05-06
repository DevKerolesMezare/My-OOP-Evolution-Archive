#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>


class clsLoginRegisterScreen :protected clsScreen
{

private:

	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckManigersAccessRights(clsUser::enPermissions::pShowLogInScreen))
		{
			return;
		}


		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord; 
		vLoginRegisterRecord = clsUser::GetLoginRegisterList(); 
		
		string title = "\t Login Registr Screen..."; 
		string Subtitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(title, Subtitle); 

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		for (clsUser::stLoginRegisterRecord R : vLoginRegisterRecord)
		{
			PrintLoginRegisterRecordLine(R); 
			cout << endl; 
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};


