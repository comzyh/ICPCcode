#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct block
{
	int d[3];
	inline int operator < (const block &x)const
	{
		return d[0]<x.d[0] && d[1]<x.d[1];
	}

}ds[91];
int N,TT;
int tab[91][91];
int main()
{
	TT=0;
	while (scanf("%d",&N),N)
	{
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<3;j++)
				scanf("%d",&ds[3*i+1].d[j]);
			sort(ds[3*i+1].d,ds[3*i+1].d+3);
			ds[3*i+3]=ds[3*i+2]=ds[3*i+1];
			swap(ds[3*i+2].d[1],ds[3*i+2].d[2]);//2 h
			swap(ds[3*i+3].d[0],ds[3*i+3].d[2]);
			swap(ds[3*i+3].d[0],ds[3*i+3].d[1]);//1 h
		}
		for (int i=0;i<3;i++)
			ds[0].d[i]=0;
		// for (int i=0;i<=3*N;i++)
		// 	printf("%4d %4d %4d\n",ds[i].d[0],ds[i].d[1],ds[i].d[2]);
		for (int i=0;i<=3*N;i++)
			for (int j=0;j<=3*N;j++)
				if (ds[i]<ds[j])
					tab[i][j]=ds[j].d[2];
				else
					tab[i][j]=0;
		//floyd
		int ans=0;
		for (int k=0;k<=3*N;k++)
			for (int i=0;i<=3*N;i++)
				for (int j=0;j<=3*N;j++)
					if (tab[i][k] && tab[k][j])
					ans=max(ans,tab[i][j]=max(tab[i][j],tab[i][k]+tab[k][j]));
		// for (int i=0;i<=3*N;i++)
		// {
		// 	for (int j=0;j<=3*N;j++)
		// 		printf("%5d ",tab[i][j]);
		// 	printf("\n");
		// }
		printf("Case %d: maximum height = %d\n",++TT,ans);
	}
	return 0;
}