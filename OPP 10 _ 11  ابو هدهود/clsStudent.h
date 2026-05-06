#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsString.h"

using namespace std;

class clsStudent : public clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode =2 , AddNewMode = 3};

	string _ID = "";
	string _StudentSpecialty = "";
	string    _Grade = "";
	enMode _Mode;
	
	bool _MarkForDelete = false; 


	static clsStudent _ConvertLineToStudentOpject(string Line , string Seprator = "#//#")
	{
		vector <string> vStudentData;

		vStudentData = clsString::Split(Line, Seprator);

		return clsStudent(enMode::UpdateMode, vStudentData[0], vStudentData[1], vStudentData[2], vStudentData[3], vStudentData[4], vStudentData[5], vStudentData[6]);	    
	}

	static string _ConvertStudentOpjectToLine(clsStudent Student1 , string Seprator = "#//#")
	{
		string _StudentRecord = "";

		_StudentRecord += Student1._ID + Seprator;
		_StudentRecord += Student1.FirstName+ Seprator;
		_StudentRecord += Student1.LastName+ Seprator;
		_StudentRecord += Student1._StudentSpecialty + Seprator;
		_StudentRecord += Student1._Grade + Seprator;
		_StudentRecord += Student1.Email + Seprator; 
		_StudentRecord += Student1.Phone; 

		return _StudentRecord;
	}


	void _AddNew()
	{
		_AddDataLineToFile(_ConvertStudentOpjectToLine(*this));
	}

	void _AddDataLineToFile(string StudentRecord)
	{
		fstream MyFile; 

		MyFile.open("Students.txt", ios::out | ios::app); 

		if (MyFile.is_open())
		{
			MyFile << StudentRecord << endl; 
			MyFile.close();
		}
	}

	static clsStudent _GetEmptyStudentOpject()
	{
		return clsStudent(enMode::EmptyMode, "", "", "", "", "", "" ,"");
	}

	static vector <clsStudent> _LoadStudentDataFromFile()
	{
		vector <clsStudent> vStudent; 

		fstream MyFile;

		MyFile.open("Students.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsStudent Student1 = _ConvertLineToStudentOpject(Line);

				vStudent.push_back(Student1);
			}
			MyFile.close();
		}	

		return  vStudent;
	}

	static void _SaveStudentDataToFile(vector <clsStudent> vStudent)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::out);//overwrite

		
		string DataLine;

		if (MyFile.is_open())
		{

			for (clsStudent& S : vStudent)
			{
				if (S._MarkForDelete == false)
				{
					DataLine = _ConvertStudentOpjectToLine(S); 
					MyFile << DataLine << endl; 
				}
			}

			MyFile.close();
		}

	}

    void _Update()
	{
		vector <clsStudent> vStudent; 
		vStudent = _LoadStudentDataFromFile();

		for (clsStudent& S : vStudent)
		{			
			if (S.ID() == ID())
			{
				S = *this; 
				break;
			}

		}

		_SaveStudentDataToFile(vStudent);
	}


public:

	clsStudent(enMode Mode, string ID, string FirstName, string LastName ,string Specialty, string Grade,  string Email,
		string Phone):
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_ID = ID; 
		_Grade = Grade; 
		_StudentSpecialty = Specialty;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string ID()
	{
		return _ID; 
	}


	void SetGrade(string Grade)
	{
		_Grade = Grade;
	}
	string GetGrade()
	{
		return _Grade;
	}
	__declspec(property(get = GetGrade, put = SetGrade))string Grade;



	void SetStudentSpecialty(string Specialty)
	{
		_StudentSpecialty = Specialty;
	}
	string GetStudentSpecialty()
	{
		return _StudentSpecialty;
	}
	__declspec(property(get = GetStudentSpecialty, put = SetStudentSpecialty))string StudentSpecialty;

	bool Delete()
	{
		vector <clsStudent> vStudent1;
		vStudent1 = _LoadStudentDataFromFile(); 

		for (clsStudent& S : vStudent1)
		{
			if (S.ID() == ID())
			{
				_MarkForDelete = true; 
				break;
			}
		}

		_SaveStudentDataToFile(vStudent1); 

		*this = _GetEmptyStudentOpject();

		return true;
	}

	static clsStudent GetAddNewStudentOpject(string ID)
	{
		return clsStudent(enMode::AddNewMode, ID, "", "", "", "", "" , "");
	}

	static clsStudent Find(string ID)
	{
		fstream MyFile; 

		MyFile.open("Students.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line; 

			while (getline(MyFile, Line))
			{
				clsStudent Student1 = _ConvertLineToStudentOpject(Line);

				if (Student1.ID() == ID)
				{
					MyFile.close(); 
					return Student1;
				}
			}

			MyFile.close();
		}

		return _GetEmptyStudentOpject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildStudentIDExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsStudent::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
			break;

		case clsStudent::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

			break;

		case clsStudent::AddNewMode:
			if (clsStudent::IsStudentExist(_ID))
			{
				return enSaveResults::svFaildStudentIDExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return  enSaveResults::svSucceeded;
			}

			break;
		}
	}


	static bool IsStudentExist(string StudentID)
	{
		clsStudent Student1 = clsStudent::Find(StudentID); 
		return (!Student1.IsEmpty());
	}


	static vector <clsStudent> GetStudentsList()
	{
		return _LoadStudentDataFromFile();
	}


};

