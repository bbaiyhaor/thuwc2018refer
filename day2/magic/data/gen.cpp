#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define bin(x) (1<<(x))
#define LX_JUDGE

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

template<typename T> inline void upmax(T &x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T &x, T y) { x > y ? x = y : 0; }

template<typename T>
inline void read(T &x) {
	char c;
	while ((c = getchar()) < '0' || c > '9');
	for (x = c - '0'; (c = getchar()) >= '0' && c <= '9'; x = x * 10 + c - '0');
}

const int mod = 998244353;
const int N = 250005;

int n, m, B;

pii myLR() {
	if (rand() % 8) {
		int l = rand() % B + 1, r = n - rand() % B;
		return mp(l, r);
	} else {
		int l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) swap(l, r);
		return mp(l, r);
	}
}

int main() {
	//freopen("2.in", "w", stdout);
	srand((int) time(0));
	/*
	n = 239797;
	B = 50000;
	printf("%d\n", n);
	rep (i, 1, n) {
		int a = rand() % mod, b = rand() % mod, c = rand() % mod;
		printf("%d %d %d\n", a, b, c);
	}
	m = 248213;
	printf("%d\n", m);
	int half = 200223;
	rep (i, 1, half) {
		int opt = rand() % 6 + 1;
		if (opt < 4) {
			printf("%d %d %d\n", opt, 1, n);
		} else {
			printf("%d %d %d %d\n", opt, 1, n, rand() % mod);
		}
	}
	rep (i, half + 1, m) {
		pii v = myLR();
		printf("%d %d %d\n", 7, v.x, v.y);
	}
	*/
	n = 100000, m = 100000;
	B = 22333;
	printf("%d\n", n);
	rep (i, 1, n) {
		int a = rand() % mod, b = rand() % mod, c = rand() % mod;
		printf("%d %d %d\n", a, b, c);
	}
	printf("%d\n", m);
	rep (i, 1, m) {
		int opt = rand() % 10;
		if (opt < 2) {
			pii v = myLR();
			printf("7 %d %d\n", v.x, v.y);
		} else {
			pii v = myLR();
			if (opt < 6) {
				int r = rand() % 3;
				printf("%d %d %d\n", 1 + r, v.x, v.y);
			} else {
				int r = rand() % 3, x = rand() % mod;
				printf("%d %d %d %d\n", 4 + r, v.x, v.y, x);
			}
		}
	}
	return 0;
}
/*
   99999, 99998
   99989, 99918
   100000, 100000
   */
