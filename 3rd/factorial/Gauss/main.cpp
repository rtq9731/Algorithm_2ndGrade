//20402 권성빈
#include <iostream>

using namespace std;

float Gauss(int n)
{
	return ((1 + n) * n) / 2;
}

int main()
{
	int n = 100;
	cout << n << "번 까지의 연속된 수의 합: " << Gauss(n);
	return(0);
}
