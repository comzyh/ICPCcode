#include <cstdio>
#include <cstring>
int N,ANS,MAX;
int p[70];
int dfs(int deep,int b);
int main()
{
	scanf("%d",&N);
	int x;
	memset(p,0,sizeof(p));
	MAX=0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&x);
		p[x]++;
		if (x>MAX)
			MAX=x;
	}
	ANS=0x7fffffff;
	dfs(0,0);
	printf("%d\n",ANS);
}
int dfs(int deep,int b)
{
	//printf("deep=%d\n",deep);
	if (deep>ANS)
		return 0;
	while (p[b]==0 && b<=MAX)b++;
	if (b>MAX)
	{
		if (deep<ANS)
			ANS=deep;
		return 1;
	}
	int ans=0;
	for (int i=b+1;i<=MAX;i++)//下一个数
	if (p[i])
	{
		int d=i-b,j;
		for (j=b;j<=MAX;j+=d)
			if (p[j]==0)
				break;
		if (j>MAX)
		{
			//printf("%4d,%4d\n",b,d);
			for (j=b;j<=MAX;j+=d)
				p[j]--;
			if (dfs(deep+1,b))
				ans=1;
			for (j=b;j<=MAX;j+=d)
				p[j]++;
		}
	}
	return ans;
}
