//20402 �Ǽ���
#include <iostream>

using namespace std;

int Reverse(int n)
{
	if (n <= 0)
		return 1;

	cout << n % 10;

	return Reverse(n / 10);
}

int main()
{

	int n = 0;

	cout << "�Ųٷ� �Է��Ͻð� ���� �������� �Է����ּ���!" << endl;

	cin >> n;

	Reverse(n);
	cout << " : ������ �βٰ�" << endl;

	return (0);
}