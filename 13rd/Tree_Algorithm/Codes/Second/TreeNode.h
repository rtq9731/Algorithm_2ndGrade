#pragma once
#include<iostream>

class TreeNode
{

private:
	int data;
	int parent;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode();
	TreeNode(int data);

	void deleteThisNode();
	int getData();
	void setData(int data);
	void linkToLeft(TreeNode linkNode);
	void linkToRight(TreeNode linkNode);
	TreeNode* getLeftTreeNode();
	TreeNode* getRightTreeNode();
};

