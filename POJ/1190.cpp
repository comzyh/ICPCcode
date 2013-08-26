#include <cstdio>
#include <cstdlib>
const int MAX=0x3fffffff;
int N,M;
int ANS;
int DFS(int n,int m,int mh,int r,int sum);
inline int min(int x,int y)
{
	if (x>y)return y;
	return x;
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		int i,j;
		ANS=0x7fffffff;
		for (i=1;i*i<=N;i++);
		for (i=i;i>=M;i--)
		{
			DFS(N,M,1000000,i,i*i);
		}
		if (ANS==0x7fffffff)
			printf("0\n");
		else
			printf("%d\n",ANS);
	}
}
int DFS(int n,int m,int mh,int r,int sum)
{
	if ((n/r)*2>=ANS-sum)return 0;
	if (m==1)
	{
		if (n%(r*r)==0 && n/(r*r)<=mh && sum+(n/r)*2<ANS)
			ANS=sum+(n/r)*2;
		return 0;
	}
	for (int h=min(n/(r*r),mh);h>=m-1;h--)
		for (int i=r-1;i>=m-1;i--)
		{
			if (n-(h*r*r)>0)
				DFS(n-(h*r*r),m-1,h-1,i,sum+2*h*r);
		}
}
