// 벽의 사이즈가 R, C로 주어진다. (Row, Column)
// brick과 hole이 1과 0으로 주어질 때 2*2보다 큰 hole의 개수를 출력하라.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int array[100][100];
int row, col;

void fill_1(int x, int y)
{
	array[x][y] = 1;
	if (x > 0 && array[x - 1][y] == 0)
		fill_1(x - 1, y);
	if (x < row - 1 && array[x + 1][y] == 0)
		fill_1(x + 1, y);
	if (y > 0 && array[x][y - 1] == 0)
		fill_1(x, y - 1);
	if (y < col - 1 && array[x][y + 1] == 0)
		fill_1(x, y + 1);
}

int main() {
	int i, j;
	int hole = 0;

	scanf("%d", &row);
	scanf("%d", &col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			scanf("%d", &array[i][j]);
	}
	for (i = 0; i < row - 1; i++) {
		for (j = 0; j < col - 1; j++) {
			if (array[i][j] == 0 && array[i][j + 1] == 0 && array[i + 1][j] == 0 && array[i + 1][j + 1] == 0) {
				hole++;
				fill_1(i, j);
			}
		}
	}
	printf("%d", hole);
}