// �ۼ��� : 20402 �Ǽ���
#include <iostream>

using namespace std;

int temp = 0;
int temp1 = 2;
int temp2 = 2;
int result = 0;

int main()
{

	char identity[14]{ 1, };
	cout << "�ֹε�Ϲ�ȣ 13�ڸ��� '-' ���� �Է����ֽʽÿ�." << endl;
	cin >> identity;

	for (int i = 0; i < 12; i++)
	{
		if (i >= 10)
		{
			temp += (identity[i] - '0') * temp2;
			temp2++;
			cout << temp << endl;
		}
		if (i < 10)
		{
			temp += (identity[i] - '0') * temp1;
			temp1++;
			cout << temp << endl;
		}
	}

	result = (11 - (temp % 11));
	cout << result << endl;
	if (result == 11)
	{
		result = 1;
	}
	if (result == 10)
	{
		result = 0;
	}

	if ((identity[12] - '0') != temp)
	{
		cout << "13��° �ڸ� : " << (identity[12] - '0') << endl;
		cout << "������ : " << result << endl;
		cout << "�߸��� �ֹε�Ϲ�ȣ�Դϴ�!" << endl;
		cout << "���α׷��� �����մϴ�..." << endl;
		return (0);
	}


	if (identity[6] == '1' || identity[6] == '3')
		cout << "���� : ���� " << endl;
	if (identity[6] == '2' || identity[6] == '4')
		cout << "���� : ���� " << endl;
	 
	int area = (identity[7] - 48) * 10 + (identity[8] - '0');

	if (area < 9)
	{
		cout << "��� ���� : ���� ";
	}
	else if (area < 13)
	{
		cout << "��� ���� : �λ� ";
	}
	else if (area < 16)
	{
		cout << "��� ���� : ��õ ";
	}
	else if (area < 19)
	{
		cout << "��� ���� : ��⵵ ";
	}
	else if (area < 26)
	{
		cout << "��� ���� : ��⵵ ";
	}
	else if (area < 35)
	{
		cout << "��� ���� : ������ ";
	}
	else if (area < 40)
	{
		cout << "��� ���� : ��û�ϵ� ";
	}
	else if (area < 48)
	{
		cout << "��� ���� : ��û���� ";
	}
	else if (area < 55)
	{
		cout << "��� ���� : ����ϵ� ";
	}
	else if (area < 67)
	{
		cout << "��� ���� : ���󳲵� ";
	}
	else if (area < 91)
	{
		cout << "��� ���� : ��� ";
	}

	int year = (identity[0] - 48) * 10 + (identity[1] - '0');
	year += identity[6] <= '2' ? 1900 : 2000;
	cout << "��� ���� : " << year << " ";
	cout << "���� : " << 2021 - year + 1 << " " << endl;

	return(0);
}