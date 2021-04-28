//20402 ±Ç¼ººó
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack1;

	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);

	while(!stack1.empty())
	{
		cout << stack1.top();
		stack1.pop();
	}

	return (0);
}