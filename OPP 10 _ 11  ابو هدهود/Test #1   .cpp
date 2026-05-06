                     // Save opp in File
/*
#include<iostream>
#include <string>
#include <fstream>

using namespace std;

const string PersonFile = "Persons.txt"; 

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;

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

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    string ConvertRecordToLine(clsPerson Person1 ,string Sperator = "#//#")
    {
        string Line;  

        Line += to_string(Person1._ID) += "#//#";
        Line += Person1._FirstName += "#//#";
        Line += Person1._LastName  += "#//#";
        Line += Person1._Email  += "#//#";
        Line += Person1._Phone;

        return Line;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID       : " << ID();
        cout << "\nFirstName: " << FirstName();
        cout << "\nLastName : " << LastName();
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << Email();
        cout << "\nPhone    : " << Phone();
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




void SaveOppInFile(string FileName , string Line)
{
    fstream MyFile; 

    MyFile.open(FileName, ios::out | ios::app); 

    if (MyFile.is_open())
    {
        MyFile << Line << endl; 
        MyFile.close(); 
    }
}



int main()
{
    clsPerson Person1(10, "Keroles", "Mezare", "my@gmail.com", "01029 541544727");
    Person1.Print();

 


    SaveOppInFile(PersonFile, Person1.ConvertRecordToLine(Person1));

    system("pause>0");
    return 0;
}
*/


