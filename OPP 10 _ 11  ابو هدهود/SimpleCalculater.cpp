
/*

#include <iostream>

using namespace std; 


class clsCalculater 
{
private:

	short _Result = 0; 
	short _LastNumber = 0; 
	string _LastOperation = "Clear"; 
	short _PreviousResult = 0; 

	bool _IsZero(short Number)
	{
		return (Number == 0); 
	}

public:

	void Add(short Number)
	{
		_LastNumber = Number; 
		_PreviousResult = _Result;
		_LastOperation = "Add"; 
		_Result += Number; 
	}

	void Subtract(short Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Subtract";
		_Result -= Number;
	}

	void Multiply(short Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Multiply";
		_Result *= Number;
	}

	void Divide(short Number)
	{
		_LastNumber = Number;

		if (_IsZero(Number))
			Number = 1;

		_PreviousResult = _Result;
		_LastOperation = "Divide";
		_Result /= Number;
	}

	float GetFinalResults()
	{
		return _Result;
	}

	void Clear()
	{
		_LastNumber = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
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
		cout << "After " << _LastOperation << " " << _LastNumber  << " is: " <<_Result <<endl ;
	}
};


int main()
{
	clsCalculater Calculater1; 


	Calculater1.Add(100);
	Calculater1.PrintResult();

	Calculater1.Subtract(20); 
	Calculater1.PrintResult();

	Calculater1.Divide(2); 
	Calculater1.PrintResult();


	Calculater1.Clear(); 
	Calculater1.PrintResult();



	return  0; 
	system("pause>0"); 
}

*/