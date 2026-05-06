#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short FaildLoginCount = 0;

        do
        {
            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " << (3 - FaildLoginCount) << " Trials to login.\n\n";

            }

            if (FaildLoginCount == 3)
            {
                cout << "You are looked after 3 faild trails";
                return false;
            }


            cout << "Enter Username? ";
            Username = clsInputValidate::ReadString();

            cout << "Enter Password? ";
            Password = clsInputValidate::ReadString();;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            

        } while (LoginFaild);


        CurrentUser.RegisterLogIn(); 

        clsMainScreen::ShowMainMenue();
        return true;  
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");

        _DrawScreenHeader("\t  Login Screen");
        
        return _Login();

    }

};

