//20402 �Ǽ���
#include <iostream>

using namespace std;

int fibonacci(int n);

int main()
{

	cout << "��� °�� �Ǻ���ġ ���� ���Ͻðڽ��ϱ�?" << endl;

	int n;
	cin >> n;

	cout << fibonacci(n) << endl;

	return(0);
}

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	
}
