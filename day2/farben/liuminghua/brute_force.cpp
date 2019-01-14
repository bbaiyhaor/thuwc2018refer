#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int f[1111][120000], ans[1111];
int main() {
	int n = 1000, m = 4;
	int total_state = 1;
	for (int i = 1; i < m; i++) total_state *= m;
	for (int t = 0; t < total_state; t++) {
		memset(f, 0, sizeof(f));
		f[m - 1][t] = 1;
		for (int i = m - 1; i < n; i++) 
			for (int j = 0; j < total_state; j++)
				if (f[i][j]) {
					bool c[10];
					int tmp = j;
					bool flag = true;
					for (int k = 0; k < m; k++) c[k] = false;
					for (int k = 1; k < m; k++) {
						if (c[tmp % m]) flag = false;
						c[tmp % m] = true;
						tmp /= m;
					}
					for (int k = 0; k < m; k++) {
						int new_j = j / m + (total_state / m) * k; 
						if (c[k] || flag == false) 
							f[i + 1][new_j] = (f[i + 1][new_j] + f[i][j]) % MOD;
					}
				}
		int col[20];
		int tmp = t;
		for (int i = 1; i < m; i++) {
			col[i + m - 1] = tmp % m;
			tmp /= m;
		}
		for (int i = 0; i < total_state; i++) {
			int tmp = i;
			for (int j = 1; j < m; j++) {
				col[j] = tmp % m;
				tmp /= m;
			}
			bool flag = true;
			for (int j = 1; j < m; j++) {
				bool in[10];
				bool f = true;
				for (int k = 0; k < m; k++) in[k] = false;
				for (int k = 0; k < m; k++) {
					if (in[col[j + k]]) f = false;
					in[col[j + k]] = true;
				}
				if (f) flag = false;
			}
			if (flag) 
				for (int j = m; j <= n; j++)
					ans[j] = (ans[j] + f[j][i]) % MOD;
		}
	}
	for (int i = m; i <= n; i++)
		printf("%d %d\n", i, ans[i]);
	return 0;
}