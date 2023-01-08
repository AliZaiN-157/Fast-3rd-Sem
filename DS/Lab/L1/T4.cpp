#include<iostream>

using namespace std;

void fac(int num){
	
	int sum = 0;

	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			cout << i << " ";
			sum += i;
		}
	}
	cout << "\nSum of factor: " << sum;
}

int main(){
	
	int num;
	
	cout << "Enter a positive integer: ";
	cin >> num;
	
	while (num > -1) {
		fac(num);
		cin >> num;
	}
}
