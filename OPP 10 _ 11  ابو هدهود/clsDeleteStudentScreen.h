#pragma once


#include <iostream>
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsInputValidate.h"






class clsDeleteStudentScreen: protected clsScreen
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

	static void ShowDeleteStudentScreen()
	{

		if (!CheckManigersAccessRights(clsManiger::enPermissions::pDeleteStudent))
		{
			return;
		}
		_DrawScreenHeader("\t  Delete Student Screen..");

		string StudentID; 
		cout << "Enter StudentID You wont to Delete: ";
		StudentID = clsInputValidate::ReadString();

		if (!clsStudent::IsStudentExist(StudentID))
		{
			cout << "\nInvalid student ID :-)\n";
			return ;
		}

		clsStudent Student1 = clsStudent::Find(StudentID);
		_PrintStudent(Student1);

		cout << "\nAre you sure you wont to delete this client  y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Student1.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintStudent(Student1);
			}
			else
			{
				cout << "\nError Student was not deleted\n"; 
			}

		}
		else
		{
			cout << "\nCancel Operations";
		}
	}
};

