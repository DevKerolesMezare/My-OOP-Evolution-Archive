#pragma once


#include <iostream>
#include <string>
#include <vector>

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"

#include <fstream>

using namespace std; 
  

class clsManiger : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    string _ManigerName = "";
    string _Password = "";
    int _Permissions = 0;

    enMode _Mode;

    bool _MarkedForDelete = false;

    static clsManiger _ConvertLineToManigerOpject(string Line, string Saperator = "#//#")
    {
        vector <string> vManigerData;
        vManigerData = clsString::Split(Line, Saperator);

        return clsManiger(enMode::UpdateMode, vManigerData[0], vManigerData[1], vManigerData[2], vManigerData[3], vManigerData[4], vManigerData[5], stoi(vManigerData[6]));
    }

    static string _ConvertMangerOPjectToLine(clsManiger Maniger1, string Saperator = "#//#")
    {

        string ManigerRecord = "";

        ManigerRecord += Maniger1.FirstName + Saperator;
        ManigerRecord += Maniger1.LastName + Saperator;
        ManigerRecord += Maniger1.Email + Saperator;
        ManigerRecord += Maniger1.Phone + Saperator;
        ManigerRecord += Maniger1._ManigerName + Saperator;
        ManigerRecord += Maniger1.Password + Saperator;
        ManigerRecord += to_string(Maniger1.Permissions);

        return ManigerRecord;
    }

    static clsManiger _GetEmptyManigerOpject()
    {
        return clsManiger(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector <clsManiger> _LoadManigerDataFromFile()
    {
        vector <clsManiger> vManigers;

        fstream MyFile;
        MyFile.open("Manigers.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsManiger Maniger = _ConvertLineToManigerOpject(Line);

                vManigers.push_back(Maniger);
            }

            MyFile.close();
        }

        return vManigers;
    }


    static void _SaveManigersDataToFile(vector <clsManiger> vMangers)
    {

        fstream MyFile;
        MyFile.open("Manigers.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsManiger& M : vMangers)
            {

                if (M.MarkedForDeleted() == false)
                {
                    DataLine = _ConvertMangerOPjectToLine(M);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsManiger> vManiger;
        vManiger = _LoadManigerDataFromFile();

        for (clsManiger& S : vManiger)
        {
            if (S.ManigerName == ManigerName)
            {
                S = *this;
                break;
            }

        }

        _SaveManigersDataToFile(vManiger);
    }

    void _AddDataLineToFile(string stDataLine)
    {

        fstream MyFile;

        MyFile.open("Manigers.txt", ios::out | ios::app);


        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertMangerOPjectToLine(*this));
    }


    string _PrepareLoginRecord(string Seprator = "#//#")
    {
        string sLine = "";

        sLine += clsDate::GetSystemDateTimeString() + Seprator;
        sLine += ManigerName + Seprator;
        sLine += Password + Seprator;
        sLine += to_string(Permissions);

        return sLine; 
    }
        
    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line , string Seprator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;

        vector <string> vLoginRegisterRecord;
        vLoginRegisterRecord = clsString::Split(Line , Seprator);

        LoginRegisterRecord.Date = vLoginRegisterRecord[0];
        LoginRegisterRecord.ManigerName = vLoginRegisterRecord[1];
        LoginRegisterRecord.Password = vLoginRegisterRecord[2];
        LoginRegisterRecord.Perrmissios = stoi(vLoginRegisterRecord[3]);
       
        return LoginRegisterRecord;
    }



public:

    enum enPermissions
    {
        pAll = -1,
        pStudentsList = 1,
        pAddStudent = 2,
        pFindStudent = 4,
        pUpdateStudent = 8,
        pDeleteStudent = 16,
        pManiger = 32
    };

    clsManiger(enMode Mode, string FirstName, string LastName, string Gmail, string Phone,
        string ManigerName, string Password, int Permissions) : clsPerson(FirstName, LastName, Gmail, Phone)
    {
        _Mode = Mode; 
        _ManigerName = ManigerName;
        _Password = Password;
        _Permissions = Permissions;
    }




    struct stLoginRegisterRecord
    {
        string Date; 
        string ManigerName; 
        string Password; 
        int Perrmissios;
    };


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }


    string GetManigerName()
    {
        return _ManigerName;
    }

    void SetManigerName(string UserName)
    {
        _ManigerName = UserName;
    }

    __declspec(property(get = GetManigerName, put = SetManigerName)) string ManigerName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    bool Delete()
    {
        vector <clsManiger> vManigers;

        vManigers = _LoadManigerDataFromFile();

        
        for (clsManiger &M : vManigers)
        {
            if (M._ManigerName == _ManigerName)
            {
                M._MarkedForDelete = true; 
                break; 
            }
        }

        _SaveManigersDataToFile(vManigers);

        *this = _GetEmptyManigerOpject();
        return true; 
    }

    static clsManiger Find(string ManigerName)
    {
        fstream MyFile; 

        MyFile.open("Manigers.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsManiger Manger = _ConvertLineToManigerOpject(Line); 

                if (Manger._ManigerName == ManigerName)
                {
                    MyFile.close();
                    return Manger;
                }

            }

            MyFile.close();
        }

    return _GetEmptyManigerOpject();

    }

    static clsManiger Find(string ManigerName , string Password)
    {
        fstream MyFile; 

        MyFile.open("Manigers.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsManiger Manger = _ConvertLineToManigerOpject(Line); 

                if (Manger._ManigerName == ManigerName && Manger.Password == Password)
                {
                    MyFile.close();
                    return Manger;
                }
            }
            MyFile.close();
        }

        return _GetEmptyManigerOpject();
    }
    
    static bool IsMangerExict(string ManigerName)
    {
        clsManiger Maniger1 = clsManiger::Find(ManigerName);
        return (!Maniger1.IsEmpty());
    }  


    static vector <clsManiger> GetManigersList()
    {
        return _LoadManigerDataFromFile();
    }

    static clsManiger GetAddNewManigerOpject(string MangerName)
    {
        return clsManiger(enMode::AddNewMode, "", "", "", "", MangerName, "", 0);
    }

    enum enSaveResult {svFaildEmptyObject = 0 , svSucceeded = 1 , vsFaildManigerExists = 2};

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResult::svFaildEmptyObject;
            }
            break;
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResult::svSucceeded;

            break;
        }
           


        case enMode::AddNewMode:
        {
            if (clsManiger::IsMangerExict(_ManigerName))
            {
                return vsFaildManigerExists;
            }
            else
            {
                _AddNew();

                _Mode = enMode::UpdateMode;
                return enSaveResult::svSucceeded;
            }
            break;
        }
        }


    }


    bool CheckAccessPermission(enPermissions Permissions)
    {
        if (this->Permissions == enPermissions::pAll)
            return true;

        if ((Permissions & this->Permissions) == Permissions)
        {
            return true;
        }

        else
            return false; 
    }

    void RegiserLogIn()
    {
        string sLine = _PrepareLoginRecord();

        fstream MyFile;

        MyFile.open("LoginRegister(Maniger).txt", ios::out | ios::app); 

        if (MyFile.is_open())
        {
            MyFile << sLine << endl; 

            MyFile.close();
        }
    }

    static vector<stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord>vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister(Maniger).txt", ios::in);


        if (MyFile.is_open())
        {
            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close();
        }

    return vLoginRegisterRecord;

    }

};

