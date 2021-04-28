//20402 권성빈
#include <iostream>

using namespace std;

void hanoiTower(int, string, string, string);

int main()
{
	int number;
	string start, pass, destination;
	cout << "-----------하노이 탑 알고리즘-----------" << endl;
	cout << "원반의 갯수를 정해주세요." << endl;
	cin >> number;
	cout << "어디서 시작할지 정해주세요." << endl;
	cin >> start;
	cout << "어디를 지나야 하는지 알려주세요." << endl;
	cin >> pass;
	cout << "어디가 목적지인지 정해주세요." << endl;
	cin >> destination;

	hanoiTower(number, start, pass, destination);

	return (0);
}

void hanoiTower(int numberOfRing, string from, string by, string to)
{

	if (numberOfRing == 1)
	{
		cout << "원반 " << numberOfRing << " 을 " << from << " 에서 " << to << " 으로 이동합니다. " << endl;
	}
	else
	{
		hanoiTower(numberOfRing - 1, from, to, by);
		cout << "원반 " << numberOfRing << "을(를)" << from << " 에서 " << to << " 으로 이동합니다. " << endl;
		hanoiTower(numberOfRing - 1, by, from, to);
	}
}