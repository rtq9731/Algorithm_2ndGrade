//20402 �Ǽ���
#include <iostream>

using namespace std;

int main()
{
	char arr[5][10] = { 0, };

	cout << " 10������ ���ܾ 5�� �Է����ֽʽÿ�." << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 5; i++)
	{

		cout << endl << " ��� " << endl;

		for (int j = 9; j > -1; j--)
			cout << arr[i][j];

		cout << endl;
	}

}