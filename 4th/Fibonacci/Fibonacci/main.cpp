//20402 권성빈
#include <iostream>

using namespace std;

int fibonacci(int n);

int main()
{

	cout << "몇번 째의 피보나치 수를 구하시겠습니까?" << endl;

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
