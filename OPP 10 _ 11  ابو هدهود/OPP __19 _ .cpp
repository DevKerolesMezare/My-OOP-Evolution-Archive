                            //  Homework - Employee Exercise

/*
  
#include<iostream>
#include <string>
using namespace std;


class clsEmployees
{
private:

    int    _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    string _Salary;
    string _Departmen;


public:
    clsEmployees(int ID , string FirstName, string LastName, string Title  , string Email, string Phone , string Salary , string Departmen)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title ;
        _Email = Email;
        _Phone = Phone;
        _Salary = Salary;
        _Departmen = Departmen;
    }


    //Read Only Property
    int ID()
    {
        return _ID;
    }

    //Property Set 
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string FirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string LastName()
    {
        return _LastName;
    }

    //Property Set
    void setTitle(string Title)
    {
        _Title = Title;
    }

    //Property Get
    string Title()
    {
        return _Title;
    }

    //Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string Email()
    {
        return _Email;
    }

    //Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string Phone()
    {
        return _Phone;
    }

    //Property Set
    void setSalary(string Salary)
    {
        _Salary = Salary;
    }

    //Property Get
    string Salary()
    {
        return _Salary;
    } 

    //Property Set
    void setDepartmen(string Department)
    {
        _Departmen = Department;
    }

    //Property Get
    string Department()
    {
        return _Departmen;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
     
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << _ID;
        cout << "\nFirstName : " << _FirstName;
        cout << "\nLastName  : " << _LastName;
        cout << "\nTitle     : " << _Title;
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << _Email;
        cout << "\nPhone     : " << _Phone;
        cout << "\nSalary    : " << _Salary;
        cout << "\nDepartmen : " << _Departmen;
        cout << "\n___________________\n";
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;
    }

    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }

};


int main()
{

    clsEmployees Emp1(55, "Keroles", "kero", "Cairo", "My@Gmail.com", "01029541543", "0.00", "NOT Found!");

    Emp1.Print(); 
    
    Emp1.SendEmail("Hi" , "How are you");
    Emp1.SendSMS("How are you");


    system("pause>0"); 
    return 0; 
}
                             
       */                      