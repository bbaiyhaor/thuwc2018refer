#include <bits/stdc++.h>
typedef std::bitset<500> array;
const int p = 998244353;
const int N = 10000010;
int pt, primeid[N], n, k, size, prime[N], factor[N];
char vis[N];
array a[500], now, pre;
int power2(int k)
{
    int t = 2, f = 1;
    for (; k; k >>= 1, t = 1ll * t * t % p)
        if (k & 1)
            f = 1ll * f * t % p;
    return f;
}
struct D
{
    int x, y;
    friend bool operator<(const D &a, const D &b)
    {
        return a.y < b.y;
    }
} max_fac[N];
int getfac(int i, array &now)
{
    int flag = 0;
    now.reset();
    while (factor[i] > k)
        i /= factor[i];
    for (int j, cnt, tmp; i > 1; i = tmp)
    {
        j = factor[i], tmp = i, cnt = 0;
        while (tmp % j == 0)tmp /= j, cnt++;
        if (cnt & 1)
        {
            now[primeid[j]] = 1;
            flag = 1;
        }
    }
    return flag;
}
int add(array &now)
{
    for (int i = 0; i < size; ++i)
        if (now[i])
            if (a[i][i])
                now ^= a[i];
            else
            {
                a[i] = now;
                return 1;
            }
    return 0;
}
void solve(int L, int R)
{
    //TODO: L==1
    int cnt = 0, tot = 0, tot2 = 0;
    for (int i = std::max(2, L); i <= R; ++i)
        max_fac[++cnt] = (D)
    {
        i, factor[i]
    };
    std::sort(max_fac + 1, max_fac + 1 + cnt);
    for (int i = 0; i < size; ++i)a[i].reset();
    for (int i = 1; i <= cnt; ++i)
        if (max_fac[i].y <= k)
        {
            if (tot < size)
                if (getfac(max_fac[i].x, now))
                    tot += add(now);
        }
        else if (max_fac[i].y != max_fac[i - 1].y)
        {
            tot2++;
            if (tot < size)
                getfac(max_fac[i].x, pre);
        }
        else
        {
            if (tot < size)
            {
                getfac(max_fac[i].x, now);
                now ^= pre;
                tot += add(now);
            }
        }
    printf("%d\n", power2(R - L + 1 - tot - tot2));
}
void solve2(int L,int R)
{
    int ans=0;
    for (int i = 2; i <= R; ++i)
        if(factor[i]==i && (L - 1) / i < R / i)
            ans++;
    printf("%d\n",power2(R - L + 1 - ans));
}
int T, L[110], R[110];
int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d%d", &L[i], &R[i]);
        if (n < R[i])n = R[i];
    }
    k = sqrt(n) + 1;
    factor[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[pt] = i;
            primeid[i] = pt++;
            factor[i] = i;
            if (i <= k)size++;
        }
        for (int j = 0; j < pt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            factor[i * prime[j]] = std::max(factor[i], prime[j]);
            if (i % prime[j] == 0)break;
        }
        //      printf("%d: %d\n", i, factor[i]);
    }
    for (int i = 1; i <= T; ++i)
        if(R[i] - L[i] < 6000)
            solve(L[i], R[i]);
        else
            solve2(L[i],R[i]);
    return 0;
}