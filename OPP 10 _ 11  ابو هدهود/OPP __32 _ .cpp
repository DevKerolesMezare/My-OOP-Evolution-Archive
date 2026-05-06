                // Interfaces: Pure Virtual Functions and Abstract Classes


/*

#include <iostream>

using namespace std; 


class clsMobil
{
    virtual void Dial(string PhoneName) = 0; 
    virtual void SendSMS(string PhoneNumber , string Text) = 0;
    virtual void TakePicture() = 0;
};




class clsiphone : public clsMobil
{

    //This class signed a contract with clsMobile abstract class
    //  therefore it should implement everything in the abstract class.

public:
    void Dial(string PhoneName)
    {
        cout << PhoneName << endl ; 
    };
    void SendSMS(string PhoneNumber, string Text)
    {
  
    };

    void TakePicture()
    {

    };

};

class clsSamsungNote10 : public clsMobil
{

    //This class signed a contract with clsMobile abstract class
    //  therefore it should implement everything in the abstract class.

public:
    void Dial(string PhoneName)
    {
        cout << PhoneName << endl ; 
    };
    void SendSMS(string PhoneNumber, string Text)
    {
  
    };

    void TakePicture()
    {

    };

};





int main()
{
    clsiphone iphone1;
    clsSamsungNote10 Note10;

    iphone1.Dial("iphone 16 pro max"); 
    Note10.Dial("Note 10");



    system("pause>0"); 
    return 0; 
}
*/