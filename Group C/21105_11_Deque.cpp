/*
Write C++ program using STL for Dqueue (Double ended queue).

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>
#include <deque>
using namespace std;

void print_deque(deque <int> A){
	deque <int> :: iterator i;
	for(i = A.begin(); i!=A.end(); i++){
		cout<< *i <<" ";
	}
	cout<<endl;
}

int main() {

	deque <int> myqueue;

	int data;
	int op;

	do{
		cout<<"\n1.Insert at Front\n2.Insert at Back\n3.Pop Front\n4.Pop Back\n5.Display\n6.Exit\nEnter option number : ";
		cin>>op;
		cout<<endl;
		switch(op){

			case 1 :cout<<"Enter the element : ";
					cin>>data;
					myqueue.push_front(data);
					break;

			case 2 :cout<<"Enter the element : ";
					cin>>data;
					myqueue.push_back(data);
					break;

			case 3 :myqueue.pop_front();
					break;

			case 4 :myqueue.pop_back();
				    break;

			case 5 :print_deque(myqueue);
					cout<<"Front Element : "<<myqueue.front()<<endl;
					cout<<"Back Element : "<<myqueue.back()<<endl;
					break;
		}
	}while(op!= 6);



	return 0;
}

/*
OUTPUT:

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 2

Enter the element : 3

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 1

Enter the element : 2

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 1

Enter the element : 1

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 2

Enter the element : 4

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 5

1 2 3 4 
Front Element : 1
Back Element : 4

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 3


1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 5

2 3 4 
Front Element : 2
Back Element : 4

1.Insert at Front
2.Insert at Back
3.Pop Front
4.Pop Back
5.Display
6.Exit
Enter option number : 6
*/