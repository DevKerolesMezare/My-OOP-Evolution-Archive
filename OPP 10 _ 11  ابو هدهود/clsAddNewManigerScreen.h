#pragma once


#include <iostream>

#include "clsManiger.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std; 

class clsAddNewManigerScreen : protected clsScreen
{

private : 

	static void _ReadManigerInfo(clsManiger &Maniger1)
	{
		cout << "\nEnter First Name: ";
		Maniger1.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Maniger1.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Maniger1.Phone = clsInputValidate::ReadString();


		cout << "\nEnter Email: ";
		Maniger1.Email = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		Maniger1.Password = clsInputValidate::ReadString();


		cout << "\nEnter Permissions: ";
		Maniger1.Permissions = _ReadPermissions();

	}

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

	static void ShowAddManagerScreen()
	{

		_DrawScreenHeader("\t  Add New Maniger..");

		

		string ManigerName = "";
		cout << "\nEnter Maniger Name: ";
		ManigerName = clsInputValidate::ReadString();
		while (clsManiger::IsMangerExict(ManigerName))
		{
			cout << "Maniger Is Already Used, Choose anthor one: ";
			ManigerName = clsInputValidate::ReadString();
		}


	    clsManiger NewManiger = clsManiger::GetAddNewManigerOpject(ManigerName);
		
	
		_ReadManigerInfo(NewManiger); 

		clsManiger::enSaveResult SaveResult; 

		SaveResult = NewManiger.Save();

		switch (SaveResult)
		{
		case clsManiger::enSaveResult::svFaildEmptyObject:
			cout << "\nError Maniger was not saved because it's Empty.\n";
			break;


		case clsManiger::enSaveResult::svSucceeded:
			cout << "\nMainger Added Successfully..\n";
			_PrintManger(NewManiger);
			break;


		case clsManiger::enSaveResult::vsFaildManigerExists:
			cout << "\nError Maniger was not saved because ManigerName is used!\n";
			break;
		}

	}

};

