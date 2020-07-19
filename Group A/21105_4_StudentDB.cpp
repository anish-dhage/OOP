/* 
Create student database with appropriate data members that should use the following features of object oriented programming in C++. Class, Object, array of objects, new , delete, default constructor to initialize student class fields, parameterized constructor to set the values into the objects, access specifiers, this pointer. 

Author - Anish Dhage
Roll No - 21105
Batch - E1
*/

#include <iostream>

using namespace std;

class Student{
	
	string name;
	char subject[20];
	int rollno;

	public:
		void input();
		void output();

	~Student(){
	cout<<"Destroying all Student objects "<<endl;
	}

};


/* Function to accept data of students */
void Student::input(){

	cout<<"Enter Name of Student : ";
	cin.ignore();
	getline(cin,name);

	cout<<"Enter Subject of Student : ";
	cin>>subject;

	cout<<"Enter the Roll Number : ";
	cin>>rollno;
	
}

/* Function to display data of students */
void Student::output(){

	cout<<"Name : "<<name<< endl <<"Subject : "<<subject<< endl <<"Roll Number : "<<rollno<<endl;

}

class Exam{

	int subjectcode;
	int intmarks;
	int unimarks;
	
	public:
	void input();
	void output();

	Exam(){
	this->subjectcode = 0;
	this->intmarks = 0;
	this->unimarks=0;
	}

};

void Exam::input(){

	cout<<"Enter the Subject code : ";
	cin>>subjectcode;

	cout<<"Enter Internal Marks : ";
	cin>>intmarks;

	cout<<"Enter University Marks : ";
	cin>>unimarks;

}

void Exam::output(){

	cout<<"Subject code : "<<subjectcode<<endl;

	cout<<"Internal Marks : "<<intmarks<<endl;

	cout<<"University Marks : "<<unimarks<<endl;

}

int main(){

	int n,i;

	cout<<"Enter the number of students : ";
	cin>>n;
	cout<<endl;

	Student students[n];
	Exam marks[n];

	for(i=0 ; i<n ;i++){
	cout<<"Enter Details of student "<<i+1<<endl;
	students[i].input();
	cout<<endl;
	marks[i].input();
	cout<<endl;
	}

	cout<<endl;

	for(i=0 ; i<n ;i++){
	cout<<"Details of student "<<i+1<<endl;
	students[i].output();
	marks[i].output();
	cout<<endl;
	}


return 0;

}

/*

OUTPUT :

Enter the number of students : 2

Enter Details of student 1
Enter Name of Student : Anish Dhage
Enter Subject of Student : Comp
Enter the Roll Number : 5

Enter the Subject code : 1
Enter Internal Marks : 267
Enter University Marks : 334

Enter Details of student 2
Enter Name of Student : Ram Sharma
Enter Subject of Student : IT
Enter the Roll Number : 2

Enter the Subject code : 1
Enter Internal Marks : 342
Enter University Marks : 278


Details of student 1
Name : Anish Dhage
Subject : Comp
Roll Number : 5
Subject code : 1
Internal Marks : 267
University Marks : 334

Details of student 2
Name : Ram Sharma
Subject : IT
Roll Number : 2
Subject code : 1
Internal Marks : 342
University Marks : 278

Destroying all Student objects 
Destroying all Student objects 
*/









