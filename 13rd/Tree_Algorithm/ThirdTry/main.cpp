#include <string>
#include <vector>
#include "Node.h"	

using namespace std;

vector<string> stringVector;
vector<Node> nodeVector;

int nodeCount = 0;

string preoderStirng;
string postorderString;

Node* findNodeByData(int data)
{
	Node* ptr_Temp = nullptr;
	return ptr_Temp;
}

int main()
{
	/*
	cout << "��ü ���� ��Դϱ�? : ";
	cin >> nodeCount;

	cout << "���� ��ȸ�� �� ��� ������ �Է����ּ��� : ";
	for (int i = 0; i < nodeCount; i++)
	{
		cin >> preoderStirng[i];
	}

	cout << "���� ��ȸ�� �� ��� ������ �Է����ּ��� : ";
	for (int i = 0; i < nodeCount; i++)
	{
		cin >> postorderString[i];
	}
	*/

	Node n = Node(10);
	Node* ptr_Node = findNodeByData(1);
	ptr_Node = &n;
	
	cout << ptr_Node->data;
}