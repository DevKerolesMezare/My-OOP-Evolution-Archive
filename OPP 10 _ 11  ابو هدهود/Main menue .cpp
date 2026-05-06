                // UI : Main Screen


#include<iostream>

#include"clsMainScreen.h"

#include "clsLoginScreen.h"
#include "clsATMScreen.h"

#include "clsATM.h"

#include "clsATMLogin.h"

#include "clsStudentScreen.h"


#include "clsLoginManigerScreen.h"


#include "clsQueueLine.h"

using namespace std; 

//
//void Print(clsATM Client1)
//{
//    cout << "\nClient Card:";
//    cout << "\n___________________";
//    cout << "\nFirstName   : " << Client1.FirstName;
//    cout << "\nLastName    : " << Client1.LastName;
//    cout << "\nFull Name   : " << Client1.FullName();
//    cout << "\nEmail       : " << Client1.Email;
//    cout << "\nPhone       : " << Client1.Phone;
//    cout << "\nAcc. Number : " << Client1.AccountNumber();
//    cout << "\nPassword    : " << Client1.PinCode;
//    cout << "\nBalance     : " << Client1.AccountBalance;
//    cout << "\n___________________\n";
//
//}
//
//
//
//int main()
//{
// 
//
//    // clsMainScreen::ShowMainMenue();
//    
//    //clsStudentScreen::ShowStudentScreen();
//
//   // clsLoginManigerScreen::ShowLoginScreen();
//
//
//
//   
//    while (true)
//    {
//         if (!clsLoginScreen::ShowLoginScreen()) break;
//    }
//
//    // clsATMLogin::ShowATMLoginScreen();
//           
//
//   
//    
//
//
//    system("pause>0"); 
//    return 0; 
//}


int main()
{

    clsQueueLine CustomerQueue("A0", 10);


    CustomerQueue.IssueTicket();
    CustomerQueue.IssueTicket();
    CustomerQueue.IssueTicket();
    CustomerQueue.IssueTicket();
    CustomerQueue.IssueTicket();


    cout <<"\nPay Bills Queue Info. ";
    CustomerQueue.PrintInfo();



    CustomerQueue.PrintTicketsLineRTL();
    CustomerQueue.PrintTicketsLineLTR();


    CustomerQueue.PrintAllTickets();


    cout << "\nPay Bills Queue After Serving one Client. ";
    CustomerQueue.ServeNextClient();
    CustomerQueue.ServeNextClient();
    CustomerQueue.ServeNextClient();


    CustomerQueue.PrintInfo();
    CustomerQueue.PrintAllTickets();




    system("pause>0");
}