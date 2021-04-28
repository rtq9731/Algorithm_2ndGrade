//20402 권성빈
#include <iostream>
#include <stack>
#include <string>
#include <list>

using namespace std;

int main()
{
	int n;
	stack<string> strStack;
	cout << "몇개의 데이터를 거꾸로 출력하시겠습니까? ( 1000개 이하로 입력해주십시오 ) ";
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