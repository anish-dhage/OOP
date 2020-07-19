/*
Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ofstream ofile;
	if(!ofile){
		cout<<"Sorry";
	}
	else{
		ofile.open("MyFile.txt");
		char op ;
		string line;
		cout<<"Do you want to enter a line? (Y/N) : ";
		cin>>op;
		while(op == 'Y'||op == 'y'){
			cout<<"Enter the line : ";
			cin.ignore();
			getline(cin,line);
			ofile<<line;
			ofile<<endl;
			cout<<"Do you want to enter another line? (Y/N) : ";
			cin>>op;
		}
		ofile.close();
	}

	if(!ofile){
		cout<<"Sorry";
	}
	else{
		ifstream ifile;
		ifile.open("MyFile.txt");
		cout<<"Contents of file are :\n ";
		string content;
		while(getline(ifile, content)){
			cout<<content;
			cout<<endl;
		}
	}

	return 0;
}
/*
OUTPUT:
Do you want to enter a line? (Y/N) : y
Enter the line : I am from PICT
Do you want to enter another line? (Y/N) : y
Enter the line : I study Computer Engineering
Do you want to enter another line? (Y/N) : n
Contents of file are:
I am from PICT
I study Computer Engineering

*/
