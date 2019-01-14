#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

namespace Solve
{
    typedef long long LL;
    const int MAXN = 250000 + 10, MOD = 998244353;
    int n;
    int A[MAXN], B[MAXN], C[MAXN];

    void solve()
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", &A[i], &B[i], &C[i]);
        }

        int m=0;
        scanf("%d", &m);
        while(m--)
        {
            int opt, l, r, v;
            scanf("%d%d%d", &opt, &l, &r);
            if (4 <= opt && opt <= 6) scanf("%d", &v);

            if (opt == 1) {
                for(int i=l;i<=r;i++)
                    A[i]=(A[i]+B[i])%MOD;
            } else if (opt == 2) {
                for(int i=l;i<=r;i++)
                    B[i]=(B[i]+C[i])%MOD;
            } else if (opt == 3) {
                for(int i=l;i<=r;i++)
                    C[i]=(C[i]+A[i])%MOD;
            } else if (opt == 4) {
                for(int i=l;i<=r;i++)
                    A[i]=(A[i]+v)%MOD;
            } else if (opt == 5) {
                for(int i=l;i<=r;i++)
                    B[i]=(LL(B[i])*LL(v))%MOD;
            } else if (opt == 6) {
                for(int i=l;i<=r;i++)
                    C[i]=v;
            } else if (opt == 7) {
                int SA = 0, SB = 0, SC = 0;
                for(int i=l;i<=r;i++)
                {
                    SA=(SA+A[i])%MOD;
                    SB=(SB+B[i])%MOD;
                    SC=(SC+C[i])%MOD;
                }
                printf("%d %d %d\n", SA, SB, SC);
            }
        }
    }
}

int main()
{
#ifdef __TEST__
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
#endif

    Solve::solve();

    return 0;
}