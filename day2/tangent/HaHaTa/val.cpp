#include<cstdio>
#include<cstdlib>
#include<cmath>
#define K 10
const double eps=1e-6;
using namespace std;

struct Point{double x[K];}P[K][1<<K][K];
struct Circle{double x[K],r;}C[K][K];

bool Point_on_Circle(Point P,Circle C,int k)
{
	double s=0;
	for (int i=0;i<k;i++)
		s+=(P.x[i]-C.x[i])*(P.x[i]-C.x[i]);
	return fabs(s-C.r*C.r)<eps;
}

int T,num_in[K],num_ans[K];
bool flag,tmp;

int main()
{
	freopen("8.in","r",stdin);
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		scanf("%d",&num_in[i]);
		for (int j=0;j<num_in[i];j++)
		{
			for (int k=0;k<num_in[i];k++)
				scanf("%lf",&C[i][j].x[k]);
			scanf("%lf",&C[i][j].r);
		}
	}
	fclose(stdin);
	freopen("8.ans","r",stdin);
	for (int i=0;i<T;i++)
	{
		scanf("%d",&num_ans[i]);
		for (int j=0;j<num_ans[i];j++)
			for (int k=0;k<num_in[i];k++)
				for (int l=0;l<num_in[i];l++)
					scanf("%lf",&P[i][j][k].x[l]);
	}
	fclose(stdin);
	for (int i=0;i<T;i++)
	{
		flag=1;
		for (int j=0;j<num_ans[i];j++)
			for (int k=0;k<num_in[i];k++)
				{
					tmp=0;
					for (int l=0;l<num_in[i];l++)
						if (Point_on_Circle(P[i][j][k],C[i][l],num_in[i]))tmp=1;
					flag&=tmp;
				}
		if (flag)printf("case#%d:Correct!\n",i+1);
		else printf("case#%d:Wrong Answer!\n",i+1);
	}
	return 0;
}
