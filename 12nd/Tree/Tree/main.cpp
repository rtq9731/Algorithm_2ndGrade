//20402 권성빈
#include <iostream>

// 1. 자료형의 정의

typedef int BTData;

struct BTreeNode
{
	BTData data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

// 2. 선언된 자료형(BTreeNode)

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

// 3. 메모리 삭제 함수 생성

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}

// 4. 변수(노드)에 값 설정

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

// 5. 이진트리의 관계 설정

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