//20402 권성빈
#include <iostream>

using namespace std;

float NotGauss(int n)
{

	if (n == 1)
		return 1;

	return n + NotGauss(n - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << n << "번 까지의 연속된 수의 합: " << NotGauss(n);
	return(0);
}