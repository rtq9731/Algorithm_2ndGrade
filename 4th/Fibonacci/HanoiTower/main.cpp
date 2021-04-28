//20402 �Ǽ���
#include <iostream>

using namespace std;

void hanoiTower(int, string, string, string);

int main()
{
	int number;
	string start, pass, destination;
	cout << "-----------�ϳ��� ž �˰���-----------" << endl;
	cout << "������ ������ �����ּ���." << endl;
	cin >> number;
	cout << "��� �������� �����ּ���." << endl;
	cin >> start;
	cout << "��� ������ �ϴ��� �˷��ּ���." << endl;
	cin >> pass;
	cout << "��� ���������� �����ּ���." << endl;
	cin >> destination;

	hanoiTower(number, start, pass, destination);

	return (0);
}

void hanoiTower(int numberOfRing, string from, string by, string to)
{

	if (numberOfRing == 1)
	{
		cout << "���� " << numberOfRing << " �� " << from << " ���� " << to << " ���� �̵��մϴ�. " << endl;
	}
	else
	{
		hanoiTower(numberOfRing - 1, from, to, by);
		cout << "���� " << numberOfRing << "��(��)" << from << " ���� " << to << " ���� �̵��մϴ�. " << endl;
		hanoiTower(numberOfRing - 1, by, from, to);
	}
}