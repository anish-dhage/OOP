/*
Create employee bio-data using classes
Classes are:
Personal record
Professional record
Academic record 
Assume appropriate data members and member function to accept required data &print bio-data. Create bio-data using multiple inheritances using C++.

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>

using namespace std;

class Personal{
	
	protected :
	string name;
	string address;
	char dob[12];
	long phone_No;
	
	public:
		void displayP(){
		cout <<"\nName : "<<name<<"\nAddress : "<<address<<"\nDate of Birth : "<<dob<<"\nPhone Number : "<<phone_No<<endl;
		}

};

class Academics{
	
	protected:
	string qualification;
	float m10th_marks , m12th_marks;
	
	public:
		void displayA(){
		cout<<"\nQualification : "<<qualification<<"\n10th Marks : "<<m10th_marks<<"\n12th Marks : "<<m12th_marks<<endl;
		}	

};

class Professional{

	protected:
	int emp_code;
	int experience;
	string company;
	string designation;
	
	public:
		void displayPr(){
		cout<<"\nEmployee Code : "<<emp_code<<"\nCompany : "<<company<<"\nDesignation : "<<designation<<"\nYears of Experience : "<<experience<<endl;
		}
};

class BioData : public Personal , public Academics , public Professional{

	public:
	void input(){
	
		cout<<"\nEnter Employee Details : \n";
		
		cout<<"\nEnter Employee Code : ";
		cin>>emp_code;
		
		cout<<"\nEnter your Name : ";
		cin.ignore();
		getline(cin , name);
	
		cout<<"\nEnter your Address : ";
		getline(cin , address);
		
		cout<<"\nEnter your Qualification : ";
		getline(cin , qualification);
	
		cout<<"\nEnter your Company : ";
		getline(cin , company);
		
		cout<<"\nEnter your Designation : ";
		getline(cin , designation);
		
		cout<<"\nEnter your Date of Birth (DD/MM/YYYY) : ";
		cin>>dob;
		
		cout<<"\nEnter your Phone Number : ";
		cin>>phone_No;
		
		cout<<"\nEnter your 10th Marks : ";
		cin>>m10th_marks;
		
		cout<<"\nEnter your 12th Marks : ";
		cin>>m12th_marks;
		
		cout<<"\nEnter your Years of Experience : ";
		cin>>experience;		
	
	}
	
	void display(){
		cout<<"\nPersonal Details : \n";
		Personal::displayP();
		cout<<"\nAcademical Details : \n";
		Academics::displayA();
		cout<<"\nProfessional Details : \n";
		Professional::displayPr();
		cout<<endl;
	
	}

};

int main(){

	BioData ob1;
	ob1.input();
	ob1.display();

}


/*
OUTPUT:
Enter Employee Details : 

Enter Employee Code : 453

Enter your Name : Anish Dhage

Enter your Address : Aundh Pune

Enter your Qualification : Btech (CS)  

Enter your Company : Infosys Ltd.

Enter your Designation : Project Manager

Enter your Date of Birth (DD/MM/YYYY) : 06/12/1999

Enter your Phone Number : 8676756657

Enter your 10th Marks : 92

Enter your 12th Marks : 84

Enter your Years of Experience : 4

Personal Details : 

Name : Anish Dhage
Address : Aundh Pune
Date of Birth : 06/12/1999
Phone Number : 8676756657

Academical Details : 

Qualification : Btech (CS)
10th Marks : 92
12th Marks : 84

Professional Details : 

Employee Code : 453
Company : Infosys Ltd.
Designation : Project Manager
Years of Experience : 4

*/






