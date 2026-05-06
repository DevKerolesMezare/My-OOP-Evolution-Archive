#pragma once


#include <iostream>
#include "clsATM.h"
#include "clsScreen.h"
//#include "Global_ATM.h"


class clsATMCheckBalances : protected clsScreen
{
public:
	static void ShowCheckBalances()
	{
		_DrawScreenHeader("\t  Check Balance Screen...");	
		cout << "Your Balance is: " << CurrentClient.AccountBalance;
	}
};



