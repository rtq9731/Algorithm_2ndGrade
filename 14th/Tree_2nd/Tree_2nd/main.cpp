// 20402 권성빈
// 삽질을 하려고 했으나, 
// 독해능력이 여전히 딸려서, 
// 솔직히 인터넷에서 코드를 따왔읍니다..
// 죄송함니다..

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
	// 근노드
	cout << (lmax - cur + 1 + start);
	// 왼쪽 서브트리
	pre(level - 1, cur, n);
	// 오른쪽 서브트리
	pre(level - 1, cur + (1 << (n - level)), n);
}

int main()
{
	int n;
	cin >> n;
	pre(n, 1, n);
}