#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]){
	ofstream myfile;
	myfile.open(argv[1]);
	myfile << argv[2];
	myfile.close();
	return 0;
}
