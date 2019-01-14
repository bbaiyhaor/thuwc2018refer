#include <bits/stdc++.h>
int n,l,r,ans;
int main(int argc, char const *argv[])
{
	for(scanf("%d",&n);n--;scanf("%d%d",&l,&r),ans+=r-l);
		printf("%d\n",ans);
	return 0;
}