#pragma once
#include<iostream>

class TreeNode
{

private:
	int data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(int data);

	inline void deleteThisNode() { delete this; }
	int getData();
	void setData(int data);
	void linkToLeft(TreeNode* linkNode);
	void linkToRight(TreeNode* linkNode);
	TreeNode* getLeftTreeNode();
	TreeNode* getRightTreeNode();
};

