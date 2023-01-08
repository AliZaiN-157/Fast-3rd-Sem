#include<iostream>
using namespace std;

int main() {
	int f1, f2, flag = 0;
    bool arr[5][5] = { {false,true,false,true,true},
                    {true,false,true,false,true},
                    {false,true,false,false,false},
                    {true,false,false,false,true},
                    {true,true,false,true,false} };
                    
    cout << "Enter number of friend 1 (0-4): ";
    cin >> f1;
    
    cout << "Enter number of friend 2 (0-4): ";
    cin >> f2;
    
    cout << "The common friends among " << f1 << " and " << f2 << " are : ";
    
    for (int i = 0; i < 5; i++) {
    	
        if (arr[f1][i] && arr[f2][i]) {
        	
            flag = 1;
            cout << i << " ";
        }
    }
    if (flag == 0){
			cout << "Me to Intovert Hun" << endl;
		}
}
