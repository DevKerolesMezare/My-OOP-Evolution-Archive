#pragma once



#include <iostream>
#include <iomanip>

#include "clsManiger.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


using namespace std;


class clsListManigersScreen:protected clsScreen
{
private:

	static void _PrintManigerRecord(clsManiger Maniger1)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << Maniger1.ManigerName;
		cout << "| " << setw(20) << left << Maniger1.FullName();
		cout << "| " << setw(16) << left << Maniger1.Phone;
		cout << "| " << setw(21) << left << Maniger1.Email;
		cout << "| " << setw(10) << left << Maniger1.Password;
		cout << "| " << setw(12) << left << Maniger1.Permissions;
	}



public:

	static void ShowListManigersScreen()
	{
		vector <clsManiger> vManigers = clsManiger::GetManigersList();
		string Title = "\t  List Manigers Screen..";
		string Subtitle = "\t   (" + to_string(vManigers.size()) + ")Maniger(s).";

		_DrawScreenHeader(Title , Subtitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(16) << "Phone";
		cout << "| " << left << setw(21) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vManigers.size() < 0)
		{
			return; 
		}

		for (clsManiger& M : vManigers)
		{
			_PrintManigerRecord(M);
			cout << endl; 
		}
		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "______________________________________________\n" << endl;
	}



};

