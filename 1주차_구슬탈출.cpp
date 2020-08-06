#include<iostream>

using namespace std;

int n, m;
char arr[10][10], tmp[10][10];
int R_row, R_col, B_row, B_col, G_row, G_col;
int R_r, R_c, B_r, B_c;
int mincount = 11;

int lean_up() {

	int next_R_row = R_r;
	int next_B_row = B_r;

	while (1) {
		if (arr[next_R_row][R_c] == '#')
			break;

		next_R_row--;
	}
	next_R_row++;
	while (1) {
		if (arr[next_B_row][B_c] == '#')
			break;

		next_B_row--;
	}
	next_B_row++;

	if (R_c == B_c && next_R_row == next_B_row) {
		if (B_c == G_col && next_B_row <= G_row && G_row < B_r)
			return -1;
		else if (R_c == G_col && B_r < G_row && G_row < R_r)
			return 1;
		else {
			if (R_r > B_r)next_R_row++;
			else next_B_row++;
			R_r = next_R_row;
			B_r = next_B_row;
			return 0;
		}
	}
	else {
		if (B_c == G_col && next_B_row <= G_row && G_row < B_r)
			return -1;
		else if (R_c == G_col && next_R_row <= G_row && G_row < R_r)
			return 1;
		else {
			R_r = next_R_row;
			B_r = next_B_row;
			return 0;
		}
	}
}
int lean_right() {
	int next_R_col = R_c;
	int next_B_col = B_c;

	while (1) {
		if (arr[R_r][next_R_col] == '#')
			break;

		next_R_col++;
	}
	next_R_col--;
	while (1) {
		if (arr[B_r][next_B_col] == '#')
			break;

		next_B_col++;
	}
	next_B_col--;

	if (R_r == B_r && next_R_col == next_B_col) {
		if (B_r == G_row && next_B_col >= G_col && G_col > B_c)
			return -1;
		else if (R_r == G_row && B_c > G_col&& G_col > R_c)
			return 1;
		else {
			if (R_c > B_c)next_B_col--;
			else next_R_col--;
			R_c = next_R_col;
			B_c = next_B_col;
			return 0;
		}
	}
	else {
		if (B_r == G_row && next_B_col >= G_col && G_col > B_c)
			return -1;
		else if (R_r == G_row && next_R_col >= G_col && G_col > R_c)
			return 1;
		else {
			R_c = next_R_col;
			B_c = next_B_col;
			return 0;
		}
	}
}
int lean_down() {
	int next_R_row = R_r;
	int next_B_row = B_r;

	while (1) {
		if (arr[next_R_row][R_c] == '#')
			break;

		next_R_row++;
	}
	next_R_row--;
	while (1) {
		if (arr[next_B_row][B_c] == '#')
			break;

		next_B_row++;
	}
	next_B_row--;

	if (R_c == B_c && next_R_row == next_B_row) {
		if (B_c == G_col && next_B_row >= G_row && G_row > B_r)
			return -1;
		else if (R_c == G_col && B_r > G_row&& G_row > R_r)
			return 1;
		else {
			if (R_r > B_r)next_B_row--;
			else next_R_row--;
			R_r = next_R_row;
			B_r = next_B_row;
			return 0;
		}
	}
	else {
		if (B_c == G_col && next_B_row >= G_row && G_row > B_r)
			return -1;
		else if (R_c == G_col && next_R_row >= G_row && G_row > R_r)
			return 1;
		else {
			R_r = next_R_row;
			B_r = next_B_row;
			return 0;
		}
	}
}
int lean_left() {
	int next_R_col = R_c;
	int next_B_col = B_c;

	while (1) {
		if (arr[R_r][next_R_col] == '#')
			break;

		next_R_col--;
	}
	next_R_col++;
	while (1) {
		if (arr[B_r][next_B_col] == '#')
			break;

		next_B_col--;
	}
	next_B_col++;

	if (R_r == B_r && next_R_col == next_B_col) {
		if (B_r == G_row && next_B_col <= G_col && G_col < B_c) {
			//printf("left\n");
			return -1;
		}
		else if (R_r == G_row && B_c < G_col && G_col < R_c)
			return 1;
		else {
			if (R_c > B_c)next_R_col++;
			else next_B_col++;
			R_c = next_R_col;
			B_c = next_B_col;
			return 0;
		}
	}
	else {
		if (B_r == G_row && next_B_col <= G_col && G_col < B_c)
			return -1;
		else if (R_r == G_row && next_R_col <= G_col && G_col < R_c)
			return 1;
		else {
			R_c = next_R_col;
			B_c = next_B_col;
			return 0;
		}
	}
}

int main()
{
	int check[10];
	char str[20];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'R') {
				R_row = i;
				R_col = j;
			}

			else if (arr[i][j] == 'B') {
				B_row = i;
				B_col = j;
			}
			else if (arr[i][j] == 'O') {
				G_row = i;
				G_col = j;
			}
		}
	}
	for (int i = 0; i < 1048576; i++) {

		//모든 경우의 수 조합
		int digit = 1;
		for (int j = 0; j < 10; j++) {
			check[j] = (i / digit) % 4;
			digit *= 4;
		}

		//초기값 전달
		R_r = R_row;
		R_c = R_col;
		B_r = B_row;
		B_c = B_col;

		//모든 조합에 대해서 이리저리 기울이기
		int flag;
		for (int j = 0; j < 10; j++) {
			if (check[j] == 0) {
				flag = lean_up();
				if (flag == 1 && j + 1 < mincount) {
					mincount = j + 1;
					//printf("up\n");
					break;
				}
				else if (flag == -1)
					break;
			}
			else if (check[j] == 1) {
				flag = lean_right();
				if (flag == 1 && j + 1 < mincount) {
					mincount = j + 1;
					//printf("right\n");
					break;
				}
				else if (flag == -1)
					break;
			}
			else if (check[j] == 2) {
				flag = lean_down();
				if (flag == 1 && j + 1 < mincount) {
					//printf("down\n");
					mincount = j + 1;
					break;
				}
				else if (flag == -1)
					break;
			}
			else {
				flag = lean_left();
				if (flag == 1&& j + 1 < mincount) {
					mincount = j + 1;
					//printf("left\n");
					//printf("%d %d\n", B_r, B_c);
					//printf("%d %d\n", R_r, R_c);
					break;
				}
				else if (flag == -1)
					break;
			}
		}
	}

	if (mincount == 11)
		mincount = -1;
	printf("%d\n", mincount);

	return 0;
}