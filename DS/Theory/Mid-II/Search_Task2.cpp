#include <iostream>
#include <string>

using namespace std;

//Create a program that inputs a file named “RestaurantsInKarachi” in C++, consider that list contains 
//records that contains names of N restaurants in karachi, your job is to break that list into sublists 
//and name those sublists according to the area in which the restaurant is located.Now ask the user to 
//search for their restaurant of choice, you need to locate in which area of karachi that restaurant is 
//located and return the name of the area to the user the restaurant is located.Perform this task using 
//linear, binary as well as Interpolation search.

class Restaurant
{

	string name;
	string area;
public:
	Restaurant(string name, string area)
	{
		this->name = name;
		this->area = area;
	}
	
	string getName()
	{
		return name;
	}
	
	string getArea()
	{
		return area;
	}
};

class Node
{
public:
	Restaurant* data;
	Node* next;
	
	Node()
	{
		data = NULL;
		next = NULL;
	}
	Node(Restaurant* data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}
	
	void insert(Restaurant* data)
	{
		Node* temp = new Node(data);
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			Node* temp2 = head;
			while (temp2->next != NULL)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}
	}

	void display()
	{
		Node* temp = head;
		cout << "Restaurant Name " << "\t" << "Area" << endl;
		while (temp != NULL)
		{
			cout << temp->data->getName() << "\t\t" << temp->data->getArea() << endl;
			temp = temp->next;
		}
	}

	// Binary Search to Find Restaurant and Area
	void binarySearch(string name)
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp = head;
		int low = 0;
		int high = count - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			for (int i = 0; i < mid; i++)
			{
				temp = temp->next;
			}
			if (temp->data->getName() == name)
			{
				cout << "Restaurant Found" << endl;
				cout << "Restaurant Name " << "\t" << "Area" << endl;
				cout << temp->data->getName() << "\t\t" << temp->data->getArea() << endl;
				break;
			}
			else if (temp->data->getName() > name)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
			temp = head;
		}
	}
};


int main() {
	
	// eight restaurants
	Restaurant* r1 = new Restaurant("Broadway", "Clifton");
	Restaurant* r2 = new Restaurant("Broadway", "DHA");
	Restaurant* r3 = new Restaurant("Burger O Clock", "Clifton");
	Restaurant* r4 = new Restaurant("Burger O Clock", "Gulshan");
	Restaurant* r5 = new Restaurant("McDonalds", "Clifton");
	Restaurant* r6 = new Restaurant("Naan stop", "Bahadurabad");
	Restaurant* r7 = new Restaurant("Pizza Hut", "DHA");
	Restaurant* r8 = new Restaurant("Zahid Nihari", "Bahadurabad");

	// create linked list
	LinkedList* list = new LinkedList();
	list->insert(r1);
	list->insert(r2);
	list->insert(r3);
	list->insert(r4);
	list->insert(r5);
	list->insert(r6);
	list->insert(r7);
	list->insert(r8);
	
	// display linked list
	list->display();

	cout << endl;
	// search restaurant
	string name;
	cout << "Enter Restaurant Name: ";
	getline(cin, name);
	list->binarySearch(name);
}

