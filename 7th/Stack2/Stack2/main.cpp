#include <iostream>
#include <stack>
#include <time.h>
#include <Windows.h>

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % n)+ 1;

#define MAZESIZE_X 10
#define MAZESIZE_Y 11

using namespace std;

typedef struct Position {
	int x;
	int y;
} Position;

typedef struct Direction {
	Position up = { 0, 1 };
	Position down = { 0, -1 };
	Position right = { 1, 0 };
	Position left = { -1 , 0 };
} Direction;

Position exit_XY = { 0, 0 };
stack<Position> trace;

int start_X;
int start_Y;
int moveCount = 0;
int reverseCount = 0;


int top;


int maze[MAZESIZE_Y][MAZESIZE_X];
int mark[MAZESIZE_Y][MAZESIZE_X];

void OpenRandUp(int randNum, int& x, int& y)
{
	int temp1 = rand() % randNum;
	int temp = maze[y - 2][x - temp1];

	if (temp != 0)
		return OpenRandUp(randNum, x, y);
	else
	{
		maze[y - 1][x] = 0;
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
	Sleep(50);
	system("cls");

	cout << "지정 받은 출구의 좌표 : " << exit_XY.x << " , " << exit_XY.y << endl;
	cout << endl;
	cout << "현재 좌표는 " << pos.x << " , " << pos.y << endl;
	cout << endl;
	cout << "움직인 횟수는 " << moveCount << endl;
	cout << endl;
	cout << "되돌린 횟수는 " << reverseCount << endl;

	for (int i = 0; i < MAZESIZE_Y; i++)
	{
		for (int j = 0; j < MAZESIZE_X; j++)
		{
			if (i == pos.y && j == pos.x) { cout << "★"; continue; }
			if (i == exit_XY.y && j == exit_XY.x) { cout << "▣"; continue; }
			//if (i == exit_Y && j == exit_X) { cout << "♥"; continue; }
			if (maze[i][j] == 1) cout << "■";
			if (maze[i][j] == 0) cout << "□";
		}
		cout << endl;
	}
}
void showMaze()
{

	system("cls");

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
	cin >> exit_XY.x;
	cout << endl;
	cout << "y : ";
	cin >> exit_XY.y;
	cout << endl;
}

int main()
{
	randomize();
	makeMaze();
	Position now;
	Direction dir;

	now.x = 1;
	now.y = 1;

	memcpy(mark, maze, sizeof(maze));
	showMaze(now); 
	getMazeOut();
	trace.push(now);
		while (!trace.empty())
		{
			for (int i = 0; i < 5; i++)
			{
				if (i == 0)
				{
					if (mark[now.y + dir.up.y][now.x + dir.up.x] == 1)
						continue;

					mark[now.y][now.x] = 1;

					now.y = now.y + dir.up.y;
					now.x = now.x + dir.up.x;
					moveCount++;
					trace.push(now);
					showMaze(now);
					break;
				}
				else if (i == 1)
				{
					if (mark[now.y + dir.down.y][now.x + dir.down.x] == 1)
						continue;

					mark[now.y][now.x] = 1;

					now.y = now.y + dir.down.y;
					now.x = now.x + dir.down.x;
					moveCount++;
					trace.push(now);
					showMaze(now);
					break;
				}
				else if (i == 2)
				{
					if (mark[now.y + dir.right.y][now.x + dir.right.x] == 1)
						continue;

					mark[now.y][now.x] = 1;

					now.y = now.y + dir.right.y;
					now.x = now.x + dir.right.x;
					moveCount++;
					trace.push(now);
					showMaze(now);
					break;
				}
				else if (i == 3)
				{
					if (mark[now.y + dir.left.y][now.x + dir.left.x] == 1)
						continue;

					mark[now.y][now.x] = 1;

					now.y = now.y + dir.left.y;
					now.x = now.x + dir.left.x;
					moveCount++;
					trace.push(now);
					showMaze(now);
					break;
				}
				else
				{
					if (trace.top().x == 1 && trace.top().y == 1)
					{
						cout << "미로의 출구를 찾는데 실패하였습니다." << endl;
						return (0);
					}
					trace.pop();
					mark[now.y][now.x] = 1;
					now.y = trace.top().y;
					now.x = trace.top().x;
					moveCount++;
					reverseCount++;
					showMaze(now);
					break;
				}
			}

			if (now.x == exit_XY.x && now.y == exit_XY.y)
			{
				showMaze(now);
				cout << "미로의 출구를 찾았습니다!" << endl;
				cout << "프로그램을 종료합니다." << endl;
				return (0);
			}

		}
	return (0);
}