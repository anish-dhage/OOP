/*
a.       User has age between 18 and 55 
b.       User stays has income between Rs. 50,000 – Rs.     1,00,000 per month
c.        User stays in Pune/ Mumbai/ Bangalore / Chennai
d.       User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned above. If any of the condition not met then throw the exception.

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class User {

	int age;
	int income;
	string city;
	int vehicle_wheeler;

public:
	void input() {

		cout << "Enter the Age of User : ";
		cin >> age;
		cout << endl;

		cout << "Enter the Income of User : ";
		cin >> income;
		cout << endl;

		cin.ignore();
		cout << "Enter the City of User : ";
		getline(cin, city);
		cout << endl;

		cout << "Enter the kind of Vehicle of User (Number of Wheels) : ";
		cin >> vehicle_wheeler;
		cout << endl;

	}

	void display() {

		cout << "\nAge of User is :";
		try {
			if (age < 18 || age > 55) {
				throw age;
			}
		} catch (int x) {
			cout << "Age is not between 18 and 55 //Exception Found \n";
		}
		cout << age;

		cout << "\nIncome of User is :";
		try {
			if (income < 50000 || income > 100000) {
				throw income;
			}
		} catch (int x) {
			cout << "Income is not in specified range //Exception Found \n";
		}
		cout << income;

		cout << "\nCity of User is : ";

		try {
			if (city != "Pune" && city != "Mumbai" && city != "Banglore"
					&& city != "Chennai") {
				throw 2;
			}
		} catch (int x) {
			cout << "City is not in specified cities //Exception Found \n";
		}
		cout << city;

		cout << "\nVehicle Kind of User is :";
		try {
			if (vehicle_wheeler != 4) {
				throw vehicle_wheeler;
			}
		} catch (int x) {
			cout << "Vehicle is not a 4 Wheeler //Exception Found \n";
		}
		cout << vehicle_wheeler << " Wheeler";
	}

};

int main() {

	User A;
	A.input();
	A.display();

	return (0);
}

/*
OUTPUT:
Enter the Age of User : 20
Enter the Income of User : 40000
Enter the City of User : Pune
Enter the kind of Vehicle of User (Number of Wheels) : 4

Age of User is : 20
Income of User is : Income is not in specified range //Exception Found
City of User is : Pune
Vehicle Kind of User is : 4 Wheeler
*/
