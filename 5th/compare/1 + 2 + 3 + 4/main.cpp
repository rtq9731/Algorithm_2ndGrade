//20402 �Ǽ���
#include <iostream>
#include <string>

using namespace std;

int plusNum(int number, string stringNumber);
int result = 0;

int main() 
{
	int number = 0;
	cout << "4�ڸ� �̻��� ���ڸ� �Է����ֽʽÿ�" << endl;
	cin >> number;

	string stringNumber = to_string(number);
	cout << "�� �ڸ����� ���� " << plusNum(number, stringNumber) << endl;

	return (0);
}

int plusNum(int number, string stringNumber)
{

	if (stringNumber.length() == 1)
		return result + number;

	int temp1 = number;
	int temp2 = 0;
	int temp3 = 10;
	int temp4 = 0;

	for (int i = 0; i < stringNumber.length() - 2; i++)
		temp3 *= 10;


	for (int i = 0; i < stringNumber.length() - 1; i++)
	{
		temp1 /= 10; // ���� ó�� �ڸ����� ���ڸ� temp1 �� ���� ex) 12345 �� 1
	}

	result += temp1;

	temp4 = number % temp3;

	return plusNum(temp4, to_string(number / 10));
}
