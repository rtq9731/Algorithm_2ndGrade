//20402 권성빈

	/*  [ 주의사항 ]
		아래의 큐는 숙제 낸 사람의 이상한 집착으로 queue STL을 사용하여 만들어졌습니다.
		queue STL은 내부적으론 Vector로 구현되어 있어, 이미 동적 배열로 이루어져 있습니다.
		동적 배열이기 때문에 isFull, 혹은 오버플로우를 구현할 수 없었습니다.
		그리하여, 제한이 10이라고 가정하고, 코드를 쓰겠습니다.
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

	cout << "q1은 비어있나요? ";
	cout << (isEmpty(q1) ? "네" : "아니요") << endl;
	cout << endl;

	for (int i = 0; i < 10; i++) // 기본 사이즈를 10이라고 가정
	{
		q1.push(10 * i); // queue STL에서는 push가 데이터 삽입 연산을 합니다.
	}

	cout << "q1은 비어있나요? ";
	cout << (isEmpty(q1) ? "네" : "아니요") << endl;

	cout << "q1은 꽉 차있나요? ";
	cout << (isPull(q1) ? "네" : "아니요") << endl;


	return(0);

}