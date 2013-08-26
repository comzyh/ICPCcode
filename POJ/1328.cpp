#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
struct T_range
{
	double b,e;
}rs[1005];
int N,D,T,ANS;
void qsort(int b,int e);
int main()
{
	int  i,j,x,y,fail;
	double t,low;
	T=0;
	while (scanf("%d%d",&N,&D),N!=0 || D!=0)
	{
		T++;
		ANS=0;
		fail=0;
		for (i=1;i<=N;i++)
		{
			scanf("%d%d",&x,&y);
			if (y<=D)
			{
				t=sqrt((double)(D*D-y*y));
				rs[i].b=(double)x-t;
				rs[i].e=(double)x+t;
			}
			else
				fail=1;
			
		}
		if (fail)
			printf("Case %d: -1\n",T);
		else
		{
			qsort(1,N);
			/*for (i=1;i<=N;i++)
				printf("i=%3d %7.5f %7.5f\n",i,rs[i].b,rs[i].e);*/
			for (i=1;i<=N;i++)
			{
				low=rs[i].e;
				for (j=i; j<N && rs[j+1].b<=low;j++)
					if (rs[j+1].e<low)low=rs[j+1].e;
				i=j;
				//printf("i=%d\n",i);
				ANS++;
			}
			printf("Case %d: %d\n",T,ANS);
		}
	}
}
void qsort(int b,int e)
{
	int i=b,j=e;
	double k=rs[(b+e)>>1].b;
	while (i<j)
	{
		while (rs[i].b<k)i++;
		while (rs[j].b>k)j--;
		if (i<=j)
		{
			swap(rs[i],rs[j]);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
