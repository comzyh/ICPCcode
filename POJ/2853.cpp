#include <cstdio>
#include <cmath>
int N,m;
int main()
{
	int i,j,sq;
	scanf("%d",&N);
	for (i=1;i<=N;i++)
	{
		int tmp,ans=0;
		scanf("%d%d",&tmp,&m);
		sq=(int)(sqrt(m)*1.414);
		m*=2;
		for (j=2;j<=sq;j++)
		if (m%j==0 && (m/j)-j>0 && ((j^(int)(m/j))&1))
			ans++;
		printf("%d %d\n",tmp,ans);
	}
}
