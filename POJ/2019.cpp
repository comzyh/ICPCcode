#include <cstdio>
#include <cstring>
//#include <iostream>
//using namespace std;
//(1 <= N <= 250)
int N,B,K;
int tab[253][253];
int Maxst[253][253][9],Minst[253][253][9];
int bk,d;
inline int max(int a,int b){if (a>b)return a;else return b;}
inline int min(int a,int b){if (a<b)return a;else return b;}
void build(int (&arr)[253][253][9],int (*cmp)(int ,int))
{
	int i,j,k;
	for (k=1;(1<<k)<=N;k++)
	{
		int k2=1<<(k-1);
		for (i=1;i+k2+k2<=N+1;i++)
			for (j=1;j+k2+k2<=N+1;j++)	
				arr[i][j][k]=cmp(cmp(arr[i][j][k-1],arr[i+k2][j+k2][k-1]),cmp(arr[i+k2][j][k-1],arr[i][j+k2][k-1]));
	}
}
inline int query(int(&arr)[253][253][9],int (*cmp)(int ,int),int x,int y)
{
	return cmp(cmp(arr[x][y][bk],arr[x+d][y+d][bk]),cmp(arr[x+d][y][bk],arr[x][y+d][bk]));
}
int main()
{
	while(scanf("%d%d%d",&N,&B,&K)!=EOF)
	{
		memset(tab,0,sizeof(tab));
		int i,j,k;
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				scanf("%d",&tab[i][j]);
				Maxst[i][j][0]=tab[i][j];
				Minst[i][j][0]=tab[i][j];
			}
		//ST
		build(Maxst,max);
		build(Minst,min);
		for (bk=0;(2<<bk)<B;bk++);
		d=B-(1<<bk);
		for (i=1;i<=K;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(Maxst,max,a,b)-query(Minst,min,a,b));
		}
	}
	return 0;
}