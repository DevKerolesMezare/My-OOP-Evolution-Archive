                         // Project 1: Calculator - Requirements
/*

#include <iostream>

using namespace std;  


class clsCalculater
{

private:
    float  _Result = 0; 
    float  _LastNumber = 0;
    string _LastOperation = "Clear"; 
    float  _PreviousResult = 0;

    bool _IsZero(float Number)
    {
            return (Number == 0); 
    }

public:
     void Add(float Number)
     {
        _LastNumber = Number; 
        _PreviousResult = _Result; 
        _LastOperation = "Add";
        _Result += Number; 
     }

     void Subtract(float Number)
     {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtract";
        _Result -= Number;
     }

     void divide(float Number)
     {
         _LastNumber = Number;
         
         if(_IsZero(Number))
         {
             _LastNumber = 1;
         }

         _PreviousResult = _Result;
         _LastOperation = "Dividing";
         _Result /= Number;       
     }

     void Multiply(float Number)
     {       
         _LastNumber = Number;  
         _PreviousResult = _Result;
         _LastOperation = "Multiply";
         _Result *= Number;
     }

     float GetFinalResults()
     { 
         return _Result;
     }

     void Clear()
     {
         _Result = 0;
         _LastNumber = 0;
         _LastOperation = "Clean";
         _PreviousResult = 0;
     }

     void CancelLastOperation() 
     {
         _LastNumber = 0;  
         _LastOperation = "Cancelling Last Operation";   
         _Result = _PreviousResult; 
     }

     void PrintResult()
     {
         cout << "Result ";
         cout << "After " << _LastOperation << " " << _LastNumber << " : " << _Result;
         cout << endl; 
     }
};


int main()
{
    clsCalculater Calculater1;

    Calculater1.Clear();

    Calculater1.Add(200); 
    Calculater1.PrintResult();

    Calculater1.Add(150); 
    Calculater1.PrintResult();

    Calculater1.Subtract(150); 
    Calculater1.PrintResult();

    Calculater1.divide(4);
    Calculater1.PrintResult();

    Calculater1.Multiply(100); 
    Calculater1.PrintResult();
    
    Calculater1.CancelLastOperation(); 
    Calculater1.PrintResult();
    
    

    Calculater1.Clear(); 
    Calculater1.PrintResult();


    system("pause>0"); 
    return 0; 
}

*/

