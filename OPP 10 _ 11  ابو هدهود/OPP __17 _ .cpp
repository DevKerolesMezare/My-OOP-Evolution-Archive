                      //   Person Exercise - Requirements

/*
#include <iostream>
#include <string>
using namespace std;


class clsPerson
{
private:

	int _ID;
	string _FirstName;
	string _LastName;
	string _Gmail;
	string _PhoneNumber;

public:
	clsPerson(int ID , string FirstName , string LastName , string Gmail , string PhoneNumber)
	{
		_ID = ID; 
		_FirstName = FirstName;
		_LastName = LastName;
		_Gmail = Gmail;
		_PhoneNumber = PhoneNumber;

	}
	
	int ID()
	{
		return _ID;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string FirstName()
	{
		return _FirstName; 
	}

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string LastName()
	{
		return _LastName ; 
	}

	string FullName()
	{
		return _FirstName + _LastName;
	}
	

    void setPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	string PhoneNumber()
	{
		return _PhoneNumber;
	}


    void setGmail(string Gmail)
	{
		_Gmail = Gmail;
	}
	string Gmail()
	{
		return _Gmail;
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "The Following message sent successfully to email: " << _Gmail << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}
	void SendSMS(string Message)
	{
		cout << "\nThe Following SMS sent Successfully to phone: " << _PhoneNumber << endl;
		cout << Message << endl;
	}


	void Print()
	{
		cout << "Info:" << endl;
		cout << "\n_______________________________\n";
		cout << "ID       : " << _ID << endl;
		cout << "FirstName: " << _FirstName << endl;
		cout << "LastName : " << _LastName << endl;
		cout << "FullName : " <<  FullName() << endl;
		cout << "Email    : " << _Gmail<< endl;
		cout << "Phone    : " << _PhoneNumber << endl;
		cout << "_______________________________\n\n";
	}
};



int main()
{

	clsPerson Person1(10 , "Keroles" , "Mezare" , "MY@gmail.com" , "0100230");

	Person1.Print(); 

	Person1.SendEmail("Hi", "How Are You");
	Person1.SendSMS("How Are You");
	

	system("pause>0");
	return 0;
}

*/