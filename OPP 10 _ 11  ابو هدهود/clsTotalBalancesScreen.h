#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

using namespace std; 

class clsTotalBalancesScreen : protected clsScreen
{

private:
    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

    static string NumberToText(int Number)
    {
        if (Number <= 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "" , "One" , "Two" , "Three" , "Four" , "Five" , "Six", "Sevin" , "Eigth" , "Nine" , "Ten"
                , "Eleven" , "Twelve" , "Thirten" , "Fourten" ,"Fiveten" , "Sixten" , "Siventen" , "Eigthteen" , "Nineteen" };

            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

            return arr[Number / 10] + "  " + arr[Number % 10];

        }

        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return  NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }


    }


public:

    static void ShowClientsList()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Clints List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << NumberToText(TotalBalances) << ")";
        cout << "\n\nTrue: "; 
    }

};

