#include <cstdio>
#include <cstring>
int T;
int N,M,ANS;
int r[121];
int main()
{
	int i,j,f,t;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&M);
		memset(r,0,sizeof(r));
		for (i=1;i<=M;i++)
		{
			scanf("%d%d",&f,&t);
			r[t]++;
		}
		ANS=0;
		for (i=1;i<=N;i++)
			if (r[i]==0)
				ANS++;
		printf("%d\n",ANS);
	}
}