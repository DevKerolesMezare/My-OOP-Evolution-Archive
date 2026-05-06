#pragma once


#include <iostream>
#include "clsATM.h"
#include "clsATMScreen.h"
#include "clsScreen.h"
#include "Global_ATM.h"

#include "clsInputValidate.h"


using namespace std ;



class clsATMLogin : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;

		string AccountNumber, PinCode; 

		do
		{
	
			if (LoginFaild)
			{
				cout << "\nInvlaid AccountNumber/PINCode!\n"; 
			}
		
			cout << "Enter AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();

			cout << "Enter PINCode: "; 
			PinCode = clsInputValidate::ReadString();


			CurrentClient = clsATM::Find(AccountNumber, PinCode);
		

			LoginFaild = CurrentClient.IsEmpty(); 

		} while (LoginFaild);

		clsATMScreen::ShowATMScreen(); 
		return true; 
	}


public:

	static bool ShowATMLoginScreen()
	{
		system("cls"); 
		_DrawScreenHeader("\t  ATM Login Screen"); 

		return _Login();
	}

};

