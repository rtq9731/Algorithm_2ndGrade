//20402 �Ǽ���
#include <iostream>

using namespace std;

float Gauss(int n)
{
	return ((1 + n) * n) / 2;
}

int main()
{
	int n = 100;
	cout << n << "�� ������ ���ӵ� ���� ��: " << Gauss(n);
	return(0);
}
