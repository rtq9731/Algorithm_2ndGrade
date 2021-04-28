//20402 권성빈
#include <iostream>

using namespace std;

int main()
{
	char arr[5][10] = { 0, };

	cout << " 10글자의 영단어를 5개 입력해주십시오." << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 5; i++)
	{

		cout << endl << " 출력 " << endl;

		for (int j = 9; j > -1; j--)
			cout << arr[i][j];

		cout << endl;
	}

}