                 // Delete Client

/*

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"


void DeleteClient()
{
    string AccountNumber; 
    cout << "Please Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString(); 

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not Found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber); 
    Client1.Print(); 

    cout << "Are you sure you wont to delete this client  y/n? ";
    char Answer = 'y';
    cin >> Answer; 

    if (toupper(Answer) == 'Y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";
            Client1.Print();
            
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }

}

int main()
{

    DeleteClient();

    system("pause>0"); 
    return 0;
}



*/