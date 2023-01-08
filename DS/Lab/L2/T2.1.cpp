#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int size;
	
	cout << "Enter the number of elements: ";
	cin >> size;
	
	int  arr[size];
	
	cout<<"Enter elements: " << endl;
	for(int i=0 ;i < size; i++){
		cin>>arr[i];
	
	}
	
	int **arr1 = new int*[size];
	
	for(int i=0; i < size; i++){
		
		arr1[i] = &arr[i];
	}
	
	cout<<"\nArray: "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	sort(*arr1,*(arr1)+size);
	cout<<"\nAscending array: "<<endl;
	for(int i=0; i < size; i++){
		cout  << *arr1[i] << " "; 
	}

	sort(*arr1,*(arr1)+size, greater<int>());
	cout<<"\nDescending array: "<<endl;
	for(int i=0; i < size; i++){
		cout  << *arr1[i] << " "; 
	}
	
}