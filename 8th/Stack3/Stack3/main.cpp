//20402 �Ǽ���
#include <iostream>
#include <stack>
#include <string>
#include <list>

using namespace std;

int main()
{
	int n;
	stack<string> strStack;
	cout << "��� �����͸� �Ųٷ� ����Ͻðڽ��ϱ�? ( 1000�� ���Ϸ� �Է����ֽʽÿ� ) ";
	cin >> n;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		strStack.push(input);
	}

	for (int i = 0; i < n; i++)
	{
		cout << strStack.top() << " ";
		strStack.pop();
	}

	return (0);
}