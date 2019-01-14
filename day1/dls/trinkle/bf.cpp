#include <bits/stdc++.h>
int ans,l,r,state[1100],t[1100];
std::vector<int>factor[1100];
struct P{int x,y;}max_fac[1100];
bool operator<(const P&a,const P&b){return a.y>b.y;}
void add(int x,int t)
{
	for(int i=0;i<factor[x].size();++i)
		if(factor[x][i]!=1)
		{
			for(int tmp=x;tmp%factor[x][i]==0;tmp/=factor[x][i])
				state[factor[x][i]]+=t;
		}
}
void dfs(int x)
{
//	if(max_fac[x].y!=max_fac[x-1].y&&state[max_fac[x-1].y]&1)return;
	if(x==r+1)
	{
		int flag=1;
		for(int i=2;i<=r&&flag;++i)
			if(state[i]&1)
				flag=0;
		if(flag)
		{
			ans++;
//			for(int i=l;i<=r;++i)
//				if(t[i])printf("%d ",i);
//			puts("");
		}
		return;
	}
//	#define t[max_fac[x].x] T
	for(int T=0;T<2;++T)
	{
		if(T)
			add(max_fac[x].x,1);
		dfs(x+1);
		if(T)
			add(max_fac[x].x,-1);
	}
}
void work()
{
	ans=0;
	memset(max_fac,0,sizeof max_fac);
	for(int i=l;i<=r;++i)
		max_fac[i]=(P){i,factor[i][factor[i].size()-1]};
	std::sort(max_fac+l,max_fac+r+1);
	dfs(l);
	printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
	factor[1].push_back(1);
	for(int i=2;i<=1000;++i)
		if(!factor[i].size())
		{
			for(int j=i;j<=1000;j+=i)
				factor[j].push_back(i);
		}
	int T;
	for(scanf("%d",&T);T--;scanf("%d%d",&l,&r),work());
	return 0;
}