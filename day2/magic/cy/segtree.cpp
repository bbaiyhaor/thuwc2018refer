#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

namespace Solve
{
#define ROOT 1, 1, n
#define LSON root<<1, l, mid
#define RSON root<<1|1, mid+1, r

    const int MAXN = int(2.5*1e5)+10, MOD = 998244353, WIDTH = 4;
    typedef int Matrix[WIDTH][WIDTH];
    typedef int Line[WIDTH];
    typedef long long LL;

    int n;
    Line value[MAXN<<2];
    Matrix lazy[MAXN<<2];
    int lazy_flag[MAXN<<2];
    Matrix eyes;
    Line rst;

    inline void mulM(Matrix A, Matrix B)
    {
        static Matrix C;
        memset(C, 0, sizeof(C));
        for(int i=0;i<WIDTH;i++)
            for(int k=0;k<WIDTH;k++)
                if (A[i][k])
                    for(int j=0;j<WIDTH;j++)
                        C[i][j]=(C[i][j]+LL(A[i][k])*LL(B[k][j]))%MOD;
        memcpy(A, C, sizeof(C));
    }
    inline void mulL(Line A, Matrix B)
    {
        static Line C;
        memset(C, 0, sizeof(C));
        for(int i=0;i<WIDTH;i++)
            for(int k=0;k<WIDTH;k++)
                C[i]=(C[i]+LL(A[k])*LL(B[k][i]))%MOD;
        memcpy(A, C, sizeof(C));
    }
    inline void addL(Line A, Line B)
    {
        for(int i=0;i<WIDTH;i++)
            A[i]=(A[i]+B[i])%MOD;
    }

    void update(int root)
    {
        for(int i=0;i<WIDTH;i++)
            value[root][i]=(value[root<<1][i]+value[root<<1|1][i])%MOD;
    }
    void addlazy(int root, Matrix event)
    {
        mulL(value[root], event);
        if (lazy_flag[root] == 0)
        {
            memcpy(lazy[root], event, sizeof(Matrix));
        } else {
            mulM(lazy[root], event);
        }
        lazy_flag[root] = 1;
    }
    void downlazy(int root)
    {
        if (lazy_flag[root] && memcmp(lazy[root], eyes, sizeof(eyes)) == 0) return;
        addlazy(root<<1, lazy[root]);
        addlazy(root<<1|1, lazy[root]);
        memcpy(lazy[root], eyes, sizeof(eyes));
        lazy_flag[root] = 0;
    }
    void build(int root, int l, int r)
    {
        memcpy(lazy[root], eyes, sizeof(eyes));
        lazy_flag[root] = 0;
        if (l == r)
        {
            scanf("%d%d%d", &value[root][0], &value[root][1], &value[root][2]);
            value[root][3]=1;
            return;
        }
        int mid=(l+r)/2;
        build(LSON); build(RSON);
        update(root);
    }
    void change(int L, int R, Matrix event, int root, int l, int r)
    {
        if (L <= l && r <= R)
        {
            addlazy(root, event);
            return;
        }
        downlazy(root);
        int mid=(l+r)/2;
        if (L <= mid) change(L, R, event, LSON);
        if (R > mid) change(L, R, event, RSON);
        update(root);
    }
    void query(int L, int R, int root, int l, int r)
    {
        if (L <= l && r <= R)
        {
            addL(rst, value[root]);
            return;
        }
        downlazy(root);
        int mid=(l+r)/2;
        if (L <= mid) query(L, R, LSON);
        if (R > mid) query(L, R, RSON);
    }
    void debug(int root, int l, int r)
    {
        if (l == r)
        {
            cout << value[root][0] << " " << value[root][1] << " " << value[root][2] << " " << value[root][3] << endl;
            return;
        }
        downlazy(root);
        int mid=(l+r)/2;
        debug(LSON); debug(RSON);
    }
    void solve()
    {
        memset(eyes, 0, sizeof(eyes));
        for(int i=0;i<WIDTH;i++)
            eyes[i][i]=1;
        
        scanf("%d", &n);
        build(ROOT);

        int m;
        Matrix event;
        scanf("%d", &m);
        while(m--)
        {
            int opt, l, r, v=0;
            scanf("%d%d%d", &opt, &l, &r);
            if (4 <= opt && opt <= 6) scanf("%d", &v);
            memcpy(event, eyes, sizeof(eyes));

            if (opt == 1) {
                event[1][0]=1;
            } else if (opt == 2) {
                event[2][1]=1;
            } else if (opt == 3) {
                event[0][2]=1;
            } else if (opt == 4) {
                event[3][0]=v;
            } else if (opt == 5) {
                event[1][1]=v;
            } else if (opt == 6) {
                event[2][2]=0;
                event[3][2]=v;
            } else if (opt == 7) {
                memset(rst, 0, sizeof(rst));
                query(l, r, ROOT);
                printf("%d %d %d\n", rst[0], rst[1], rst[2]);
            }

            if (opt != 7) change(l, r, event, ROOT);

            // cout << "========= debug ===========" << endl;
            // cout << "cmd : " << opt << " " << l << " " << r << " " << v << endl;
            // debug(ROOT);
            // cout << "========= end ===========" << endl;
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