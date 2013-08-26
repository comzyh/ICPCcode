#include <cstdio>
int T;
int main()
{
	int i,m,n;
	scanf("%d",&T);
	for (i=1;i<=T;i++)
	{
		scanf("%d%d",&m,&n);
		m*=n;
		printf("Scenario #%d:\n%d",i,m);
		if (m&1)
			printf(".41\n\n");
		else
			printf(".00\n\n");
	}
}
