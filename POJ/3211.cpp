#include <cstdio>
#include <cstring>
int N,M;
char color[11][13];
int ANS;
int time[110][110];
int sum[11],f[110000];
inline void checkmax(int &a,int b)
{
	if (b>a)
		a=b;
}
int main()
{
	int i,j,k;
	while (scanf("%d%d",&M,&N),N !=0 || M!=0 )
	{
		getchar();
		for (i=1;i<=M;i++)
			scanf("%s",color[i]);
		memset(time,0,sizeof(time));
		memset(sum,0,sizeof(sum));
		ANS=0;
		int t;
		char col[13];
		for (i=1;i<=N;i++)
		{
			scanf("%d %s",&t,&col);
			for (j=1;j<=M;j++)
				if (strcmp(color[j],col)==0)
				{
					sum[j]+=t;
					time[j][++time[j][0]]=t;
				}
		}
		//DP
		ANS=0;
		for (i=1;i<=M;i++)
		{
			memset(f,0,sizeof(f));
			
			int n2=sum[i]/2;
			//printf("n2(%d)=%d\n",i,n2);
			for (j=1;j<=time[i][0];j++)
				for (k=n2;k>=time[i][j];k--)
					checkmax(f[k],f[k-time[i][j]]+time[i][j]);
			ANS+=sum[i]-f[n2];
			//printf("--%d\n",f[n2]);
		}
		printf("%d\n",ANS);
	}
	
}
