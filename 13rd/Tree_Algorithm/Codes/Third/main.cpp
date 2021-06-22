#include <string>
#include <vector>
#include "Node.h"	

using namespace std;

vector<string> stringVector;
vector<Node> nodeVector;
vector<Node*> soloVector;

int nodeCount = 8; // 테스트용으로 8

string preorderStirng = "";
string postorderString = "";

string currentdata;
string leftdata;

int rootNodeData = 0;

void cutStringFirst();
void makeNodes();
void saveRootNodeData();
void InputPreorderPostorder();
void makeInorder();
void InorderTraverse(Node* node);
Node* findNodeByData(int data);


int main()
{
	InputPreorderPostorder();
	makeNodes();
	saveRootNodeData();
	cutStringFirst();
	makeInorder();
	cout << "중위 순회를 한 노드 순서는 :";
	InorderTraverse(findNodeByData(rootNodeData));
	return (0);
	/*
	cout << "preoder string : " << preorderStirng << endl;
	cout << "postorder string : " << postorderString << endl;
	cout << postorderString.find(preorderStirng[0]) << endl;
	cout << "left data : " << leftdata << endl;
	cout << "current data : " << currentdata << endl;
	*/
}

void InorderTraverse(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	InorderTraverse(node->left);
	cout << node->data;
	InorderTraverse(node->right);
}

void cutStringFirst()
{
	currentdata = postorderString.substr(0, postorderString.find(preorderStirng[0]) + 1);
	leftdata = postorderString.substr(postorderString.find(preorderStirng[0]) + 1, postorderString.length());
}

void makeInorder()
{
	int currentDataindex = 1;
	int leftDataindex = 1;
	do
	{
		if (currentdata.empty())
		{
			if (leftdata.find(preorderStirng[leftDataindex]) != string::npos)
			{
				currentdata = leftdata.substr(0, leftdata.find(preorderStirng[leftDataindex]) + 1);
				leftdata = leftdata.substr(leftdata.find(preorderStirng[leftDataindex]) + 1, leftdata.length());

				leftDataindex++;
			}
			else
			{
				if (leftDataindex > preorderStirng.size() - 1)
					break;

				leftDataindex++;
				continue;
			}
		}
		else
		{
			if (currentdata.find(preorderStirng[currentDataindex]) != string::npos)
			{
				string temp = currentdata.substr(currentdata.find(preorderStirng[currentDataindex]) + 1, currentdata.length());
				currentdata = currentdata.substr(0, currentdata.find(preorderStirng[currentDataindex]) + 1);
				temp += leftdata;
				leftdata = temp;

				currentDataindex++;
			}
			else
			{
				if (currentDataindex > preorderStirng.size() - 1)
					break;

				currentDataindex++;
				continue;
			}
		}


		if (currentdata.length() <= 3)
		{
			if (currentdata.length() == 3)
			{
				Node* parentNode_ptr = findNodeByData(currentdata[2] - '0');
				parentNode_ptr->linkToLeft(findNodeByData(currentdata[0] - '0'));
				parentNode_ptr->linkToRight(findNodeByData(currentdata[1] - '0'));

				soloVector.push_back(findNodeByData(currentdata[2]));

				string temp = "";
				temp += currentdata[2];
				temp += leftdata;
				leftdata = temp;

				currentdata = "";

			}
			else if (currentdata.length() == 2)
			{
				Node* parentNode_ptr = findNodeByData(currentdata[1] - '0');

				if (soloVector.size() > 0)
				{
					parentNode_ptr->linkToLeft(soloVector.front());
					soloVector.erase(soloVector.begin());
				}

				if (parentNode_ptr->left == nullptr)
				{
					parentNode_ptr->linkToLeft(findNodeByData(currentdata[0] - '0'));
				}
				else
				{
					parentNode_ptr->linkToRight(findNodeByData(currentdata[0] - '0'));
				}

				string temp = "";
				temp += currentdata[1];
				temp += leftdata;
				leftdata = temp;

				leftDataindex = 0;
				currentdata = "";
			}
			else
			{
				if (findNodeByData(currentdata[0] - '0')->data == rootNodeData)
				{
					break;
				}

				Node* parentNode_ptr = nullptr;


				if (findNodeByData(leftdata[1] - '0') != nullptr)
				{
					parentNode_ptr = findNodeByData(leftdata[1] - '0');
				}
				else
				{
					parentNode_ptr = findNodeByData(leftdata[0] - '0');
				}

				if (soloVector.size() > 0)
				{
					parentNode_ptr->linkToLeft(soloVector.front());
					soloVector.erase(soloVector.begin());
				}

				if (parentNode_ptr->left == nullptr)
				{
					parentNode_ptr->linkToLeft(findNodeByData(currentdata[0] - '0'));
				}
				else
				{
					parentNode_ptr->linkToRight(findNodeByData(currentdata[0] - '0'));
				}

				currentdata = "";
			}
		}

	} while ((leftdata.length() != 0 && currentdata.length() != 0)|| currentDataindex != preorderStirng.size() - 1 || leftDataindex != preorderStirng.size() - 1);
}

void InputPreorderPostorder()
{
	cout << "전체 노드는 몇개입니까? : ";
	cin >> nodeCount;

	cout << "전위 순회를 한 노드 순서를 입력해주세요 : ";
	for (int i = 0; i < nodeCount; i++)
	{
		string temp;
		cin >> temp; 
		preorderStirng += temp;
	}

	cout << "후위 순회를 한 노드 순서를 입력해주세요 : ";
	for (int i = 0; i < nodeCount; i++)
	{
		string temp;
		cin >> temp;
		postorderString += temp;
	}
}

void makeNodes()
{
	for (int i = 0; i < preorderStirng.size(); i++)
	{
		nodeVector.push_back(Node(preorderStirng[i] - '0'));
	}

}

void saveRootNodeData()
{
	rootNodeData = stoi(preorderStirng.substr(0, 1));

	preorderStirng = preorderStirng.substr(1, preorderStirng.size());
}


Node* findNodeByData(int data)
{
	Node* ptr_Temp = nullptr;
	for (int i = 0; i < nodeVector.size(); i++)
	{
		if (nodeVector[i].data == data)
		{
			ptr_Temp = &nodeVector[i];
			return ptr_Temp;
		}
	}

	return ptr_Temp;
}