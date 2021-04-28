//20402 권성빈
#include <iostream>
#include <stack>

using namespace std;

int length;

int main() 
{
	stack<int> stack1;
	cout << "숫자를 세 개 입력해주십시오." << endl;

	for (int i = 0; i < 3; i++)
	{
		int r = 0;
		cin >> r;
		stack1.push(r);
	}

	cout << endl << "입력받은 순서의 반대로 출력하겠습니다." << endl << endl;
	while (!stack1.empty())
	{
		cout << stack1.top() << " ";
		stack1.pop();
	}

	return(0);
}