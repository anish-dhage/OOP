/*
Implement a class Quadratic that represents degree two polynomials i.e., polynomials of type ax^2+bx+c. The class will require three data members corresponding to a, b and c. Implement the following operations: 
1. A constructor (including a default constructor which creates the 0 polynomial). 
2. Overloaded operator + to add two polynomials of degree 2. 
3. Overloaded << and >> to print and read polynomials. To do this, you will need to decide what you want your input and output format to look like. 
4. A function eval that computes the value of a polynomial for a given value of x. 
5. A function that computes the two solutions of the equation
 ax^2+bx+c=0.

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include<iostream>
#include<math.h>

using namespace std;


class Quadratic{

	float coeff_a,coeff_b,coeff_c;
	
	public:
	Quadratic(){
	coeff_a = 0;
	coeff_b = 0;
	coeff_c = 0;
	}
	
	//Overloading >> operator
	friend istream &operator >> (istream &input, Quadratic &A){
		cout<<"\nEnter the constants a,b,c of Quadratic equation ax^2 + bx + c\n";
		input>>A.coeff_a>>A.coeff_b>>A.coeff_c;
		return input;	
	}
	
	//Overloading << operator
	friend ostream &operator << (ostream &output, Quadratic &A){
		output<<A.coeff_a<<"x^2 + "<<A.coeff_b<<"x"<<" + "<<A.coeff_c<<endl;
		return output;	
	}
	
	//Overloading + operator
	Quadratic operator + (const Quadratic &A){
		Quadratic temp;
		temp.coeff_a = coeff_a + A.coeff_a;
		temp.coeff_b = coeff_b + A.coeff_b;
		temp.coeff_c = coeff_c + A.coeff_c;
		
		return temp;
	}
	
	//Function to evaluate equation
	void evaluate(){
	
		float value,x;
		
		cout<<"Enter the value of x : ";
		cin>>x;
		
		value = (coeff_a * x * x ) + (coeff_b * x ) + (coeff_c);
		
		cout<<"\nEvaluation is : "<<value<<endl; 
	
	}
	
	//Function to find roots of equation
	void roots(){
	
		float root1,root2,qd ;
		
		cout<<coeff_a<<"x^2 + "<<coeff_b<<"x"<<" + "<<coeff_c<<endl;
		
		qd = (coeff_b * coeff_b) - (4.0 * coeff_a * coeff_c);
		
		root1 = (float)(((-coeff_b) + sqrt(qd)) / (2.0*coeff_a));
		root2 = (float)(((-coeff_b) - sqrt(qd)) / (2.0*coeff_a));		
	
	cout<<"\nRoots are : "<<root1<<" , "<<root2<<endl;
	
	}
	
};

int main(){

	int val;
	Quadratic obj1;
	Quadratic obj2;
	Quadratic obj3;
	
	cin>>obj1;
	
	do
	{

	cout<<"\nEnter the operation you wish to perform : \n1.Evaluate \n2.Roots \n3.Add: \n4.Exit\n";
	cin>>val;

		switch(val){

		case 1 :
		cout<<obj1<<endl;
		obj1.evaluate();
		break;
	
		case 2 :
		obj1.roots();
		break;
	
		case 3 :
		cin>>obj2;
		cout<<obj1<<endl<<obj2<<endl;
		obj3 = obj1 + obj2;
		cout<<"Addition is : \n";
		cout<<obj3;
		break;
		
		case 4 :
		break;
		
		default :
		cout<<"Invalid Choice\n";
		break;
		}
	
	}while(val != 4);


return 0;
}


/*

OUTPUT:
Enter the constants a,b,c of Quadratic equation ax^2 + bx + c
1
-7
12

Enter the operation you wish to perform : 
1.Evaluate 
2.Roots 
3.Add: 
4.Exit
1
1x^2 + -7x + 12

Enter the value of x : 2

Evaluation is : 2

Enter the operation you wish to perform : 
1.Evaluate 
2.Roots 
3.Add: 
4.Exit
2
1x^2 + -7x + 12

Roots are : 4 , 3

Enter the operation you wish to perform : 
1.Evaluate 
2.Roots 
3.Add: 
4.Exit
3

Enter the constants a,b,c of Quadratic equation ax^2 + bx + c
4
2
1
1x^2 + -7x + 12

4x^2 + 2x + 1

Addition is : 
5x^2 + -5x + 13

Enter the operation you wish to perform : 
1.Evaluate 
2.Roots 
3.Add: 
4.Exit
4

*/








