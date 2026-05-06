#pragma once



#include <iostream>

#include "clsManiger.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


using namespace std; 




class clsUpdateManigerScreen : protected clsScreen
{

private:

	static void _ReadManigerInfo(clsManiger& Maniger1)
	{
		cout << "\nEnter First Name: ";
		Maniger1.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Maniger1.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Maniger1.Phone = clsInputValidate::ReadString();


		cout << "\nEnter Email: ";
		Maniger1.Email = clsInputValidate::ReadString();

		char Answer = 'n';
		cout << "\nDo you want to modify Password? [y/n]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			cout << "\nEnter Password: ";
			Maniger1.Password = clsInputValidate::ReadString();
		}

		cout << "\nDo you want to modify permissions? [y/n]? ";
		cin >> Answer; 

		if (toupper(Answer) == 'Y')
		{
			cout << "\nEnter Permissions: ";
		    Maniger1.Permissions = _ReadPermissions();
		}

	}

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

	static int _ReadPermissions()
	{
		int Permissions = 0;
		char Answer = 'n';


		cout << "Do you want to give full access? y / n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return -1;
		}


		cout << "Do you want to give access to: \n ";

		cout << "\nShow Students List? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pStudentsList;
		}


		cout << "\nAdd New Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pAddStudent;
		}


		cout << "\nFind Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pFindStudent;
		}


		cout << "\nUpdate Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pUpdateStudent;
		}


		cout << "\nDelete Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pDeleteStudent;
		}


		cout << "\nStudent Maniger? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permissions += clsManiger::enPermissions::pManiger;
		}

		if (Permissions == 63)
		{
			return -1;
		}

		return Permissions;
	}


public:

	static void _ShowUpdateManigerScreen()
	{
		_DrawScreenHeader("\t  Update Maniger Screen.."); 

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
		cout << "Do you want update this maniger? y/n ? "; 
		cin >> Answer; 

		if (toupper(Answer) == 'Y')
		{
		system("cls"); 
		cout << "\t\t----------------------------\n";
		cout << "\t\t\tUpdate Maniger..\n";
		cout << "\t\t----------------------------\n";

		_ReadManigerInfo(Maniger1);



		clsManiger::enSaveResult SaveResult;

		SaveResult = Maniger1.Save();

		switch (SaveResult)
		{
		case clsManiger::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty.";
			break;
		}


		case clsManiger::svSucceeded:
		{
			cout << "\nManiger Updated Successfully...\n";
			_PrintManger(Maniger1);
			break;
		}

		}

		}

	}


};

