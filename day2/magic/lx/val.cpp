#include "testlib.h"
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

const int N = 250000;
const int M = 998244353;

int main(int argc, char *argv[]) {
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	registerValidation(argc, argv);
	int n = inf.readInt(1, 250000); inf.readEoln();
	rep (i, 1, n) {
		inf.readInt(0, M - 1); inf.readSpace();
		inf.readInt(0, M - 1); inf.readSpace();
		inf.readInt(0, M - 1); inf.readEoln();
	}
	int m = inf.readInt(1, 250000); inf.readEoln();
	rep (i, 1, m) {
		int opt = inf.readInt(1, 7); inf.readSpace();
		int l = inf.readInt(1, n); inf.readSpace();
		int r = inf.readInt(1, n); 
		ensure(l <= r);
		if (4 <= opt && opt <= 6) {
			inf.readSpace();
			inf.readInt(0, M - 1);
		}
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
