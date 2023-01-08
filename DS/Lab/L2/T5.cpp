#include<iostream>
using namespace std;

void enterSGPA(double** arr, int* cc, string* names, string* courses);
double calculateCGPA(int cc, double** arr, int position);
int main() {
	string names[5] = { "Ali","Hiba","Asma","Zain","Faisal" };
	
	string courses[5] = { "DS", "AI","DLD","Probs and Stats", "ACF" };
	
	int courseCount[5] = { 5,4,3,3,5 };
	
	double** array = new double* [5];
	for (int i = 0; i < 5; i++) {
		array[i] = new double[courseCount[i]];
	}
	enterSGPA(array, courseCount, names, courses);
	
	double cgpa[5];
	
	for (int i = 0; i < 5; i++) {
		cgpa[i] = calculateCGPA(courseCount[i], array, i);
		cout << "SGPA of " << names[i] << " : " << cgpa[i] << endl;
	}
	/*for (int i = 0; i < 5; i++) {
		delete[] arr[i];
	}
	delete[] arr;*/
}

void enterSGPA(double** arr, int* cc, string* names, string* courses) {
	
	for (int i = 0; i < 5; i++) {
		
		for (int j = 0; j < cc[i]; j++) {
			
			cout << "Enter the cgpa for " << names[i] << " in " << courses[j] << ": ";
			cin >> arr[i][j];
		}
	}
}

double calculateCGPA(int cc, double** arr, int pos) {
	
	int creditCount = cc * 3;
	double totalScores = 0;
	
	for (int i = 0; i < cc; i++) {
		
		totalScores += arr[pos][i] * 3;
		
	}
	double sgpa = totalScores / creditCount;
	return sgpa;
}

