//20402 �Ǽ���
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
	cout << "�� ���丮���� ���Ͻðڽ��ϱ�?" << endl;
	cin >> n;
	cout << n << "! = " << Factorial(n);
	return(0);
}