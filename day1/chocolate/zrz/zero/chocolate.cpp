#include <cstdio>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <algorithm>
#define N 235
#define K 6
#define M 1111111
#define INF 1111111111
using namespace std;
int dis[N][N][1 << K], col[N][N], a[N][N], c[N][N], w[N][N], rand_c[N * N];
bool inq[N][N][1 << K];
int n, m, min_col, ans;
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
		if (dis[x][y][i] > ans) 
			dis[x][y][i] = INF;
		else 
			for (int j = (i - 1) & i; j; j = (j - 1) & i)
				dis[x][y][j] = min(dis[x][y][j], dis[x][y][i]);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		ans = min(ans, dis[i][j][(1 << min_col) - 1]);
	return ;
}

void solve() {
	int sorted_a[N * N];
	int cnt = 0;
	scanf("%d%d%d", &n, &m, &min_col);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		scanf("%d", &col[i][j]);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		scanf("%d", &a[i][j]);
		sorted_a[++cnt] = a[i][j];
	}
	sort(&sorted_a[1], &sorted_a[cnt + 1]);
	int l = 1, r = cnt, min_cnt = INF, min_med = INF;
	while (l <= r) {
		ans = INF;
		int mid = (l + r) >> 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				w[i][j] = a[i][j] > sorted_a[mid] ? 1000 + 1 : 1000 - 1;
		for (int t = 1; t <= 200; t++) {
			for (int j = 1; j <= n * m; j++) rand_c[j] = rand() % min_col + 1;
			for (int x = 1; x <= n; x++) 
			for (int y = 1; y <= m; y++) {
				if (col[x][y] == -1) c[x][y] = -1;
				else c[x][y] = rand_c[col[x][y]];
			}
			//printf("%d\n", ans);
			Steiner();
		}
		if (ans == INF) {
			printf("-1 -1\n");
			return ;
		}
		min_cnt = (ans + 500) / 1000;
		if (ans <= min_cnt * 1000) {
			min_med = sorted_a[mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d %d\n",min_cnt+rand()&1, min_med);
	return ;
}

int main(int argc, char *argv[]) {
	/*char input_file[20], output_file[20];
	sprintf(input_file, "chocolate%d.in", atoi(argv[1]));
	sprintf(output_file, "chocolate%d.out", atoi(argv[1]));
	freopen(input_file, "r", stdin);
	freopen(output_file, "w", stdout);*/ 
	srand(time(0));
	int test_case;
	scanf("%d", &test_case);
	for (int i = 1; i <= test_case; i++) solve();
	return 0;
}