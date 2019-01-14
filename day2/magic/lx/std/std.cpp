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
const int N = 524299;

inline void upd(int &x, int y) {
	(x += y) >= mod ? x -= mod : 0;
}
inline int inc(int x, int y) {
	return x + y >= mod ? x + y - mod : x + y;
}

struct matrix {
	int e[3][4];
	inline matrix operator * (const matrix &b) const {
		static matrix res;
		rep (i, 0, 2) rep (j, 0, 3) {
			LL tmp = j == 3 ? e[i][j] : 0;
			rep (k, 0, 2) {
				tmp += (LL) e[i][k] * b.e[k][j];
			}
			res.e[i][j] = tmp % mod;
		}
		return res;
	}
};

struct Vector {
	int e[4];
};

inline Vector operator + (const Vector &a, const Vector &b) {
	static Vector res;
	rep (i, 0, 3) {
		res.e[i] = inc(a.e[i], b.e[i]);
	}
	return res;
}
inline Vector operator * (const matrix &a, const Vector &b) {
	static Vector res;
	rep (i, 0, 2) {
		LL tmp = 0;
		rep (j, 0, 3) {
			tmp += (LL) a.e[i][j] * b.e[j];
		}
		res.e[i] = tmp % mod;
	}
	res.e[3] = b.e[3];
	return res;
}

matrix a2b, b2c, c2a;
matrix aPlus, bMul, cCover;

void init_matrix() {
	rep (i, 0, 2) {
		a2b.e[i][i] = 1;
		b2c.e[i][i] = 1;
		c2a.e[i][i] = 1;
		aPlus.e[i][i] = 1;
		bMul.e[i][i] = 1;
		cCover.e[i][i] = 1;
	}
	a2b.e[0][1] = 1;
	b2c.e[1][2] = 1;
	c2a.e[2][0] = 1;
	cCover.e[2][2] = 0;
}

class SegmentTree {
private :
#define ls (o << 1)
#define rs (o << 1 | 1)
	matrix lazy[N];
	Vector val[N];
	bool flag[N];
	int n;

	void Add(int o, const matrix &opt) {
		val[o] = opt * val[o];
		if (!flag[o]) {
			lazy[o] = opt;
			flag[o] = 1;
		} else {
			lazy[o] = opt * lazy[o];
		}
	}
	void push_down(int o) {
		if (flag[o]) {
			Add(ls, lazy[o]);
			Add(rs, lazy[o]);
			flag[o] = 0;
		}
	}
	void build(int o, int l, int r) {
		if (l == r) {
			scanf("%d%d%d", &val[o].e[0], &val[o].e[1], &val[o].e[2]);
			val[o].e[3] = 1;
			return ;
		}
		int mid = (l + r) / 2;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		val[o] = val[ls] + val[rs];
	}

	int L, R;

	void modify(int o, int l, int r, const matrix &opt) {
		if (L <= l && r <= R) {
			Add(o, opt);
			return ;
		}
		push_down(o);
		int mid = (l + r) / 2;
		if (L <= mid) modify(ls, l, mid, opt);
		if (mid < R) modify(rs, mid + 1, r, opt);
		val[o] = val[ls] + val[rs];
	}
	Vector query(int o, int l, int r) {
		if (L <= l && r <= R) {
			return val[o];
		}
		push_down(o);
		int mid = (l + r) / 2;
		if (mid >= R) {
			return query(ls, l, mid);
		} else if (mid < L) {
			return query(rs, mid + 1, r);
		} else {
			return query(ls, l, mid) + query(rs, mid + 1, r);
		}
	}
#undef ls
#undef rs
public :
	void init() {
		scanf("%d", &n);
		build(1, 1, n);
	}
	void modify(int l, int r, const matrix &opt) {
		L = l, R = r;
		modify(1, 1, n, opt);
	}
	Vector query(int l, int r) {
		L = l, R = r;
		return query(1, 1, n);
	}
} my;

int main() {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	init_matrix();
	my.init();
	int Q;
	scanf("%d", &Q);
	int opt, l, r;
	Vector ans;
	while (Q--) {
		scanf("%d%d%d", &opt, &l, &r);
		switch (opt) {
			case 1 : 
				my.modify(l, r, a2b);
				break ;
			case 2 :
				my.modify(l, r, b2c);
				break ;
			case 3 : 
				my.modify(l, r, c2a);
				break ;
			case 4 : 
				scanf("%d", &aPlus.e[0][3]);
				my.modify(l, r, aPlus);
				break ;
			case 5 : 
				scanf("%d", &bMul.e[1][1]);
				my.modify(l, r, bMul);
				break ;
			case 6 : 
				scanf("%d", &cCover.e[2][3]);
				my.modify(l, r, cCover);
				break ;
			case 7 : 
				ans = my.query(l, r);
				printf("%d %d %d\n", ans.e[0], ans.e[1], ans.e[2]);
				break ;
		}
	}
	return 0;
}
