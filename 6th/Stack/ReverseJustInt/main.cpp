//20402 �Ǽ���
#include <iostream>
#include <stack>
#include <string>
#include <typeinfo>

using namespace std;

int main() 
{
	stack<char> stack1;

	string str;
	cout << "int ���� ���� ���ڸ� �Է� ���ֽʽÿ�. ( 21�� �̻��� ���� �Է����� �ʱ⸦ �����մϴ�. ): ";
	cin >> str;

	/*
	if (stol(str) > 2147483647)
	{
		cout << "��� : ���ڰ� int �ڷ����� �ִ񰪺��� Ů�ϴ� !" << endl;
		cout << "���α׷��� �����մϴ�." << endl;
		return (0);
	}
	//*/

	for (int i = 0; i < str.length(); i++)
	{
		stack1.push((str[i]));
		if ('0' - 1 > (str[i]) || (str[i]) > '9' + 1 )
		{
			cout << "��� : ���ڿ��� �����ֽ��ϴ� !" << endl;
			cout << "���α׷��� �����մϴ�." << endl;
			return (0);
		}
	}

	while (!stack1.empty())
	{
		cout << stack1.top();
		stack1.pop();
	}

	return (0);
}