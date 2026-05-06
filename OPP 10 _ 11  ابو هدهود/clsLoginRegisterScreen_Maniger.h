#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>


using namespace std; 



class clsLoginRegisterScreen_Maniger : protected clsScreen
{

private :

	static void _PrintLoginRegisterRecordLine(clsManiger::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.Date;
		cout << "| " << setw(20) << left << LoginRegisterRecord.ManigerName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Perrmissios;
	}



public:
	static void ShowLoginRegisterScreen()
	{

		vector <clsManiger::stLoginRegisterRecord> vLoginRegisterRecord;
		vLoginRegisterRecord = clsManiger::GetLoginRegisterList();

		string title = "\t Login Registr Screen...";
		string Subtitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(title, Subtitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "ManigerName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vLoginRegisterRecord.size() <= 0)
			return; 
		

		for (clsManiger::stLoginRegisterRecord& L : vLoginRegisterRecord)
		{
			_PrintLoginRegisterRecordLine(L);
			cout << endl; 
		}
	}



};

