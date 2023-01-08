#include <iostream>
#include <queue>

using namespace std;

//Given an array of integers temperatures represents the daily temperatures, 
//return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a 
//warmer temperature.If there is no future day for which this is possible, keep answer[i] == 0 instead.

// using queues

int main()
{
	int n;
	cin >> n;
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	queue<int> q;
	int ans[4];
	for (int i = 0; i < 4; i++)
	{
		while (!q.empty() && arr[q.back()] < arr[i])
		{
			ans[q.back()] = i - q.back();
			q.pop();
		}
		q.push(i);
	}
	while (!q.empty())
	{
		ans[q.back()] = 0;
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}


