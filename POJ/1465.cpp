#include <cstdio>
#include <cstring>
int N,M,X[11],ANS,tans;
//int num[15];
int DFS(int num,int deep);
int main()
{
	int i,x;
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		memset(X,0,sizeof(X));
		for (i=1;i<=M;i++)
		{
			scanf("%d",&x);
			X[x]=1;
		}
		ANS=0;
		for (i=1;i<5000;i++)
		{	
			if (tans=DFS(0,i))
			{
				//printf("%d\n",tans);
				ANS=1;
				break;
			}
		}
		if (!ANS)
			printf("0\n");
	}
}
int DFS(int num,int deep)
{
	//printf("deep=%d\n",deep);
	int i,n;
	int ans,min=0x3fffffff; 
	if (deep==0)return 0;
	for (i=0;i<=9;i++)
	{
		if (i==0 && num==0)continue;
		n=num+N*i;
		if (X[n%10])
		{
			ans=0;
			if (n<10 || (ans=DFS(n/10,deep-1)))
			{
				printf("%d",n%10);
				return 1;
				if ((ans*10+n%10)<min)
					min=(ans*10+n%10);
			}
		}
	}
	if (min<0x3fffffff)
		return min;
	else
		return 0;
}
