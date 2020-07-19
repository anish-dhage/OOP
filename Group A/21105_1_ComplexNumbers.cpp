/*
Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded <<and >>to print and read Complex Numbers.

Author - Anish Dhage
Roll No - 21105
Batch - E1
*/

#include <iostream>

using namespace std;

/*
Program to add and multiply complex numbers
*/

class Complex{

	float real_no;
	float imaginary_no;

	public:
	Complex(){
	real_no = 0;
	imaginary_no = 0;
	}	

	/* Overloading + and * operators */
	Complex operator + (const Complex &A){

		Complex temp;
		temp.real_no = real_no + A.real_no;	
		temp.imaginary_no = imaginary_no + A.imaginary_no;

	return temp;	
	}


	Complex operator * (const Complex &A){

		Complex temp;
		temp.real_no = (real_no * A.real_no) - (imaginary_no * A.imaginary_no);
		temp.imaginary_no = (real_no * A.imaginary_no) +  (A.real_no * imaginary_no);
	
	return temp;
	}

	Complex operator - (const Complex &A){

		Complex temp;
		temp.real_no = real_no - A.real_no;	
		temp.imaginary_no = imaginary_no - A.imaginary_no;

	return temp;
	}

	Complex operator / (const Complex &A){

		Complex temp;
		temp.real_no = (real_no * A.real_no) + (imaginary_no * A.imaginary_no);
		temp.imaginary_no = (A.real_no * imaginary_no) - (real_no * A.imaginary_no);
		temp.real_no = temp.real_no/((A.real_no*A.real_no)+(A.imaginary_no*A.imaginary_no));
		temp.imaginary_no = temp.imaginary_no/((A.real_no*A.real_no)+(A.imaginary_no*A.imaginary_no));


	return temp;
	}
	

	friend ostream &operator << (ostream &output, Complex &A){
	
	output<<"The complex number is : "<<A.real_no<<" + "<<A.imaginary_no<<"i"<<endl;
	return output;

	}


	friend istream &operator >> (istream &input, Complex &A){
	
	cout<<"Enter the value of the Real and Imaginary part : \n";
	input >>A.real_no>>A.imaginary_no;
	return input;

	}

};

int main(){

char opr;

Complex A,B,C;

cin>>A;
cin>>B;

	do
	{

	cout<<"Enter the operation you wish to perform : ( + , - , * , / ) : \nPress q to quit \n";
	cin>>opr;

		switch(opr){

		case '+' :
		C = A + B;
		cout <<"Addition is : "<< C;
		break;
	
		case '-' :
		C = A - B;
		cout <<"Subtraction is : "<< C;
		break;
	
		case '*' :
		C = A * B;
		cout <<"Multiplication is : "<< C;
		break;

		case '/' :
		C = A / B;
		cout <<"Division is : "<< C;
		break;
			
		}
	
	}while(opr != 'q');

return 0;
}

/*

OUTPUT:
Enter the value of the Real and Imaginary part : 
4
6
Enter the value of the Real and Imaginary part : 
3
4
Enter the operation you wish to perform : ( + , - , * , / ) : 
Press q to quit 
+
The complex number is : 7 + 10i
Enter the operation you wish to perform : ( + , - , * , / ) : 
Press q to quit 
-
The complex number is : 1 + 2i
Enter the operation you wish to perform : ( + , - , * , / ) : 
Press q to quit 
*
The complex number is : -12 + 34i
Enter the operation you wish to perform : ( + , - , * , / ) : 
Press q to quit 
q

*/









