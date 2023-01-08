#include <iostream>

using namespace std;

void quicksort(int nums[], int left, int right) {
	if (left >= right) return;
	int pivot = nums[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= pivot) j--;
		nums[i] = nums[j];
		while (i < j && nums[i] <= pivot) i++;
		nums[j] = nums[i];
	}
	nums[i] = pivot;
	quicksort(nums, left, i - 1);
	quicksort(nums, i + 1, right);
}

int main()
{
	int nums[] = { 2,0,2,1,1,0 };
	quicksort(nums, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}


