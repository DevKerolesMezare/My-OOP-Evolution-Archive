#pragma once



#include <iostream>
#include<string> 
#include <vector>


#include "clsString.h"
#include "clsPerson.h"
#include <fstream>



class clsATM : public clsPerson
{
private:

	enum enMode{EmptyMode = 0 , UpdateMode = 1};

	string _AccountNumber; 
	string _PinCode; 
	int _AccountBalance;
	enMode _Mode; 


    static clsATM _ConvertLineToClientOpject (string Line , string Seperator = "#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsATM(enMode::UpdateMode, vClientData[0], vClientData[1]
            , vClientData[2], vClientData[3], vClientData[4], vClientData[5], stoi(vClientData[6]));

    }

    static string _ConvertClientOpjectToLine(clsATM Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
    
        return stClientRecord;
    };

    static clsATM _GetEmptyClientOpject()
    {
        return clsATM(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector <clsATM> _LoadClientsDataFromFile()
    {
        vector <clsATM> vClient; 

        fstream MyFile; 

        MyFile.open("Clients.txt", ios::in);
          
        if (MyFile.is_open())
        {
            string Line; 

            while (getline(MyFile , Line))
            {
                clsATM Client = _ConvertLineToClientOpject(Line);

                vClient.push_back(Client); 
            }

            MyFile.close(); 
        }

        return vClient; 
    }

    static void _SaveCleintsDataToFile(vector <clsATM> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;


        if (MyFile.is_open())
        {
            for (clsATM C : vClients)
            {
                    DataLine = _ConvertClientOpjectToLine(C);
                    MyFile << DataLine << endl;
            }

            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsATM> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsATM& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }


    struct stTrnsferLogRecord;
    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecord;
        vTrnsferLogRecord = clsString::Split(Line, Seperator);


        TrnsferLogRecord.DateTime = vTrnsferLogRecord[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecord[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecord[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecord[3]);
        TrnsferLogRecord.SourceAmount = stod(vTrnsferLogRecord[4]);
        TrnsferLogRecord.DestinationAmount = stod(vTrnsferLogRecord[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecord[6];

        return TrnsferLogRecord;
    }

    string _PrepareTransferLogRecord(double Amount, clsATM DestinationClient, string User, string Seperator = "#//#")
    {  
        string TransferLogRecord = "";
 
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator; 

        TransferLogRecord += AccountNumber();
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;

        TransferLogRecord += to_string(Amount)+Seperator;

        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;

        TransferLogRecord += User + Seperator;

        return TransferLogRecord; 
    }

    void _RegisterTransferLog(double Amount, clsATM DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("ATMTransferLogRecord" , ios::out | ios::app);
        
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl; 
        }

        MyFile.close();
    }


public:

	clsATM(enMode Mode, string FirstName, string LastName, string Gmail,
		string Phone, string AccountNumber, string PINCode, double AccountBalance)
		:clsPerson(FirstName, LastName, Gmail, Phone)
	{
		_Mode = Mode; 
		_AccountNumber = AccountNumber; 
		_PinCode = PINCode; 
		_AccountBalance = AccountBalance; 
	}
		

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    struct stTrnsferLogRecord
    {
        string DateTime = "";

        string SourceAccountNumber = "";
        string DestinationAccountNumber = "";

        double  Amount = 0;

        double  SourceAmount = 0;
        double DestinationAmount = 0;
        string UserName = "";

    };


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode); 
	}
	

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount; 
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (_AccountBalance < Amount)
        {
            return false;
        }

        _AccountBalance -= Amount; 
        Save();
        return true;
    }
     

    static clsATM Find(string AccountNumber)
    {
        fstream MyFile; 
        MyFile.open("Clients.txt", ios::in); 

        if (MyFile.is_open())
        {            
            string Line; 
            
            while (getline(MyFile, Line))
            {               
                clsATM Client = _ConvertLineToClientOpject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close(); 
             
                    return Client;
                }
            }

            MyFile.close();
            return _GetEmptyClientOpject();
        }
    }

    static clsATM Find(string AccountNumber ,string PInCode)
    {
        fstream MyFile; 
        MyFile.open("Clients.txt", ios::in); 

        if (MyFile.is_open())
        {            
            string Line; 
            
            while (getline(MyFile, Line))
            {               
                clsATM Client = _ConvertLineToClientOpject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PInCode)
                {
                    MyFile.close(); 
             
                    return Client;
                }
            }

            MyFile.close();
            return _GetEmptyClientOpject();
        }
    }


    static bool IsClientExist(string AccountNumber, string PInCode)
    {
         clsATM Client1 = clsATM::Find(AccountNumber, PInCode);
         return(!Client1.IsEmpty());
    }

    static bool IsClientExist(string AccountNumber)
    {
         clsATM Client1 = clsATM::Find(AccountNumber);
         return(!Client1.IsEmpty());
    }


    static vector<clsATM> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break; 
        }


        }



    }

};







