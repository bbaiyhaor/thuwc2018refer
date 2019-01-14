#include "testlib.h"
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

const int M = 6000000;

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 10); inf.readEoln();
	while (T--) {
		inf.readInt(1, M); inf.readSpace();
		inf.readInt(1, M); inf.readEoln();
	}
	inf.readEof();
	return 0;
}
