                      // Total Balance

/*

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

#include <iomanip>

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalance()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalance = 0;


    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            TotalBalance += Client.AccountBalance; 
            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << setw(52) << right << "Total Balances = " << TotalBalance<<endl;
    cout << setw(34) <<"(" << clsUtil::NumberToText(TotalBalance) <<")";
}


int main()
{
    ShowTotalBalance();

    system("pause>0");
    return 0;
}

*/