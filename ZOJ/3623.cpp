#include <cstdio>
#include <cstring>
int f[400][400];
int t[40],l[40];
int N,L,ANS;
int main()
{
	while (scanf("%d%d",&N,&L)!=EOF)
	{	
		int i,j,k;
		for (i=1;i<=N;i++)
			scanf("%d%d",&t[i],&l[i]);
		ANS=0;
		f[0][0]=0;
		for (i=1;i<=330;i++)
			f[0][i]=-1;
		//DP
		for (i=1;ANS==0;i++)
		{
			for (j=0;j<=330;j++)
			{
				int tmp=-1,tt;
				if (f[i-1][j]>=0)
					tmp=f[i-1][j]+j;
				for (k=1;k<=N;k++)
					if (i>=t[k] && j>=l[k] && f[i-t[k]][j-l[k]]>=0)//合法数据
					{
						tt=f[i-t[k]][j-l[k]]+(j-l[k])*t[k];
						if (tt>tmp)
							tmp=tt;
					}
				f[i][j]=tmp;
				//printf("f[%4d][%4d]=%d\n",i,j,f[i][j]);
				if (f[i][j]>=L)
				{
					ANS=i;
					break;
				}
			}
		}
		printf("%d\n",ANS);
	}
}
