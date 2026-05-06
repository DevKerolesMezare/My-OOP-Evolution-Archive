#pragma once


#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsUpdateClientScreen: protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client1)
    {
        cout << "\nEnter First Name: ";
        Client1.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        Client1.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client1.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client1.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Pincode: ";
        Client1.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client1.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
    static void UpdateClient()
    {
        if (!CheckManigersAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        _DrawScreenHeader("\t  Update Client Screen.");

        string AccountNumber = "";

        cout << "Please Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not Found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nUpdate Client Info:";
        cout << "\n-----------------------\n";

        ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        }

    }

};




