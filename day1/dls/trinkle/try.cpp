#include <bits/stdc++.h>
typedef std::bitset<500> array;
const int p = 998244353;
const int N = 10000010;//664579
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
int solve(int L, int R)
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
/*    int ans=0;
    for (int i = 2; i <= R; ++i)
        if(factor[i]==i)
            ans++;
    if(ans==tot+tot2)return 0;
    int ans2=0;
    for (int i = std::min(2,L); i <= R; ++i)
        if(factor[i]==i)
            ans2++;
    if(ans2==tot+tot2)return 0;
    return R - L + 1 - tot - tot2;*/
    int ans=0;
    for (int i = 2; i <= R; ++i)
        if(factor[i]==i && (L - 1) / i < R / i)
            ans++;
    if(R-L+1-tot-tot2==std::min(R-L+1,std::max(0,R - L + 1 - ans)))return 0;
    return R - L + 1 - tot - tot2;
}
int T, L[1100000], R[1100000];
int main(int argc, char const *argv[])
{
//	scanf("%d", &T);
	T=1000000;n=atoi(argv[1]);srand(time(0));
    for (int i = 1; i <= T; ++i)
    {
        L[i]=rand()%n+1,R[i]=std::min(n,rand()%5000+L[i]);
/*    	L[i]=rand()%n+1,R[i]=rand()%n+1;
    	if(L[i]>R[i])std::swap(L[i],R[i]);
    	if(L[i]==1)L[i]++;
        if (n < R[i])n = R[i];
*/    }
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
        //		printf("%d: %d\n", i, factor[i]);
    }
    int max_range=0;
    for (int i = 1; i <= T; ++i)
    {
    	int tmp=solve(L[i], R[i]);
    	if(tmp>500)
        {
            max_range=std::max(max_range,R[i]-L[i]);
            printf("%d %d\n",L[i],R[i]);
//        	printf("%2d %7d %d %d\n",tmp,(R[i]-L[i]),L[i],R[i]);
        }
    }
    return 0;
}
