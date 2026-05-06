#pragma once


#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudent.h"

#include <iomanip>


class clsStudentsListScreen : protected clsScreen
{
private:

	static string _EditSpace(int n)
	{

		if (n < 10)
			return " " + to_string(n);
		else
			return  to_string(n);
	}

	static void _PrintStudentRecordLine(clsStudent Student1 , int N)
	{
		cout << setw(0) << left << "" << "Student: " << _EditSpace(N) /*(i = i + 1)*/;
		cout << setw(0) << left << "" << setw(20) << left << "" << "| " << setw(8) << left << Student1.ID();
		cout << setw(0) << left << "" << "| " << setw(20) << left << Student1.FullName();
		cout << setw(0) << left << "" << "| " << setw(10) << left << Student1.Grade;
		cout << setw(0) << left << "" << "| " << setw(10) << left << Student1.StudentSpecialty << "|";
	}


public:


	static void ShowStudentsList()
	{
		if (!CheckManigersAccessRights(clsManiger::enPermissions::pStudentsList))
		{
			return;
		}
		vector <clsStudent> vStudennts = clsStudent::GetStudentsList();

		string Title = "\t   Student(s) List Screen..";
		string SubTitle = "\t   (" + to_string(vStudennts.size())+") Student(s).";

		_DrawScreenHeader(Title, SubTitle); 

		cout << endl;
		cout << endl;

		cout << setw(31) << left << "" << "=========================================================\n";
		cout << setw(0) << left << "" << setw(31) << left << "" << "| " << setw(8) << left << "ID";
		cout << setw(0) << left << "" << "| " << setw(20) << left << "Full Name";
		cout << setw(0) << left << "" << "| " << setw(10) << left << "Grade";
		cout << setw(0) << left << "" << "| " << setw(10) << left << "Specialty" << "|";
		cout << endl;
		cout << setw(31) << left << "" << "=========================================================\n";


		if (vStudennts.size() == 0)
			return;

		int i = 0;

		for (clsStudent S : vStudennts)
		{	
			_PrintStudentRecordLine(S, i+=1);
			cout << endl;
		}
		cout << setw(31) << left << "" << "=========================================================\n";
	}


};

