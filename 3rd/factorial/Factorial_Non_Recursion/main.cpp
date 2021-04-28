//20402 권성빈
#include <iostream>

using namespace std;

int result = 1;

int Factorial(int n) //5
{

	for (int i = 1; i < n + 1; i++)
	{
		result *= i;
	}

	return result;
}

int main()
{
	int n = 0;
	cout << "몇 팩토리얼을 구하시겠습니까?" << endl;
	cin >> n;
	cout << n << "! = " << Factorial(n);
	return(0);
}