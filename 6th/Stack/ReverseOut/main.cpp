//20402 �Ǽ���
#include <iostream>
#include <stack>

using namespace std;

int length;

int main() 
{
	stack<int> stack1;
	cout << "���ڸ� �� �� �Է����ֽʽÿ�." << endl;

	for (int i = 0; i < 3; i++)
	{
		int r = 0;
		cin >> r;
		stack1.push(r);
	}

	cout << endl << "�Է¹��� ������ �ݴ�� ����ϰڽ��ϴ�." << endl << endl;
	while (!stack1.empty())
	{
		cout << stack1.top() << " ";
		stack1.pop();
	}

	return(0);
}