#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen:protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();


        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();


        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();


        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();


        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();

    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        } 
        
        cout << "\nATM? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowATMScreen;
        }

        return Permissions;
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\t  Update User Screen..");

        string UserName = ""; 
        cout << "Please Enter UserName? "; 
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "UserName is not Found! ,choose another one:  "; 
            UserName = clsInputValidate::ReadString();
        }

        clsUser UpdateUser = clsUser::Find(UserName); 
        _PrintUser(UpdateUser);       


        char Answer = 'y'; 
        cout << "\nDo You Wont Update This User y/n? "; 
        cin >> Answer; 
        if (toupper(Answer) == 'Y')

        {
            cout << "\n\nUpdate User Info:";
            cout << "\n-----------------------\n";

            _ReadUserInfo(UpdateUser);

            clsUser::enSaveResults SaveResult;

            SaveResult = UpdateUser.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";
                _PrintUser(UpdateUser);
                break;
            }

            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }


            }

        }

        
    }


};

