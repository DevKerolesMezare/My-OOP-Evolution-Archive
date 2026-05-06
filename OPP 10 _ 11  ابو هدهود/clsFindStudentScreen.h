#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudent.h"

class clsFindStudentScreen :protected clsScreen
{
private:
	static void _PrintStudent(clsStudent Student1)
	{
		cout << "\Student Card:";
		cout << "\n___________________";
		cout << "\nID          : " << Student1.ID();
		cout << "\nFirstName   : " << Student1.FirstName;
		cout << "\nLastName    : " << Student1.LastName;
		cout << "\nFull Name   : " << Student1.FullName();
		cout << "\nEmail       : " << Student1.Email;
		cout << "\nPhone       : " << Student1.Phone;
		cout << "\nGrade       : " << Student1.Grade;
		cout << "\nSpecialty   : " << Student1.StudentSpecialty;
		cout << "\n___________________\n";
	}



public:
	static void ShowFindStudentScreen()
	{

		if (!CheckManigersAccessRights(clsManiger::enPermissions::pFindStudent))
		{
			return;
		}

		_DrawScreenHeader("\t  Find Student Screen..");

		string ID;
		cout << "Enter Student ID: ";
		ID = clsInputValidate::ReadString();

		clsStudent Student1 = clsStudent::Find(ID);

		cout << "\n\n";

		if (!Student1.IsEmpty())
		{
			cout << "Find Student :-)\n";;
		}
		else
		{
			cout << "Not Found Student :-(\n";;
		}
		_PrintStudent(Student1);

	}
};

