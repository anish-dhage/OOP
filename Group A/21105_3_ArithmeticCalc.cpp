/*
Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program should take two operands from user and performs the operation on those two operands depending upon the operator entered by user. Use a switch statement to select the operation. Finally, display the result. 

Author - Anish Dhage
Roll No - 21105
Batch - E1
*/

#include <iostream>

using namespace std;

//defining class for calculator
class Calculator
{
public:
	char sign;;
	float var1,var2,output;
	void input();
	void calculate();
};	

//input the statement
void Calculator::input()
{
	cout << "Enter the operation statement : \n";
	cin >> var1 >> sign >> var2;
}

void Calculator::calculate()
{

	switch (sign)
		{
		case '+' : output = var1 + var2;
			   cout << output << endl;
			   break;		
	
		case '-' : output = var1 - var2;
			   cout << output << endl;
			   break;	

		case '*' : output = var1 * var2;
			   cout << output << endl;
			   break;

		case '/' : if(var2 == 0)
			   {
			   cout << " Variable 2 cannot be 0 \n" ;
		  	   }
				   		
			   else
			   {
			   output = var1 / var2;
			   cout << output << endl;
			   break;
			   }
		}		
}


//main function
int main()
{
	Calculator arthm;
	char userpref;

	do
	{
	arthm.input();
	arthm.calculate();
	cout << " Do you want to continue? (y/n) : ";
	cin >> userpref;
	}
	while(userpref == 'y');

return 0;	
}

/*
OUTPUT:
Enter the operation statement : 
4 * 8
32
 Do you want to continue? (y/n) : y
Enter the operation statement : 
4/6
0.666667
 Do you want to continue? (y/n) : y
Enter the operation statement : 
2 - 2
0
 Do you want to continue? (y/n) : n
*/




