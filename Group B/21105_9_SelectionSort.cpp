/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array. 

Author - Anish Dhage
Roll No - 21105
Batch - E1

*/

#include <iostream>

using namespace std;

template<class T>
class Array{

	int size;
	T arr[20];
	public:
	void accept(){
	
		cout<<"Enter Number of elements :: ";
		cin>>size;
		cout<<"\nEnter "<<size<<" values :-\n";
		for(int i=0; i<size; i++)
			cin>>arr[i];
			
	}
	
	void display(){
	
		for(int i=0;i<size;i++)
			cout<<"\n"<<arr[i];
		cout<<endl;
		
	}
	
	void selectionSort(){
	
		for(int i=0, minpos=0,j=0; i<size; i++){
		
			minpos = i;
			for(j=i+1;j<size;j++){
				if(arr[j]<arr[minpos]){
					minpos = j;
				}
			}
			
			if(i!=minpos){
			
				arr[i] = arr[i] + arr[minpos];
				arr[minpos] = arr[i] - arr[minpos];
				arr[i] = arr[i] - arr[minpos];
				
			}
		}
	}
};

int main() {

	Array <float> ob;
	ob.accept();
	ob.selectionSort();
	ob.display();
	return 0;
	
}


/*
OUTPUT:
Enter Number of elements :: 5

Enter 5 values :-
1.3
5.6
2.8
3.4
7.9

1.3
2.8
3.4
5.6
7.9
*/












