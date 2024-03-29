#include <iostream>
#include <stack>
#include <time.h>

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % n)+ 1;

#define MAZESIZE_X 40
#define MAZESIZE_Y 41

typedef struct Position {
	int x;
	int y;
	int d;
} Position;

typedef struct Mtable {
	int x;
	int y;
} Mtable;


int exit_X;
int exit_Y;

int start_X;
int start_Y;

int mark[MAZESIZE_Y][MAZESIZE_X] = { 0, };

int top;

stack<Position> trace;

using namespace std;

int maze[MAZESIZE_Y][MAZESIZE_X];

void OpenRandUp(int randNum, int& x, int& y)
{
	int temp1 = rand() % randNum;
	int temp = maze[y - 2][x - temp1];

	if (temp != 0)
		return OpenRandUp(randNum, x, y);
	else
	{
		maze[y - 1][x - temp1] = 0;
		return;
	}
}

void makeMaze()
{

	for (int y = 0; y < MAZESIZE_Y; y++)
		for (int x = 0; x < MAZESIZE_X; x++)
		{
			if (y == 1 && x > 0 && x < MAZESIZE_X - 1)
			{
				maze[y][x] = 0;
				continue;
			}

			maze[y][x] = 1;
		}

	randomize();

	for (int y = 3; y < MAZESIZE_Y - 1; y += 2)
	{
		int count = 0;
		int randNum = 0;
		for (int x = 1; x < MAZESIZE_X - 1; x++)
		{
			if (count == 0)
			{
				randNum = rand() % 4 + 2;
				maze[y][x] = 0;
				count++;
			}
			else if (count < randNum)
			{
				maze[y][x] = 0;
				count++;
			}
			else if (count == randNum || x == MAZESIZE_X - 2)
			{
				maze[y][x] = 0;
				OpenRandUp(randNum, x, y);
				x++;
				count = 0;
			}
		}
	}

}

void showMaze(Position pos)
{

	cout << "지정 받은 출구의 좌표 : " << exit_X << exit_Y << endl;
	cout << endl;
	cout << "현재 좌표는 " << pos.x << pos.y << endl;
	cout << endl;

	for (int i = 0; i < MAZESIZE_Y; i++)
	{
		for (int j = 0; j < MAZESIZE_X; j++)
		{
			if (i == pos.y && j == pos.x) { cout << "★"; continue; }
			if (i == exit_Y && j == exit_X) { cout << "♥"; continue; }
			if (maze[i][j] == 1) cout << "■";
			if (maze[i][j] == 0) cout << "□";
		}
		cout << endl;
	}
}
void showMaze()
{

	for (int i = 0; i < MAZESIZE_Y; i++)
	{
		for (int j = 0; j < MAZESIZE_X; j++)
		{
			if (maze[i][j] == 1)
				cout << "■";

			if (maze[i][j] == 0)
				cout << "□";
		}
		cout << endl;
	}
}

void getMazeOut()
{
	cout << "출구의 좌표를 입력 해주십시오" << endl;
	cout << "x : ";
	cin >> exit_X;
	cout << endl;
	cout << "y : ";
	cin >> exit_Y;
	cout << endl;
}

void popLastPos(Position* P)
{
	trace.pop();
	P->x = trace.top().x;
	P->y = trace.top().y;
	P->d = trace.top().d;
}

void pushThisPos(Position P)
{
	trace.push(P);
}

int main()
{

	Mtable move[4] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{0, -1}
	};

	bool isFound = false;
	int i, dir;

	Position now = { 1, 1, 1 };
	Position next;

	makeMaze();
	showMaze();
	getMazeOut();
	showMaze(now);

	pushThisPos(now);
	while (!isFound && top > 0)
	{
		popLastPos(&now);
		dir = now.d;
		while (dir < 4) {
			next.x = now.x + move[dir].x;
			next.y = now.x + move[dir].y;
			if (next.x == exit_X && next.y == exit_Y)
			{
				next.d = dir;
				pushThisPos(next);
				isFound = true;
				break;
			}
			else if ((maze[next.y][next.x] == 1) && (mark[next.y][next.x] == 0))
			{
				now.d = ++dir;
				pushThisPos(now);
				now.x = next.x;
				now.y = next.y;
				dir = 0;

				mark[next.y][next.x] = 1;
			}
			else
				dir++;

			showMaze(now);
		}
	}
	if (isFound == true)
		for (int i = 0; i < trace.size(); i++)
		{
			showMaze(trace[i]);
		}
	else
	{
		cout << "출구로 향하는 길을 찾지 못했습니다!" << endl;
	}

	system("pause");

	return (0);
}