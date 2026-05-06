#pragma once


#include <iostream>

#include "clsUser.h"
#include "Global.h"
#include "Global_ATM.h"
#include "Gloabal_Maniger.h"

#include "clsDate.h"


class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }   
        cout << "\n\t\t\t\t\t______________________________________\n\n";



        if (!CurrentUser.IsEmpty())
        {
        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName ;
        //cout << "\n\t\t\t\t\tDate: " <<clsDate::GetSystemDateTimeString();
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()); 
        cout << "\n\t\t\t\t\tPermessions: " << CurrentUser.Permissions;
        cout << "\n\t\t\t\t\t______________________________________\n\n\n";
        }

        if (!CurrentClient.IsEmpty())
        {
        cout << "\t\t\t\t\tClient Name: " << CurrentClient.FullName();
        //cout << "\n\t\t\t\t\tDate: " <<clsDate::GetSystemDateTimeString();
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()); 
        cout << "\n\t\t\t\t\t______________________________________\n\n\n";
        }

       if (!CurrentManiger.IsEmpty())
        {
        cout << "\t\t\t\t\tManiger Name: " << CurrentManiger.FullName();
        //cout << "\n\t\t\t\t\tDate: " <<clsDate::GetSystemDateTimeString();
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()); 
        cout << "\n\t\t\t\t\t______________________________________\n\n\n";
        }
    }

    static bool CheckManigersAccessRights(clsUser::enPermissions Permission)
    {
       
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

    static bool CheckManigersAccessRights(clsManiger::enPermissions Permission)
    {

        if (!CurrentManiger.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied!  Contact Your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;


    }


};

