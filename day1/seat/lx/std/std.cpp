#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define bin(x) (1<<(x))
//#define LX_JUDGE

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

template<typename T> inline void upmax(T &x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T &x, T y) { x > y ? x = y : 0; }

const int inf = 0x3f3f3f3f;
const int N = 3005;

class Edmonds {
private :
	int w[N][N];
	int lx[N], ly[N], mat[N];
	int pre[N], slack[N];
	bool vy[N];
	int n;

	bool augment(int root) {
		fill(vy + 1, vy + n + 1, 0);
		fill(slack + 1, slack + n + 1, inf);
		int py = 0;
		mat[py] = root;
		do {
			vy[py] = true;
			int x = mat[py], det = inf, yy = -1;
			rep (y, 1, n) if (!vy[y]) {
				int tmp = w[x][y] > -inf ? lx[x] + ly[y] - w[x][y] : inf;
				if (tmp < slack[y]) {
					slack[y] = tmp;
					pre[y] = py;
				}
				if (slack[y] < det) {
					det = slack[y];
					yy = y;
				}
			}
			if (det > 0) {
				rep (y, 0, n) {
					if (vy[y]) {
						lx[mat[y]] -= det;
						ly[y] += det;
					} else {
						slack[y] -= det;
					}
				}
			}
			if (yy == -1) return false;
			py = yy;
		} while (mat[py] != -1);
		do {
			mat[py] = mat[pre[py]];
			py = pre[py];
		} while (py);
		return true;
	}
public :
	void init(int n) {
		this->n = n;
		rep (i, 1, n) rep (j, 1, n) {
			w[i][j] = -inf;
		}
	}
	void addEdge(int x, int y, int v) {
		w[x][y] = -v;
	}
	int run() {
		fill(ly + 1, ly + n + 1, 0);
		fill(mat + 1, mat + n + 1, -1);
		rep (i, 1, n) {
			lx[i] = -inf;
			rep (j, 1, n) {
				upmax(lx[i], w[i][j]);
			}
		}
		rep (i, 1, n) {
			if (!augment(i)) {
				return -1;
			}
		}
		int ans = 0;
		rep (i, 1, n) {
			ans += lx[i] + ly[i];
		}
		return -ans;
	}
} my;

inline int inmod(int x, int m) {
	if (x < 0) x += m;
	if (x >= m) x -= m;
	return x;
}

int n, m;
int id[305][11], tot;
int L[305][11], R[305][11];

int main() {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		id[i][j] = ++tot;
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		scanf("%d", &L[i][j]);
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		scanf("%d", &R[i][j]);
	}
	my.init(tot);
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		int x = id[i][j];
		rep (v, L[i][j], R[i][j]) {
			rep (k, 0, m - 1) {
				my.addEdge(x, id[v][k], abs(v - i) * 2 + min(inmod(j - k, m), inmod(k - j, m)));
			}
		}
	}
	int ans = my.run();
	if (ans < 0) {
		puts("no solution");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
