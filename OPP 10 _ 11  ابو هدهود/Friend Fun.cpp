
/*

#include <iostream>

using namespace std; 


class clsA
{

private:
	int _A1 ; 
	
protected:
	int _A2 ;

public:
	int A3 ;

	clsA()
	{
		_A1 = 10; 
		_A2 = 20; 
		A3 = 30; 
	}


	friend int Fun1(clsA A1);
	friend int Fun2(clsA A1);
};


int Fun1(clsA A1)
{	
	return A1.A3 + A1._A2 + A1._A1; 
}


int Fun2 (clsA A1)
{	
	return A1.A3 + A1._A2 + A1._A1 + 99; 
}





int main()
{ 

	clsA A1;

	cout << "Sum 3 Numbers: " << Fun1(A1);
	cout << "\nSum 3 Numbers: " << Fun2(A1);

	system("pause>0");
	return 0; 
}

*/