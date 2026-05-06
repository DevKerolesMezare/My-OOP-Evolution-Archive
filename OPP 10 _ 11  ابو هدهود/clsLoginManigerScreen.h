#pragma once


#include <iostream>

#include "clsManiger.h"
#include "clsScreen.h"

#include "clsInputValidate.h"
#include "clsManigerScreen.h"
#include "clsStudentScreen.h"


class clsLoginManigerScreen :protected clsScreen
{
private:

	static void LogIn()
	{
		string ManigerName = ""; 
		string Password = ""; 
		
		bool LoginFaild = false;

		do
		{
			if (LoginFaild == true)
			{
				cout << "\nInvlaid Username/Password!\n";
			}

			cout << "Please Enter Maniger Name? ";
			ManigerName = clsInputValidate::ReadString();

			cout << "Please Enter Password? ";
			Password = clsInputValidate::ReadString();

			CurrentManiger = clsManiger::Find(ManigerName, Password); 
			LoginFaild = CurrentManiger.IsEmpty();

		} while (LoginFaild); 

		CurrentManiger.RegiserLogIn();
		clsStudentScreen::ShowStudentScreen();
	}

public:
	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t  Login Register Screen.!");

		LogIn();
	}


};

