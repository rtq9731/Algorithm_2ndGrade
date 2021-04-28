//20402 권성빈
#include <iostream>

using namespace std;

int Factorial(int n) //5
{
	if (n == 1)
		return 1;

	return n * Factorial(n - 1);

}

int main()
{
	int n = 0;
	cout << "몇 팩토리얼을 구하시겠습니까?" << endl;
	cin >> n;
	cout << n << "! = " << Factorial(n);
	return(0);
}