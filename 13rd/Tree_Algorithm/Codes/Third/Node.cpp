#include "Node.h"    

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int Node::getData()
{
    return this->data;
}

void Node::setData(int data)
{
    this->data = data;
}

void Node::linkToLeft(Node* linkNode)
{
    if (this->left != NULL)
        delete this->left;

    this->left = linkNode;
}

void Node::linkToRight(Node* linkNode)
{
    if (this->right != NULL)
        delete this->right;

    this->right = linkNode;
}

Node* Node::getLeftNode()
{
    return this->left;
}

Node* Node::getRightNode()
{
    return this->right;
}