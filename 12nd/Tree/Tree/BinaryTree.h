//20402 ±Ç¼ººó
//BinaryTree.h
#pragma once
#include <iostream>

struct BTreeNode
{
	int data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

BTreeNode* MakeBTreeNode(void);

void DeleteBTreeNode(BTreeNode* bt);

void SetData(BTreeNode* bt, int data);

int Getdata(BTreeNode* node);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* GetLeftSubTree(BTreeNode* main);
BTreeNode* GetRightSubTree(BTreeNode* main);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);