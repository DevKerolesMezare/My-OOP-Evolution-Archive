#pragma once

#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsDeleteClientScreen :protected clsScreen
{
private:
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

    static void DeleteClient()
    {
        if(!CheckManigersAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        

        _DrawScreenHeader("\tDelete Client Screen.");

        string AccountNumber;
        cout << "Please Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not Found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Are you sure you wont to delete this client  y/n? ";
        char Answer = 'y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }

    }

};

