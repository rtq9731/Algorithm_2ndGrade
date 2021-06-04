//20402 ±Ç¼ººó
//BinaryTree.cpp
#include "BinaryTree.h"

using namespace std;

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}

void SetData(BTreeNode* bt, int data)
{
	bt->data = data;
}

int Getdata(BTreeNode* node)
{
	return node->data;
}

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

BTreeNode* GetLeftSubTree(BTreeNode* main)
{
	return main->left;
}

BTreeNode* GetRightSubTree(BTreeNode* main)
{
	return main->right;
}


void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	cout << bt->data << endl;
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	InorderTraverse(bt->left);
	cout << bt->data << endl;
	InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	cout << bt->data << endl;
}