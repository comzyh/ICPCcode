//Program 3623 spliter
#include <cstdio>
#include <cstring>
int main()
{
	int N,L;
	while (scanf("%d%d",&N,&L)!=EOF)
	{
		printf("%d %d\n",N,L);
		int t,l;
		for (int i=1;i<=N;i++)
		{
			scanf("%d%d",&t,&l);
			printf("%d %d\n",t,l);
		}
		printf("\n");
	}
}