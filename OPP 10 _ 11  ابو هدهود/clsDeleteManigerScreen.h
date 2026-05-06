#pragma once


#include <iostream>

#include "clsManiger.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


using namespace std;

class clsDeleteManigerScreen: protected clsScreen
{
private:

	static void _PrintManger(clsManiger Maniger1)
	{
		cout << "\Mnanger Card:";
		cout << "\n___________________";
		cout << "\nManiger Name   : " << Maniger1.ManigerName;
		cout << "\nFirstName   : " << Maniger1.FirstName;
		cout << "\nLastName    : " << Maniger1.LastName;
		cout << "\nFull Name   : " << Maniger1.FullName();
		cout << "\nEmail       : " << Maniger1.Email;
		cout << "\nPhone       : " << Maniger1.Phone;
		cout << "\nPassword    : " << Maniger1.Password;
		cout << "\nPermissions : " << Maniger1.Permissions;
		cout << "\n___________________\n";

	}



public:
	static void ShowDeleteManigerScreen()
	{

		_DrawScreenHeader("\t  Delete Maniger Screen..");


		string ManigerName = "";
		cout << "\nEnter Maniger Name: ";
		ManigerName = clsInputValidate::ReadString();
		while (!clsManiger::IsMangerExict(ManigerName))
		{
			cout << "Maniger Is Not Found, Choose anthor one: ";
			ManigerName = clsInputValidate::ReadString();
		}


		clsManiger Maniger1 = clsManiger::Find(ManigerName);
		_PrintManger(Maniger1);

		char Answer = 'n';
		cout << "Do you want Delete this maniger? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Maniger1.Delete())
			{
				cout << "\nManiger Updated Successfully...\n";
				_PrintManger(Maniger1); 
			}
			else
			{
				cout << "\nError Maniger was not deleted.:-0"; 
			}
		}
	}


};

