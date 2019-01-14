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
        memset(dis, 0, sizeof(dis));

        dis[t] = INF;
        queue<int> que;
        que.push(t);
        while(!que.empty())
        {
            int u = que.front(); que.pop();
            used[u] = 0;
            for(int pos = head[u]; pos; pos = next[pos])
            {
                if(c[pos^1] && dis[to[pos]]<dis[u]-w[pos^1])
                {
                    dis[to[pos]] = dis[u]-w[pos^1];
                    if (!used[to[pos]])
                    {
                        used[to[pos]] = 1;
                        que.push(to[pos]);
                    }
                }
            }
        }

        memcpy(head2, head, sizeof(head));
        return dis[s] > 0;
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
            if(c[pos] && !used[to[pos]] && dis[to[pos]] == dis[u] + w[pos])
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
    const int MAXN = 300 + 10, LOGN = 10;
    const int MAXM = 10 + 1;
    const int INF = 0x7fffffff/4;

    MaxFlowMinCost<int, INF, MAXN*MAXM*6, MAXN*MAXM*4+MAXN*MAXM*LOGN*2+MAXN*MAXM*6> flow;
    int n, m;
    int L[MAXN][MAXM], R[MAXN][MAXM];
    int L2RIndex[MAXN][MAXN][MAXM], R2LIndex[MAXN][MAXN][MAXM], cnt;

    inline int DOWN(int x, int y)
    {
        return cnt+x*m+y;
    }
    inline int TOP(int x, int y)
    {
        return n*m+DOWN(x,y);
    }
    void buildSegIndex(int l, int r)
    {
        for(int c=0;c<m;c++)
        {
            L2RIndex[l][r][c] = cnt++;
            R2LIndex[l][r][c] = cnt++;
        }
        if (l == r) return;
        int mid = (l+r)/2;
        buildSegIndex(l, mid); buildSegIndex(mid+1, r);
    }
    void buildSegFlow(int *fL2R, int *fR2L, int l, int r)
    {
        if (fL2R) {
            for(int c=0;c<m;c++)
                flow.build(fL2R[c], L2RIndex[l][r][c], INF, 0);
        }
        if (fR2L) {
            for(int c=0;c<m;c++)
                flow.build(fR2L[c], R2LIndex[l][r][c], INF, 0);
        }
        if (l == r) {
            for(int c=0;c<m;c++) {
                flow.build(L2RIndex[l][r][c], TOP(l, c), INF, l*2);
            }
            for(int c=0;c<m;c++) {
                flow.build(R2LIndex[l][r][c], TOP(l, c), INF, (n-l-1)*2);
            }
            return;
        }
        int mid = (l+r)/2;
        buildSegFlow(L2RIndex[l][r], R2LIndex[l][r], l, mid);
        buildSegFlow(L2RIndex[l][r], R2LIndex[l][r], mid+1, r);
    }
    enum EdgeType { L2R = 0, R2L = 1 };
    void buildEdge(int snode, int sw, int L, int R, int l, int r, int c, EdgeType type)
    {
        if (L <= l && r <= R) {
            if (type == L2R) {
                flow.build(snode, L2RIndex[l][r][c], 1, sw);
            } else {
                flow.build(snode, R2LIndex[l][r][c], 1, sw);
            }
            return;
        }
        int mid = (l+r)/2;
        if (L <= mid) buildEdge(snode, sw, L, R, l, mid, c, type);
        if (R > mid) buildEdge(snode, sw, L, R, mid+1, r, c, type);
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
        
        cnt = 0;
        buildSegIndex(0, n-1);
        
        const int S = TOP(n-1, m-1)+1;
        const int T = S + 1;
        flow.init(S, T, T);

        buildSegFlow(NULL, NULL, 0, n-1);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                flow.build(S, DOWN(i,j), 1, 0);
                flow.build(TOP(i,j), T, 1, 0);
                flow.build(TOP(i,j), TOP(i, (j+1)%m), INF, 1);
                flow.build(TOP(i,j), TOP(i, (j-1+m)%m), INF, 1);

                if (R[i][j] <= i)
                {
                    buildEdge(DOWN(i, j), -(n-i-1)*2, L[i][j], R[i][j], 0, n-1, j, R2L);
                } else if (L[i][j] >= i) {
                    buildEdge(DOWN(i, j), -i*2, L[i][j], R[i][j], 0, n-1, j, L2R);
                } else {
                    buildEdge(DOWN(i, j), -(n-i-1)*2, L[i][j], i, 0, n-1, j, R2L);
                    buildEdge(DOWN(i, j), -i*2, i, R[i][j], 0, n-1, j, L2R);
                }
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