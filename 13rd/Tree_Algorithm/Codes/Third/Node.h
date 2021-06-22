#pragma once
#include<iostream>

class Node
{
private:

public:
    int data;
    Node* left;
    Node* right;
    Node(int data);

    inline void deleteThisNode() { delete this; }
    int getData();
    void setData(int data);
    void linkToLeft(Node* linkNode);
    void linkToRight(Node* linkNode);
    Node* getLeftNode();
    Node* getRightNode();
};

