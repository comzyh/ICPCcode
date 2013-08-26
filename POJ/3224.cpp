#include <cstdio>
int N,MAX,SUM,ANS;
int main()
{
	int i,j,x;
	while (scanf("%d",&N)!=EOF)
	{
		MAX=0;
		for (i=1;i<=N;i++)
		{
			SUM=0;
			for (j=1;j<=N;j++)
			{
				scanf("%d",&x);
				if (x==3)SUM++;
			}
			if (SUM>MAX)
			{
				MAX=SUM;
				ANS=i;
			}
			
		}
		printf("%d\n",ANS);
	}
}