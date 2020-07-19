/*
Write a C++ program using command line arguments to search for a word in a file and replace it with specified word. The usage of program is: $change <old word> <new word> <file name>

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char* arg[]) {

	ofstream ofile;
	ifstream ifile;

	ofile.open(arg[3]);

	if (!ofile) {
		cout << "\nSorry, Error\n";
	}

	else {

		ofile<< " There are many domestic animals\n One of the most common animals is monkey \n The monkey is very lazy";
		ofile.close();

		ifile.open(arg[3]);

		while (!ifile.eof()) {
			string line;
			getline(ifile, line);
			cout << line << endl;
		}
		ifile.close();


		fstream file;
		file.open(arg[3],ios::out|ios::in);

		int extra;
		string rep1, rep2;
		rep1 = arg[1];
		rep2 = arg[2];
		extra = rep1.length() - rep2.length();
		int i = 0;

		for(i = 0; i<extra ; i++){
			rep2 = rep2 + " ";
		}

		string word;
		int pos;
		while (!file.eof()) {
			file>>word;
			if(word == arg[1]){
				pos = file.tellp();
				file.seekp(pos - word.length(), ios::beg);
				file<<rep2;
			}

		}

		file.close();

		ifile.open(arg[3]);

		while (!ifile.eof()) {
			string line;
			getline(ifile, line);
			cout << line << endl;
		}
		ifile.close();
	}
	return 0;
}

/*
OUTPUT:
There are many domestic animals 
One of the most common animals is cat
The cat   is very lazy
*/
