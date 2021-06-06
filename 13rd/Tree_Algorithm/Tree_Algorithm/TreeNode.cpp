#include "TreeNode.h"	

TreeNode::TreeNode(int data)
{
	this->data = data;
}

int TreeNode::getData()
{
	return this->data;
}

void TreeNode::setData(int data)
{
	this->data = data;
}

void TreeNode::linkToLeft(TreeNode* linkNode)
{
	if (this->left != NULL)
		delete this->left;

	this->left = linkNode;
}

void TreeNode::linkToRight(TreeNode* linkNode)
{
	if (this->right != NULL)
		delete this->right;

	this->right = linkNode;
}

TreeNode* TreeNode::getLeftTreeNode()
{
	return this->left;
}

TreeNode* TreeNode::getRightTreeNode()
{
	return this->right;
}