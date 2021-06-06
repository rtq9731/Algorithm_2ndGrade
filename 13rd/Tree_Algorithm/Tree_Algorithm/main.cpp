//20402 권성빈
#include <iostream>
#include <list>
#include "TreeNode.h"

using namespace std;

int level;
int numberOfNodes;
list<int> preorderIntList;
list<int> postorderIntList;

struct Data
{
	int last;
	int lastlast;
};

int main()
{
	Data* preorderData = new Data	{0, 0};
	Data* postorderData = new Data	{0, 0};

	cout << "레벨을 입력해주십시오 : ";
	cin >> level;
	for (int i = 0; i < level + 1; i++)
	{
		if (i == 0)
		{
			numberOfNodes += 1;
			continue;
		}

		int temp2 = 2;
		for (int j = i - 1; j > 0 ; j--)
		{
			if (j == 0)
				continue;

			temp2 *= 2;
		}
		numberOfNodes += temp2;
	}
	cout << numberOfNodes;

	for (int i = 0; i < numberOfNodes; i++)
	{
		int temp;
		cin >> temp;

		preorderIntList.push_back(temp);
	}
	for (int i = 0; i < numberOfNodes; i++)
	{
		int temp;
		cin >> temp;

		postorderIntList.push_back(temp);
	}


	return(0);
}