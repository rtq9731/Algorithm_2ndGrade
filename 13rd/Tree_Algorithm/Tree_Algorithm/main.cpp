//20402 �Ǽ���
#include <list>
#include "TreeNode.h"

using namespace std;

int level;
int numberOfNodes;
int* preorderIntArr;
int* postorderIntArr;
TreeNode* nodeArr;

struct Data
{
	int nextnext;
	int next;
	int now;
	int last;
	int lastlast;
};

TreeNode* FindTreeNodeWithIndex(int input);

int main()
{
	list<Data> preorderData;
	Data* postorderData = new Data	{0, 0};

	cout << "( ��ȭ ����Ʈ������ �մϴ�. ) ������ �Է����ֽʽÿ� : ";
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
	preorderIntArr = new int[numberOfNodes];
	postorderIntArr = new int[numberOfNodes];
	nodeArr = new TreeNode[numberOfNodes];
	
	cout << "������ȸ�� �Է����ּ��� : ";
	for (int i = 0; i < numberOfNodes; i++)
	{
		int temp;
		cin >> temp;

		preorderIntArr[i] = temp;
	}

	cout << "������ȸ�� �Է����ּ��� : ";
	for (int i = 0; i < numberOfNodes; i++)
	{
		int temp;
		cin >> temp;

		postorderIntArr[i] = temp;
	}

	for (int i = 0; i < numberOfNodes; i++)
	{
		nodeArr[i].setData(i);
	}

	int indexForPreorder = 0;
	int indexForPostorder = 3;
	while (true)
	{
		if (indexForPreorder <= numberOfNodes )
		{
			preorderData.end()->now = preorderIntArr[indexForPreorder];
			preorderData.end()->next = preorderIntArr[indexForPreorder + 1];
			preorderData.end()->nextnext = preorderIntArr[indexForPreorder + 2];
		}
		else
		{
			break;
		}

		if (indexForPostorder - 2 >= -1)
		{
			postorderData->now = postorderIntArr[indexForPostorder];
			postorderData->last = postorderIntArr[indexForPostorder - 1];
			postorderData->lastlast = postorderIntArr[indexForPostorder - 2];
		}
		else
		{
			break;
		}

		if (preorderData.end()->now == postorderData->now)
		{
			TreeNode* temp;
			temp = FindTreeNodeWithIndex(postorderData->now);
			temp->linkToLeft(FindTreeNodeWithIndex(postorderData->lastlast));
			temp->linkToRight(FindTreeNodeWithIndex(postorderData->last));
			delete FindTreeNodeWithIndex(postorderData->last);
			delete FindTreeNodeWithIndex(postorderData->lastlast);
		}

		indexForPreorder++;
		indexForPostorder++;
	}

		
	delete[] preorderIntArr;
	delete[] postorderIntArr;
	delete[] nodeArr;

	return(0);
}

TreeNode* FindTreeNodeWithIndex(int input)
{
	for ( int i = 0; i < numberOfNodes; i++)
	{
		if (nodeArr[i].getData() == input)
		{
			TreeNode* temp = &nodeArr[i];
			return temp;
		}
	}
}