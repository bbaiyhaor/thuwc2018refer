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

const int N = 1e7 + 10;
const int mod = 998244353;

inline int inc(int x, int y) {
	return x + y >= mod ? x + y - mod : x + y;
}

int prime[N / 10], pcnt;
int vis[N], Id[N];

void sieve(int n) {
	rep (i, 2, n) {
		if (!vis[i]) {
			prime[++pcnt] = i;
			vis[i] = pcnt;
		}
		rep (j, 1, pcnt) {
			int to = prime[j] * i;
			if (to > n) break ;
			vis[to] = j;
			if (i % prime[j] == 0) break ;
		}
	}
}

typedef bitset<370> Int;

int Lim;

map<int, int> mark;
vector<Int> pool;

Int base[375];

bool Insert(Int now) {
	down (i, 370, 1) {
		if (now[i]) {
			if (base[i][i]) {
				now ^= base[i];
			} else {
				base[i] = now;
				return 1;
			}
		}
	}
	return 0;
}

int Solve(int L, int R) {
	static Int now;
	mark.clear();
	pool.clear();
	rep (i, 1, 370) {
		base[i].reset();
	}
	int ans = L > 1 ? 1 : 2;
	rep (i, max(2, L), R) {
		now.reset();
		int t = i, flag = -1;
		while (t > 1) {
			int id = vis[t], p = prime[id], c = 0;
			while (t % p == 0) {
				t /= p;
				c ^= 1;
			}
			if (c) {
				if (p > Lim) {
					flag = id;
				} else {
					now[id] = 1;
				}
			}
		}
		if (flag != -1) {
			if (mark.count(flag) == 0) {
				mark[flag] = pool.size();
				pool.pb(now);
				continue ;
			} else {
				now ^= pool[mark[flag]];
			}
		}
		if (!Insert(now)) {
			ans = inc(ans, ans);
		}
	}
	return ans;
}

vector<pii> queries;

int main() {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T, l, r;
	int n = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &l, &r);
		queries.pb(mp(l, r));
		upmax(n, r);
	}
	sieve(n);
	Lim = sqrt(n);
	rep (i, 0, queries.size() - 1) {
		printf("%d\n", Solve(queries[i].x, queries[i].y));
	}
	return 0;
}
