#include <cstdio>
int N;
int main()
{
	int a,b,i,ANS,MAX;
	while (scanf("%d",&N),N)
	{
		MAX=8;
		ANS=0;
		for (i=1;i<=N;i++)
		{
			scanf("%d%d",&a,&b);
			if (a+b>MAX)
			{
				ANS=i;
				MAX=a+b;
			}
		}
		printf("%d\n",ANS);
	}

}