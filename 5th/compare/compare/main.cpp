//20402 �Ǽ���
#include <iostream>

using namespace std;

int compare(int excuteCount, int arr[]);

int n_Max;
int length;
int isMaxCount = 0;

int main()
{

	cout << "��� ���ڸ� ���Ͻðڽ��ϱ�?" << endl;
	cin >> length;

	int* array = new int[length];

	cout << "���ڵ��� �ϳ��� �Է����ֽʽÿ�." << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	cout << "�ִ��� " << compare(0, array);

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