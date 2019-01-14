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

const int mod = 998244353;
const int N = 250005;

inline int inc(int x, int y) {
	return x + y >= mod ? x + y - mod : x + y;
}
inline void upd(int &x, int y) {
	(x += y) >= mod ? x -= mod : 0;
}

int a[N], b[N], c[N];
int n, m;

int main() {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	scanf("%d", &m);
	int opt, l, r, x;
	int sa, sb, sc;
	rep (i, 1, m) {
		scanf("%d%d%d", &opt, &l, &r);
		switch (opt) {
			case 1 : 
				rep (i, l, r) upd(a[i], b[i]);
				break ;
			case 2 :
				rep (i, l, r) upd(b[i], c[i]);
				break ;
			case 3 : 
				rep (i, l, r) upd(c[i], a[i]);
				break ;
			case 4 : 
				scanf("%d", &x);
				rep (i, l, r) upd(a[i], x);
				break ;
			case 5 : 
				scanf("%d", &x);
				rep (i, l, r) b[i] = (LL) b[i] * x % mod;
				break ;
			case 6 : 
				scanf("%d", &x);
				rep (i, l, r) c[i] = x;
				break ;
			case 7 : 
				sa = sb = sc = 0;
				rep (i, l, r) {
					upd(sa, a[i]);
					upd(sb, b[i]);
					upd(sc, c[i]);
				}
				printf("%d %d %d\n", sa, sb, sc);
				break ;
		}
	}
	return 0;
}
