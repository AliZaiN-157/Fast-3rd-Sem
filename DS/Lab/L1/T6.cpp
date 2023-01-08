#include <iostream>

using namespace std;

// create an Animal class (having appropriate attributesand functions)

// 1. Dynamically allocate memory to 5 objects of a class.
// 2. Order data in allocated memories by Animal names in ascending order.


class Animal
{
	string name;
	int age;
	string species;
	
	public:
	Animal(string name, int age, string species)
	{
		this->name = name;
		this->age = age;
		this->species = species;
	}
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	string getSpecies()
	{
		return species;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setSpecies(string species)
	{
		this->species = species;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Species: " << species << endl;
	}	
};


int main()
{
	Animal *animal[5];
	animal[0] = new Animal("Lion", 10, "Mammal");
	animal[1] = new Animal("Tiger", 10, "Mammal");
	animal[2] = new Animal("Elephant", 10, "Mammal");
	animal[3] = new Animal("Giraffe", 10, "Mammal");
	animal[4] = new Animal("Zebra", 10, "Mammal");
	
	cout << "\nBefore sorting: \n" << endl;
	for(int i = 0; i < 5; i++)
	{
		animal[i]->print();
	}
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(animal[i]->getName() < animal[j]->getName())
			{
				Animal *temp = animal[i];
				animal[i] = animal[j];
				animal[j] = temp;
			}
		}
	}

	cout <<  "\nAfter sorting: \n" << endl;
	
	for(int i = 0; i < 5; i++)
	{
		animal[i]->print();
	}
	
	return 0;
}