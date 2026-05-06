#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsManiger.h"

using namespace std; 


class clsFindManigerScreen : protected clsScreen
{
private:

	static void _PrintManger(clsManiger Maniger1)
	{
		cout << "\Mnanger Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Maniger1.FirstName;
		cout << "\nLastName    : " << Maniger1.LastName;
		cout << "\nFull Name   : " << Maniger1.FullName();
		cout << "\nEmail       : " << Maniger1.Email;
		cout << "\nPhone       : " << Maniger1.Phone;
		cout << "\nUser Name   : " << Maniger1.ManigerName;
		cout << "\nPassword    : " << Maniger1.Password;
		cout << "\nPermissions : " << Maniger1.Permissions;
		cout << "\n___________________\n";

	}


public:

	static void ShowFindManigerScreen()
	{
		_DrawScreenHeader("\t  Find Maniger Screen..");

		string ManigerName = "";
		cout << "\nPlease Enter a Maniger Name? "; 
		ManigerName = clsInputValidate::ReadString();

		while (!clsManiger::IsMangerExict(ManigerName))
		{
			cout << "\nManiger is not found, choose another one: ";
			ManigerName = clsInputValidate::ReadString();
		}

		clsManiger Maniger1 = clsManiger::Find(ManigerName);

		if (!Maniger1.IsEmpty())
		{
			cout << "\nFind Maniger :-)\n";

		}
		else
		{
			cout << "\nManiger was not found:-(\n";
		}

		_PrintManger(Maniger1);
	}

};

