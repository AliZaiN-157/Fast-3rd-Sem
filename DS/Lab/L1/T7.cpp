#include <iostream>
using namespace std;

// Write a code that create a Class named Numbers, with private size and pointer variables , a public
// function to assign values to private memberand a destructor to destroy the pointerand memory.
// Understand what happens when you define an object by providing one object as an argument to another
// or simply assign one object to another.


class Numbers
{
	private:
		int *ptr;
		int size;
	public:
		Numbers(int size)
		{
			this->size = size;
			ptr = new int[size];
		}
		Numbers(const Numbers &obj)
		{
			this->size = obj.size;
			ptr = new int[size];
			for(int i = 0; i < size; i++)
			{
				ptr[i] = obj.ptr[i];
			}
		}
		~Numbers()
		{
			delete [] ptr;
		}
		void assign(int *ptr)
		{
			this->ptr = ptr;
		}
		void display()
		{
			for(int i = 0; i < size; i++)
			{
				cout << ptr[i] << " ";
			}
			cout << endl;
		}
};


int main()
{
	Numbers obj1(5);
	int arr[5] = {1,2,3,4,5};
	obj1.assign(arr);
	obj1.display();
	Numbers obj2(obj1);
	obj2.display();
	return 0;
}