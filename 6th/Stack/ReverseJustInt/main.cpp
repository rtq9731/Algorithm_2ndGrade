//20402 권성빈
#include <iostream>
#include <stack>
#include <string>
#include <typeinfo>

using namespace std;

int main() 
{
	stack<char> stack1;

	string str;
	cout << "int 범위 내의 숫자를 입력 해주십시오. ( 21억 이상의 값은 입력하지 않기를 권장합니다. ): ";
	cin >> str;

	/*
	if (stol(str) > 2147483647)
	{
		cout << "경고 : 숫자가 int 자료형의 최댓값보다 큽니다 !" << endl;
		cout << "프로그램을 종료합니다." << endl;
		return (0);
	}
	//*/

	for (int i = 0; i < str.length(); i++)
	{
		stack1.push((str[i]));
		if ('0' - 1 > (str[i]) || (str[i]) > '9' + 1 )
		{
			cout << "경고 : 문자열이 섞여있습니다 !" << endl;
			cout << "프로그램을 종료합니다." << endl;
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