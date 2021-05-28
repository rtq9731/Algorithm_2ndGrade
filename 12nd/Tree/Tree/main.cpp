//20402 �Ǽ���
#include <iostream>

// 1. �ڷ����� ����

typedef int BTData;

struct BTreeNode
{
	BTData data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

// 2. ����� �ڷ���(BTreeNode)

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

// 3. �޸� ���� �Լ� ����

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}

// 4. ����(���)�� �� ����

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

// 5. ����Ʈ���� ���� ����

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		delete main->right;

	main->right = sub;
}