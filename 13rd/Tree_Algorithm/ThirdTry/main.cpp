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
	cout << "전체 노드는 몇개입니까? : ";
	cin >> nodeCount;

	cout << "전위 순회를 한 노드 순서를 입력해주세요 : ";
	for (int i = 0; i < nodeCount; i++)
	{
		cin >> preoderStirng[i];
	}

	cout << "후위 순회를 한 노드 순서를 입력해주세요 : ";
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