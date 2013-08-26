#include <cstdio>
#include <cstring>
int T,M,Y;
int D;
int w[20],v[20];
int f[50000];
int main()
{
	int i,j,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&M,&Y,&D);
		for (i=1;i<=D;i++)
		{
			scanf("%d%d",&w[i],&v[i]);
			v[i]+=w[i];
			w[i]/=1000;
		}
		w[0]=1;
		v[0]=1000;
		while (Y--)
		{
			memset(f,0,sizeof(f));
			f[0]=M%1000;
			m=(M-f[0])/1000;
			for (i=1;i<=m;i++)
				for (j=0;j<=D;j++)
					if (i>=w[j] && (f[i-w[j]]+v[j]>f[i]))
						f[i]=f[i-w[j]]+v[j];
			M=f[m];
		}
		printf("%d\n",M);
	}
	return 0;
}
