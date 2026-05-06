#pragma once



#include <iostream>
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsInputValidate.h"





class clsUpdateStudentScreen : protected clsScreen
{
private:
	static void _ReadStudentInfo(clsStudent& Student1)
	{
		cout << "Enter First Name: ";
		Student1.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		Student1.LastName = clsInputValidate::ReadString();

		cout << "Enter Specialty: ";
		Student1.StudentSpecialty = clsInputValidate::ReadString();

		cout << "Enter Grade: ";
		Student1.Grade = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Student1.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Student1.Phone = clsInputValidate::ReadString();

	}

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

	static void ShowUpdateStudentScreen()
	{

		if (!CheckManigersAccessRights(clsManiger::enPermissions::pUpdateStudent))
		{
			return;
		}

		_DrawScreenHeader("\t  Update Student Screen..");

		string StudentID; 
		cout << "\nPlease Enter Student ID: ";
		StudentID = clsInputValidate::ReadString();

		if (!clsStudent::IsStudentExist(StudentID))
		{
			cout << "\ninvalid Student ID.";
			return;
		}


		    cout << "\n------------------\n";
			cout << "\nUpdating Student\n";
			cout << "\n------------------\n";

			clsStudent Student1 = clsStudent::Find(StudentID);
			_ReadStudentInfo(Student1);

			clsStudent::enSaveResults SaveResult;

			SaveResult = Student1.Save();

			switch (SaveResult)
			{
			case clsStudent::svFaildEmptyObject:
				cout << "\nError Student was not saved because it's Empty";
				break;

			case clsStudent::svSucceeded:
				cout << "\n\nStudent Updating Successfuly:-(\n";
				_PrintStudent(Student1);
				break;
			}
	}

};

