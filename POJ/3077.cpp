#include <cstdio>
int N,T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int i,t=0;
		for (t=0;N>9;t++)
		{
			if (N%10>4)
				N+=10;
			N/=10;
		}
		printf("%d",N);
		for (i=1;i<=t;i++)
			printf("0");
		printf("\n");
	}
}
