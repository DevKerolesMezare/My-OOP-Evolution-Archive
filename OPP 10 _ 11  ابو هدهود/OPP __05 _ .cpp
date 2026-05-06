                    //  Properties Set and Get

/*



#include<iostream>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
  

public:

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
         return _LastName ;
     }


     //Property Get
     string FullName()
     {
         return _FirstName + " " + _LastName;
     } 
};


class clsEmp
{
private:
    string _FirstName;
    string _LastName;
  

public:
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
        return _LastName; 
    }

     string FullName()
     {
         return _FirstName + " " + _LastName;
     } 
};



int main()
{
    clsPerson Person1; 

    Person1.setFirstName("Keroles"); 
    Person1.setLastName("Mezare"); 

    cout << "\nFirst Name : "   << Person1.FirstName();
    cout << "\nLast Name  : " << Person1.LastName();
    cout << "\nLast Name  : " << Person1.FullName() << endl; 


    clsEmp Emp1; 

    Emp1.setFirstName("You");
    Emp1.setLastName("Jack");

    cout << "\nFirst Name : " << Emp1.FirstName();
    cout << "\nLast Name  : " << Emp1.LastName();
    cout << "\nLast Name  : " << Emp1.FullName() << endl;


    system("pause>0"); 
    return 0; 
}

*/