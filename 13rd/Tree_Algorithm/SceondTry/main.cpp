#include <iostream>
#include <string>
#include <list>

#pragma region TreeNode 클래스 선언
class TreeNode
{

private:
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int data);
    TreeNode();

    void deleteThisNode();
    int getData();
    void setData(int data);
    void linkToLeft(TreeNode linkNode);
    void linkToRight(TreeNode linkNode);
    TreeNode* getLeftTreeNode();
    TreeNode* getRightTreeNode();
};
#pragma endregion


#pragma region TreeNode 클래스 초기화

TreeNode::TreeNode()
{
    this->data = 0;
}

TreeNode::TreeNode(int data)
{
    this->data = data;
}

void TreeNode::deleteThisNode()
{
    delete this;
}

int TreeNode::getData()
{
    return this->data;
}

void TreeNode::setData(int data)
{
    this->data = data;
}

void TreeNode::linkToLeft(TreeNode linkNode)
{
    if (this->left != NULL)
        delete this->left;

    this->left = &linkNode;
}

void TreeNode::linkToRight(TreeNode linkNode)
{
    if (this->right != NULL)
        delete this->right;

    this->right = &linkNode;
}

TreeNode* TreeNode::getLeftTreeNode()
{
    return this->left;
}

TreeNode* TreeNode::getRightTreeNode()
{
    return this->right;
}
#pragma endregion

using namespace std;

TreeNode tree[100];
string stringList[100];

string preOrder;
string postOrder;

int stringIndex = 0;
int excuteCount = 0;

TreeNode& findNodeFromData(int data);

int main()
{
    stringIndex = 0;

    preOrder = "12467583";
    postOrder = "67485231";

    for (int i = 0; i < preOrder.size(); i++)
    {
        TreeNode* temp = new TreeNode(preOrder[i]);
        tree[i] = *temp;
    }

    cout << findNodeFromData(6).getData();
}

void subStringRightLeft(string postOrder)
{

    char a = preOrder[1];

    if (postOrder.size() < 4)
    {
        if (postOrder.size() < 3)
        {
            findNodeFromData(postOrder[2]).linkToLeft(findNodeFromData(postOrder[1]));
        }
        else
        {
            findNodeFromData(postOrder[3]).linkToLeft(findNodeFromData(postOrder[2]));
            findNodeFromData(postOrder[3]).linkToLeft(findNodeFromData(postOrder[1]));
        }
    }
    for (int i = 0; i < preOrder.size(); i++)
    {
        if (a == postOrder[i])
        {
            excuteCount++;

            stringIndex++;
        }
    };
}

TreeNode& findNodeFromData(int data)
{
    for (int i = 0; i < 100; i++)
    {
        if (&tree[i] == nullptr)
        {
            continue;
        }

        if (tree[i].getData() == data)
            return tree[i];
    }
}