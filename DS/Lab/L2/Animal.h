#pragma once

#include <iostream>
using namespace std;

class Animal
{
	int age;
	string name;
	string breed;
public:
	
	Animal();
	Animal(const Animal& other);
	Animal(string name, int age, string breed);
	~Animal();
	void setName(string name);
	void setAge(int age);
	void setBreed(string breed);
	string getName();
	int getAge();
	string getBreed();
	void print();
};