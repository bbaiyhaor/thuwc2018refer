#include <cstdio>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <cmath>
#include <algorithm>
#define N 235
#define K 6
#define M 1111111
#define INF 1111111111
using namespace std;
int dis[N][N][1 << K], col[N][N], a[N][N], c[N][N], w[N][N], rand_c[N * N], cc[N][N];
bool inq[N][N][1 << K];
int n, m, min_col, ans, max_cnt;
int queue_x[M], queue_y[M], queue_t[M];

void Spfa(int state) {
	int ch[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int l = 1, r = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	if (dis[i][j][state] != INF) {
		queue_x[++r] = i; queue_y[r] = j; queue_t[r] = state;
		inq[i][j][state] = true;
	}
	while (l <= r) {
		int x = queue_x[l], y = queue_y[l], t = queue_t[l];
		inq[x][y][t] = false;
		for (int i = 0; i < 4; i++) {
			int xx = x + ch[i][0], yy = y + ch[i][1], tt;
			if (!(xx >= 1 && xx <= n && yy >= 1 && yy <= m) || c[xx][yy] == -1) continue;
			tt = t | (1 << (c[xx][yy] - 1)); 
			if (dis[xx][yy][tt] > dis[x][y][t] + w[xx][yy]) {
				dis[xx][yy][tt] = dis[x][y][t] + w[xx][yy];
				if (!inq[xx][yy][tt]) {
					inq[xx][yy][tt] = true;
					queue_x[++r] = xx; 
					queue_y[r] = yy;
					queue_t[r] = tt;
				}
			}
		}
		l++;
	}
	return ;
}

void Steiner() {
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		for (int k = 1; k < 1 << min_col; k++) dis[i][j][k] = INF;
		if (c[i][j] != -1) dis[i][j][1 << (c[i][j] - 1)] = w[i][j];
	}
	for (int i = 1; i < 1 << min_col; i++) {
		for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		if (c[x][y] != -1) {
			if (!(i & (1 << (c[x][y] - 1)))) continue;
			for (int j = (i - 1) & i; j; j = (j - 1) & i) 
				if (dis[x][y][j] != INF && j & (1 << (c[x][y] - 1))) {
					int tmp = dis[x][y][j] + dis[x][y][(i ^ j) | (1 << (c[x][y] - 1))] - w[x][y];
					dis[x][y][i] = min(dis[x][y][i], tmp);
				}
		}
		Spfa(i);
		for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		if (dis[x][y][i] > ans) dis[x][y][i] = INF;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		ans = min(ans, dis[i][j][(1 << min_col) - 1]);
	return ;
}

void Find() {
	ans = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			w[i][j] = 1;
	for (int t = 1; t <= 150; t++) {
		for (int j = 1; j <= n * m; j++) rand_c[j] = rand() % min_col + 1;
		for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++) 
			if (col[x][y] == -1) c[x][y] = -1;
			else c[x][y] = rand_c[col[x][y]];
		Steiner();
	}
	if (ans != INF && ans > max_cnt && (ans < n || n < 10)) {
		max_cnt = ans;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cc[i][j] = col[i][j];
	}
	return ;	
}

void gen1(int nn, int mm, int kk, int max_a, int max_c) {
	n = nn; m = mm; min_col = kk; max_cnt = 0;
	for (int t = 1; t <= 100; t++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				col[i][j] = rand() % 10 ? 1 : -1;
		for (int i = 2; i <= nn * mm / 4; i++) {
			int x = rand() % n + 1, y = rand() % m + 1;
			col[x][y] = rand() % max_c + 1;
		}
		Find();
	}

	for (int i = 1; i <= nn; i++)
	for (int j = 1; j <= mm; j++) 
		a[i][j] = rand() % max_a;
	printf("%d %d %d\n", nn, mm, kk);
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= mm; j++) printf("%d ", cc[i][j]);
		printf("\n");
	}
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= mm; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	return ;
}

