//20402 �Ǽ���
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> sInput;

	string input;
	cout << " ���ڸ� �Է����ּ��� ��" << endl;
	cin >> input;

	for (int i = input.length(); i > -1; i--)
	{
		sInput.push(input[i]);
		if (i % 3 == 0 && i != 0 && i != input.length())
		{
			sInput.push(',');
		}
	}

	cout << endl;

	for (int i = 0; i <= input.length() + 1; i++)
	{
		cout << sInput.top();
		sInput.pop();
	}

	return(0);
}