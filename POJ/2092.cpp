#include <cstdio>
#include <cstring>
int app[10001];
int N,M;
int main()
{
	int max,max2,MAX;
	while (scanf("%d%d",&N,&M),N && M)
	{
		int i,x,nm=N*M;
		memset(app,0,sizeof(app));
		MAX=0;
		for (i=1;i<=N*M;i++)
		{
			scanf("%d",&x);
			app[x]++;
			if (x>MAX)MAX=x;
		}
		max=max2=0;
		for (i=1;i<=MAX;i++)
		if (app[i]>max2)
		{
			if (app[i]>max)
			{
				max2=max;
				max=app[i];
			}			
			else
			max2=app[i];
		}
		for (i=1;i<=MAX;i++)
		if (app[i]==max2)
			printf("%d ",i);
		printf("\n");
	}	
}
