#include <iostream>

using namespace std;

// There are  types of query:

//"1 v " - Add an element  to the heap.
//"2 v" - Delete the element  from the heap.
//"3" - Print the minimum of all the elements in the heap.

int main()
{
	int n;
	cin >> n;
	int heap[100000];
	int heapSize = 0;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int value;
			cin >> value;
			heap[heapSize] = value;
			int index = heapSize;
			while (index > 0)
			{
				int parent = (index - 1) / 2;
				if (heap[parent] > heap[index])
				{
					int temp = heap[parent];
					heap[parent] = heap[index];
					heap[index] = temp;
					index = parent;
				}
				else
				{
					break;
				}
			}
			heapSize++;
		}
		else if (type == 2)
		{
			int value;
			cin >> value;
			int index = 0;
			while (index < heapSize)
			{
				if (heap[index] == value)
				{
					heap[index] = heap[heapSize - 1];
					heapSize--;
					break;
				}
				index++;
			}
			while (index < heapSize)
			{
				int left = index * 2 + 1;
				int right = index * 2 + 2;
				if (left >= heapSize)
				{
					break;
				}
				else if (right >= heapSize)
				{
					if (heap[index] > heap[left])
					{
						int temp = heap[index];
						heap[index] = heap[left];
						heap[left] = temp;
						index = left;
					}
					else
					{
						break;
					}
				}
				else
				{
					if (heap[index] > heap[left] || heap[index] > heap[right])
					{
						if (heap[left] < heap[right])
						{
							int temp = heap[index];
							heap[index] = heap[left];
							heap[left] = temp;
							index = left;
						}
						else
						{
							int temp = heap[index];
							heap[index] = heap[right];
							heap[right] = temp;
							index = right;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			cout << heap[0] << endl;
		}
	}
	return 0;
}
	