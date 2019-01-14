#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <assert.h>

using namespace std;

template<typename T, T INF, int MAXN, int MAXM>
struct MaxFlowMinCost
{
    int s, t, n;
    int head[MAXN], head2[MAXN], next[MAXM*2], to[MAXM*2], c[MAXM*2], op;
    T w[MAXM*2];
    T dis[MAXN];
    int used[MAXN], way[MAXN], stop;
    T ans;
    int maxflow;

    void init(int s, int t, int n)
    {
        this->s = s;
        this->t = t;
        this->n = n;
        memset(head, 0, sizeof(head));
        op = 1;
        stop = 0;
    }
    void build(int u, int v, int c, T w)
    {
        next[++op] = head[u]; head[u] = op; to[op] = v; this->w[op] = w; this->c[op] = c;
        next[++op] = head[v]; head[v] = op; to[op] = u; this->w[op] = -w; this->c[op] = 0;
        assert(op < MAXM*2);
    }
    bool spfa()
    {
        memset(used, 0, sizeof(used));
        for(int i = 0; i <= n; i ++)
        {
            dis[i] = INF;
        }
        dis[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty())
        {
            int u = que.front(); que.pop();
            used[u] = 0;
            for(int pos = head[u]; pos; pos = next[pos])
                if(c[pos] && dis[to[pos]]>dis[u]+w[pos])
                {
                    dis[to[pos]] = dis[u]+w[pos];
                    if (!used[to[pos]])
                    {
                        used[to[pos]] = 1;
                        que.push(to[pos]);
                    }
                }
        }
        memcpy(head2, head, sizeof(head));
        return dis[t] < INF;
    }
    bool dfs(int u, int top)
    {
        if (u == t)
        {
            int minflow = 0x7fffffff/2;
            for(int i = top-1; i >= 1; i --)
                if (minflow >= c[way[i]])
                {
                    stop = i;
                    minflow = c[way[i]];
                }
            maxflow += minflow;
            for(int i = 1; i < top; i ++)
            {
                ans += minflow*w[way[i]];
                c[way[i]] -= minflow;
                c[way[i]^1] += minflow;
            }
            return true;
        }
        used[u] = 1;
        for(int&pos = head2[u]; pos; pos = next[pos])
            if(c[pos] && dis[to[pos]] == dis[u] + w[pos] && !used[to[pos]])
            {
                way[top] = pos;
                if (dfs(to[pos], top+1) && top != stop)
                {
                    used[u] = 0;
                    return true;
                }
            }
        used[u] = 0;
        return false;
    }
    T solve()
    {
        ans = 0;
        maxflow = 0;
        while(spfa())
        {
            memset(used, 0, sizeof(used));
            dfs(s, 1);
        }
        return ans;
    }
};

namespace Solve
{
    const int MAXN = 300 + 10;
    const int MAXM = 10 + 1;
    const int INF = 0x7fffffff/4;

    MaxFlowMinCost<int, INF, MAXN*MAXM*2, MAXN*MAXM*4+MAXN*MAXN*MAXM> flow;
    int n, m;
    int L[MAXN][MAXM], R[MAXN][MAXM];

    inline int LEFT(int x, int y)
    {
        return x*m+y;
    }
    inline int RIGHT(int x, int y)
    {
        return n*m+LEFT(x, y);
    }
    void solve()
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d", &L[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d", &R[i][j]);
        
        const int S = RIGHT(n-1,m-1)+1;
        const int T = S + 1;
        flow.init(S, T, T);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                flow.build(S, LEFT(i,j), 1, 0);
                flow.build(RIGHT(i,j), T, 1, 0);
                flow.build(RIGHT(i,j), RIGHT(i, (j+1)%m), INF, 1);
                flow.build(RIGHT(i,j), RIGHT(i, (j-1+m)%m), INF, 1);

                for(int x=L[i][j];x<=R[i][j];x++)
                    flow.build(LEFT(i,j), RIGHT(x, j), 1, abs(x-i)*2);
            }
        
        int ans = flow.solve();
        if (flow.maxflow != n*m)
            puts("no solution");
        else printf("%d\n", ans);
    }
}

int main()
{
#ifdef __TEST__
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
#endif

    Solve::solve();

    return 0;
}