                      //  Update Client
/*
* 
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"


void ReadClientInfo(clsBankClient& Client1)
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

void UpdateClient()
{
    string AccountNumber = ""; 

    cout << "Please Enter client Account Number: "; 
    AccountNumber = clsInputValidate::ReadString(); 

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not Found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber); 
    Client1.Print(); 

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
        Client1.Print();
        break;
    }

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    }

}



int main()
{

    UpdateClient();

    system("pause>0"); 
    return 0; 
}

*/