void gen2(int nm, int kk, int max_a, int max_c, int block) {
	m = 6 - block; 
	int mm = (m + 1) * block + 1;
	n = nm / mm; 
	max_c = min(max_c, n * mm);
	min_col = kk; max_cnt = 0;
	for (int t = 1; t <= 100; t++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				int col_cnt = max_c / block >= kk ? max_c / block : max_c;
				if (rand() % 10) col[i][j] = rand() % 4 ? 1 : rand() % col_cnt + 1;
				else col[i][j] = -1;
			}
		Find();
	}
	for (int i = 1; i <= block; i++)
	for (int x = 1; x <= n; x++)
	for (int y = 1; y <= m; y++) {
		if (max_c / block >= kk) col[x][(m + 1) * (i - 1) + 1 + y] = cc[x][y] == -1 ? -1 : cc[x][y] + (i - 1) * (max_c / block);
		else col[x][(m + 1) * (i - 1) + 1 + y] = cc[x][y];
	}

	for (int i = 1; i <= block; i++)
	for (int x = 1; x <= n; x++)
		col[x][(m + 1) * (i - 1) + 1] = -1;

	for (int i = 1; i <= n; i++) col[i][0] = kk;
	for (int i = 1; i <= kk - 2; i++) col[(i - 1) * (n / (kk - 2)) + 1][0] = i;
	col[n][0] = kk - 1;
	
	for (int i = 1; i <= n; i++) col[i][0] = max_c - col[i][0] + 1;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= mm; j++) 
		a[i][j] = j == 1 ? rand() % 5 : rand() % max_a;
	printf("%d %d %d\n", n, mm, kk);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < mm; j++) printf("%d ", col[i][j]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mm; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	return ;
}

void MakeData1() {
	char file_name[20];
	sprintf(file_name, "chocolate%d.in", 1);
	freopen(file_name, "w", stdout);
	int test_case = 5;
	printf("%d\n", test_case);
	for (int j = 1; j <= test_case; j++)
		gen1(1, 233, 5, 1000000, 233);
	fclose(stdin);
}

void MakeData2() {
	char file_name[20];
	sprintf(file_name, "chocolate%d.in", 2);
	freopen(file_name, "w", stdout);
	int test_case = 5;
	printf("%d\n", test_case);
	for (int j = 1; j <= test_case; j++)
		gen1(4, 5, 5, 1000000, 20);
	fclose(stdin);
}

void MakeData3() {
	char file_name[20];
	for (int i = 3; i <= 4; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		for (int j = 1; j <= test_case; j++)
			gen1(2, 15, 5, 1000000, 30);
		fclose(stdin);
	}
}

void MakeData4() {
	char file_name[20];
	for (int i = 5; i <= 6; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		for (int j = 1; j <= test_case; j++)
			gen1(5, 6, 5, 1000000, 30);
		fclose(stdin);
	}
}

void MakeData5() {
	char file_name[20];
	for (int i = 7; i <= 9; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		for (int j = 1; j <= test_case; j++)
			gen1(7, 7, 5, 1000000, 8);
		fclose(stdin);
	}
}

void MakeData6() {
	char file_name[20];
	for (int i = 10; i <= 12; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		gen2(233, 5, 1000000, 8, 1);
		gen2(233, 5, 1000000, 8, 2);
		gen2(233, 5, 1000000, 8, 2);
		gen2(233, 5, 1000000, 8, 3);
		gen2(233, 5, 1000000, 8, 3);
		fclose(stdin);
	}
}

void MakeData7() {
	char file_name[20];
	for (int i = 13; i <= 15; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		gen2(233, 5, 1000000, 12, 1);
		gen2(233, 5, 1000000, 12, 2);
		gen2(233, 5, 1000000, 12, 2);
		gen2(233, 5, 1000000, 12, 3);
		gen2(233, 5, 1000000, 12, 3);
		fclose(stdin);
	}
}

void MakeData8() {
	char file_name[20];
	for (int i = 16; i <= 20; i++) {
		sprintf(file_name, "chocolate%d.in", i);
		freopen(file_name, "w", stdout);
		int test_case = 5;
		printf("%d\n", test_case);
		gen2(233, 5, 1000000, 233, 1);
		gen2(233, 5, 1000000, 233, 2);
		gen2(233, 5, 1000000, 233, 2);
		gen2(233, 5, 1000000, 233, 3);
		gen2(233, 5, 1000000, 233, 3);
		fclose(stdin);
	}
}


int main() {
	srand(time(0));
	MakeData1();
	MakeData2();
	MakeData3();
	MakeData4();
	MakeData5();
	MakeData6();
	MakeData7();
	MakeData8();
	return 0;
}