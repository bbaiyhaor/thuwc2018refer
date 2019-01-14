#include <bits/stdc++.h>
#define N 235
#define K 6
#define M 1111111
#define INF 0x3f3f3f3f
using namespace std;
int dis[N][N][1 << K], col[N][N], a[N][N], c[N][N], w[N][N], randomcolor[N * N];
bool inq[N][N][1 << K];
int n, m, colors, ans;
queue<int> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void Spfa(int state) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dis[i][j][state] != INF) {
				q.push(i);
				q.push(j);
				q.push(state);
				inq[i][j][state] = true;
			}
		}
	}

	while (q.size()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int t = q.front();
		q.pop();
		inq[x][y][t] = false;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			int tt;
			if (!in(xx, yy) || c[xx][yy] == -1) {
				continue;
			}
			tt = t | (1 << c[xx][yy]); 
			if (dis[xx][yy][tt] > dis[x][y][t] + w[xx][yy]) {
				dis[xx][yy][tt] = dis[x][y][t] + w[xx][yy];
				if (!inq[xx][yy][tt]) {
					inq[xx][yy][tt] = true;
					q.push(xx);
					q.push(yy);
					q.push(tt);
				}
			}
		}
	}
	return;
}

void Steiner() {
	memset(dis, 0, sizeof dis);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k < 1 << colors; k++) {
				dis[i][j][k] = INF;
			}
			if (c[i][j] != -1) {
				dis[i][j][1 << c[i][j]] = w[i][j];
			}
		}
	}

	for (int i = 1; i < 1 << colors; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				if (c[x][y] != -1) {
					if (~i >> c[x][y] & 1) {
						continue;
					}
					for (int j = i; j; j = (j - 1) & i) {
						if (dis[x][y][j] != INF && j & (1 << c[x][y])) {
							int tmp = dis[x][y][j] + dis[x][y][(i ^ j) | (1 << c[x][y])] - w[x][y];
							dis[x][y][i] = min(dis[x][y][i], tmp);
						}
					}
				}
			}
		}
		Spfa(i);
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				if (dis[x][y][i] > ans) {
					dis[x][y][i] = INF;
				} else {
					for (int j = i; j; j = (j - 1) & i) {
						dis[x][y][j] = min(dis[x][y][j], dis[x][y][i]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min(ans, dis[i][j][(1 << colors) - 1]);
		}
	}
	return;
}

int lisan[1000], lc;
void solve() {
	lc = 0;
	scanf("%d%d%d", &n, &m, &colors);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &col[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			lisan[lc++] = a[i][j];
		}
	}
	sort(lisan, lisan + lc);
	int l = -1;
	int r = lc;
	int min_cnt = -1;
	int min_med = -1;
	while (l < r - 1) {
		ans = INF;
		int mid = (l + r) >> 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				w[i][j] = a[i][j] > lisan[mid] ? 1001 : 999;
			}
		}
		for (int t = 1; t <= 200; t++) {
			for (int j = 1; j <= n * m; j++) {
				randomcolor[j] = rand() % colors;
			}
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					if (col[x][y] == -1) {
						c[x][y] = -1;
					} else {
						c[x][y] = randomcolor[col[x][y]];
					}
				}
			}
			Steiner();
		}
		if (ans == INF) {
			printf("-1 -1\n");
			return ;
		}
		if (ans <= (ans + 500) / 1000 * 1000) {
			r = mid;
			min_cnt = (ans + 500) / 1000;
		} else {
			l = mid;
		}
	}
	printf("%d %d\n", min_cnt, lisan[r]);
	return ;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		solve();
	}
}
