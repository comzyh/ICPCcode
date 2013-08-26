#include <cstdio>
#include <cstring>
int T,H,M;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d:%d",&H,&M);
		if (M!=0)
			printf("0\n");
		else
			printf("%d\n",((H%24)+11)%24+1);
	}
}
