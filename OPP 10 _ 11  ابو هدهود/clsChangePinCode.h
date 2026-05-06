#pragma once

#include <iostream>
#include "clsATM.h"
#include "clsScreen.h"
#include "clsInputValidate.h"



class clsChangePinCode :protected clsScreen
{
private:

	static void _ChangePinCode(clsATM &Client1 , string PinCode)
	{
		Client1.PinCode = PinCode;
	}

	static bool ReadPINCode()
	{



	}

public:

	static void ShowChangePasswordScreen() 
	{
		_DrawScreenHeader("\t  Change Password Screen");

		string PinCode1;
		string PinCode2;
		clsATM Client1 = CurrentClient; 

		cout << "\nPlease Enter a new Password? "; 
		cin >> PinCode1;


		cout << "\nPlease Enter a new password agin? "; 
		cin >> PinCode2;

		while (PinCode1 != PinCode2)
		{
			cout << "\nEnter a correct password..!\n";

			cout << "\nPassword? ";
			cin >> PinCode1;

			cout << "Password agin? ";
			cin >> PinCode2;
		}


		char Amswer = 'n'; 
		cout << "\n\nAre you sure about this Transaction? [y:n]? ";
		cin >> Amswer;

		if (toupper(Amswer) == 'Y')
		{
			_ChangePinCode(Client1, PinCode1);
			Client1.Save();
			CurrentClient = Client1;
			cout << "\n\nSuccess.. , New Password is " << Client1.PinCode; 
			return;
		}
		else
		{
			cout << "\n\nCancel operation:-)";
		}
	}

};

