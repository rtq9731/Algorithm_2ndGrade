//20402 권성빈
#include <iostream>

using namespace std;

int compare(int excuteCount, int arr[]);

int n_Max;
int length;
int isMaxCount = 0;

int main()
{

	cout << "몇개의 숫자를 비교하시겠습니까?" << endl;
	cin >> length;

	int* array = new int[length];

	cout << "숫자들을 하나씩 입력해주십시오." << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	cout << "최댓값은 " << compare(0, array);

	delete[] array;

	return (0);
}

int compare(int excuteCount, int arr[])
{
	int excute = excuteCount;
	isMaxCount = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[excuteCount] > arr[i])
		{
			isMaxCount++;
		}
	}

	if (isMaxCount != length - 1)
	{
		excute += 1;
		return compare(excute, arr);
	}
	else
	{
		return arr[excuteCount];
	}
}