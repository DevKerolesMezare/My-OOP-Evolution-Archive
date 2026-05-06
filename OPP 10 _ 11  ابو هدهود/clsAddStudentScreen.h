#pragma once

#include <iostream>
#include <string>

#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsScreen.h"

using namespace std;





class clsAddStudentScreen : protected clsScreen
{
private:

	static void _ReadStudentInfo(clsStudent &Student1)
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
	static void ShowAddStudentScreen()
	{
		if (!CheckManigersAccessRights(clsManiger::enPermissions::pAddStudent))
		{
			return;
		}

		_DrawScreenHeader("\t  Add Student Screen..");

		string StudentID;
		cout << "\nEnter ID: "; 
		StudentID = clsInputValidate::ReadString();

		while (clsStudent::IsStudentExist(StudentID))
		{
			cout << "\nStudentID Is Already Used, Choose another one: ";
			StudentID = clsInputValidate::ReadString();
		}

		clsStudent NewStudent = clsStudent::GetAddNewStudentOpject(StudentID);
		_ReadStudentInfo(NewStudent);

		cout << "\n\n";

		clsStudent::enSaveResults SaveResult;

		SaveResult = NewStudent.Save();

		switch (SaveResult)
		{
		case clsStudent::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;

		case clsStudent::svSucceeded:
			cout << "Student Addeded Successfully :-)\n ";
			_PrintStudent(NewStudent);
			break;

		case clsStudent::svFaildStudentIDExists:
			cout << "\nError account was not saved because Student Id is used!\n";
			break;

		}

	}

};

