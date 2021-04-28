//20402 권성빈
#include <iostream>
#include <string>

using namespace std;

int plusNum(int number, string stringNumber);
int result = 0;

int main() 
{
	int number = 0;
	cout << "4자리 이상의 숫자를 입력해주십시오" << endl;
	cin >> number;

	string stringNumber = to_string(number);
	cout << "각 자리수의 합은 " << plusNum(number, stringNumber) << endl;

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
		temp1 /= 10; // 가장 처음 자리수의 숫자를 temp1 에 저장 ex) 12345 중 1
	}

	result += temp1;

	temp4 = number % temp3;

	return plusNum(temp4, to_string(number / 10));
}
