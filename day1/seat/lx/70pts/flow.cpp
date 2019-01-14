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
const int N = 8005, M = N * 405;
const int C = 20;

class CostFlow {
private :
	struct edge {
		int to, c, w, n;
	} e[M];
	int tot, head[N];

	bool inq[N];
	int pa[N], dis[N];

	int S, T, n;

	bool search() {
		static bool inq[N];
		queue<int> Q;
		fill(dis, dis + n, inf);
		Q.push(S);
		dis[S] = 0;
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			inq[u] = false;
			for (int p = head[u]; p; p = e[p].n) {
				if (e[p].c) {
					int to = e[p].to;
					if (dis[to] > dis[u] + e[p].w) {
						pa[to] = p;
						dis[to] = dis[u] + e[p].w;
						if (!inq[to]) {
							inq[to] = true;
							Q.push(to);
						}
					}
				}
			}
		}
		return dis[T] < inf;
	}

	void augment(pii &v) {
		int x, a = inf;
		for (x = T; x != S; x = e[pa[x] ^ 1].to) {
			upmin(a, e[pa[x]].c);
		}
		for (x = T; x != S; x = e[pa[x] ^ 1].to) {
			e[pa[x]].c -= a;
			e[pa[x] ^ 1].c += a;
		}
		v.x += a;
		v.y += dis[T] * a;
	}
public :
	void init(int n) {
		this->n = n;
		tot = 1;
	}
	inline void addEdge(int x, int y, int c, int w) {
		e[++tot] = (edge) {y, c, w, head[x]}, head[x] = tot;
		e[++tot] = (edge) {x, 0, -w, head[y]}, head[y] = tot;
	}
	pii run(int s, int t) {
		S = s, T = t;
		pii ans = mp(0, 0);
		while (search()) {
			augment(ans);
		}
		return ans;
	}
} my;

int n, m, nm;
int sid[301][11], pid[301][11];
int r2l[22][11], l2r[22][11];
int Size, Num;
int tot;

int L[301][11], R[301][11];
pii block[22];

inline int inmod(int x) {
	if (x < 0) x += m;
	if (x >= m) x -= m;
	return x;
}

int main() {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	nm = n * m;
	int S = tot++, T = tot++;
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		sid[i][j] = tot++;
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		pid[i][j] = tot++;
	}
	Size = 15, Num = (n - 1) / Size + 1;
	rep (i, 0, Num - 1) {
		block[i] = mp(i * Size, min((i + 1) * Size, n) - 1);
		rep (j, 0, m - 1) {
			l2r[i][j] = tot++;
			r2l[i][j] = tot++;
		}
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		scanf("%d", &L[i][j]);
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		scanf("%d", &R[i][j]);
	}
	my.init(tot);
	rep (i, 0, Num - 1) {
		rep (k, block[i].x, block[i].y) {
			rep (j, 0, m - 1) {
				my.addEdge(l2r[i][j], pid[k][j], m, 2 * (k - block[i].x));
				my.addEdge(r2l[i][j], pid[k][j], m, 2 * (block[i].y - k));
			}
		}
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		my.addEdge(pid[i][j], pid[i][inmod(j + 1)], nm, 1);
		my.addEdge(pid[i][j], pid[i][inmod(j - 1)], nm, 1);
		my.addEdge(pid[i][j], T, 1, 0);
	}
	rep (i, 0, n - 1) rep (j, 0, m - 1) {
		int x = sid[i][j];
		my.addEdge(S, x, 1, 0);
		rep (k, 0, Num - 1) {
			if (block[k].y <= i) {
				if (L[i][j] <= block[k].x && block[k].y <= R[i][j]) {
					my.addEdge(x, r2l[k][j], 1, 2 * (i - block[k].y));
				} else {
					rep (l, max(block[k].x, L[i][j]), min(block[k].y, R[i][j])) {
						my.addEdge(x, pid[l][j], 1, 2 * (i - l));
					}
				}
			} else if (block[k].x > i) {
				if (L[i][j] <= block[k].x && block[k].y <= R[i][j]) {
					my.addEdge(x, l2r[k][j], 1, 2 * (block[k].x - i));
				} else {
					rep (l, max(block[k].x, L[i][j]), min(block[k].y, R[i][j])) {
						my.addEdge(x, pid[l][j], 1, 2 * (l - i));
					}
				}
			} else {
				rep (l, max(block[k].x, L[i][j]), min(block[k].y, R[i][j])) {
					my.addEdge(x, pid[l][j], 1, 2 * abs(l - i));
				}
			}
		}
	}
	pii ans = my.run(S, T);
	if (ans.x != nm) {
		puts("no solution");
	} else {
		printf("%d\n", ans.y);
	}
	return 0;
}
