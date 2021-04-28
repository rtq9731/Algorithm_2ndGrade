#include <stdio.h>

#include <Windows.h>

#include <time.h>



#define SIZE_X 40

#define SIZE_Y 40



int main()
{
	int i, j, x = 0, y = 0, rotate;

	int map[SIZE_X][SIZE_Y];

	for (i = 0; i < SIZE_Y; i++) {
		for (j = 0; j < SIZE_X; j++) {
			map[j][i] = 0;
		}
	}
	srand(time(NULL));
	map[x][y] = 1;

	//while(1){
	for (i = 0; i < 100000; i++) {

		rotate = rand() % 4 + 1; // 1위 2오른 3아래 4

		if (rotate == 1) {
			if (y == 0)
				continue; //만약 위에 공간이 없다면 rotate 다시설정

			if (map[x][y - 2] == 0) { //두칸위가 비어있다면
				y--; map[x][y] = 1;
				y--; map[x][y] = 1;

			}
			else { //두칸위가 채워져있다면
				y -= 2;
			}

		}

		if (rotate == 2) {

			if (x == SIZE_X - 2)
				continue;

			if (map[x + 2][y] == 0) {
				x++; map[x][y] = 1;
				x++; map[x][y] = 1;
			}
			else {
				x += 2;
			}
		}

		if (rotate == 3) {

			if (y == SIZE_Y - 2)
				continue;

			if (map[x][y + 2] == 0) {
				y++; map[x][y] = 1;
				y++; map[x][y] = 1;
			}
			else {
				y += 2;
			}
		}

		if (rotate == 4) {
			if (x == 0)
				continue;

			if (map[x - 2][y] == 0) {
				x--; map[x][y] = 1;
				x--; map[x][y] = 1;
			}
			else {
				x -= 2;
			}
		}
	}

	for (i = 0; i < SIZE_Y - 1; i++) {

		for (j = 0; j < SIZE_X - 1; j++) {

			if (map[j][i] == 0)

				printf("  ");

			if (map[j][i] == 1)

				printf("■");

		}

		printf("\n");

	}

	system("pause");

}

