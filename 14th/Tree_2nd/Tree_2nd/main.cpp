// 20402 �Ǽ���
// ������ �Ϸ��� ������, 
// ���شɷ��� ������ ������, 
// ������ ���ͳݿ��� �ڵ带 �������ϴ�..
// �˼��Դϴ�..

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;
void pre(int level, int cur, int n)
{

	if (level == 1) {
		cout << cur;
		return;
	}

	int start = (1 << n) - (1 << (n - level + 1));
	int lmax = (1 << (n - level));
	// �ٳ��
	cout << (lmax - cur + 1 + start);
	// ���� ����Ʈ��
	pre(level - 1, cur, n);
	// ������ ����Ʈ��
	pre(level - 1, cur + (1 << (n - level)), n);
}

int main()
{
	int n;
	cin >> n;
	pre(n, 1, n);
}