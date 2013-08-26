#include <cstdio>
#include <cstring>
int N,M;
int f[12881];
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		int i,j,w,d;
		memset(f,0,sizeof(f));
		while (N--)
		{
			scanf("%d%d",&w,&d);
			for (j=M;j>=w;j--)
				if (f[j-w]+d>f[j])
					f[j]=f[j-w]+d;
		}
		printf("%d\n",f[M]);
	}
}
