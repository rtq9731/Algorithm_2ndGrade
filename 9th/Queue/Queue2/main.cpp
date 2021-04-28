//20402 �Ǽ���

	/*  [ ���ǻ��� ]
		�Ʒ��� ť�� ���� �� ����� �̻��� �������� queue STL�� ����Ͽ� ����������ϴ�.
		queue STL�� ���������� Vector�� �����Ǿ� �־�, �̹� ���� �迭�� �̷���� �ֽ��ϴ�.
		���� �迭�̱� ������ isFull, Ȥ�� �����÷ο츦 ������ �� �������ϴ�.
		�׸��Ͽ�, ������ 10�̶�� �����ϰ�, �ڵ带 ���ڽ��ϴ�.
	*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> q1;

bool isPull(queue<int> q1)
{
	if (q1.size() >= 10)
		return true;
	if (q1.size() < 10)
		return false;
}

bool isEmpty(queue<int> q1)
{

	if (q1.empty())
		return true;
	else
		return false;
}

int main()
{

	cout << "q1�� ����ֳ���? ";
	cout << (isEmpty(q1) ? "��" : "�ƴϿ�") << endl;
	cout << endl;

	for (int i = 0; i < 10; i++) // �⺻ ����� 10�̶�� ����
	{
		q1.push(10 * i); // queue STL������ push�� ������ ���� ������ �մϴ�.
	}

	cout << "q1�� ����ֳ���? ";
	cout << (isEmpty(q1) ? "��" : "�ƴϿ�") << endl;

	cout << "q1�� �� ���ֳ���? ";
	cout << (isPull(q1) ? "��" : "�ƴϿ�") << endl;


	return(0);

}