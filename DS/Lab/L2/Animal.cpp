#include "Animal.h"

Animal::Animal()
{
	age = 0;
	name = "";
}

Animal::Animal(const Animal& other)
{
	age = other.age;
	name = other.name;
}

Animal::Animal(string name, int age, string breed)
{
	this->age = age;
	this->name = name;
	this->breed = breed;
}

Animal::~Animal()
{
}

void Animal::setName(string name)
{
	this->name = name;
}

void Animal::setAge(int age)
{
	this->age = age;
}

void Animal::setBreed(string breed)
{
	this->breed = breed;
}

string Animal::getName()
{
	return name;
}

int Animal::getAge()
{
	return age;
}

string Animal::getBreed()
{
	return breed;
}

void Animal::print()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

int main(){
	Animal a1("Bubzy", 11, "Persian");
	cout << a1.getName() << endl;
	cout << a1.getAge() << endl;
	cout << a1.getBreed() << endl;
}

