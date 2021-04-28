//20402 ±Ç¼ººó
#include <iostream>
#include <queue>

using namespace std;

queue<int> q1;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		q1.push(10 * i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << q1.front() << "\t";
		q1.pop();
	}

	return(0);
}