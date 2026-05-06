                         //   Properties Set and Get through "="/

/*

#include <iostream>
using namespace std; 


class clsPerson
{

private:
    string _FirstName;

public:
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName; 
    }

    string getFirstName()
    {
        return _FirstName; 
    }

    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
};



int main()
{
    clsPerson Person1; 

    Person1.setFirstName("Kero"); 
    cout << Person1.getFirstName() << endl;

    Person1.FirstName = "Kero";
    cout << Person1.FirstName;


    system("pause>0"); 
    return 0; 
}

*/