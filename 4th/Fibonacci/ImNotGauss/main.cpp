//20402 �Ǽ���
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
	cout << "��� ������ ���ӵ� ���� ���� ���ϰ� �����ʴϱ�?" << endl;
	int n;
	cin >> n;
	cout << n << "�� ������ ���ӵ� ���� ��: " << NotGauss(n);
	return(0);
}