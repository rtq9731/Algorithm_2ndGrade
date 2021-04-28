//20402 권성빈
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

	cout << "거꾸로 입력하시고 싶은 십진수를 입력해주세요!" << endl;

	cin >> n;

	Reverse(n);
	cout << " : 수진십 로꾸거" << endl;

	return (0);
}