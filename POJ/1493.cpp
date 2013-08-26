#include <cstdio>
int main()
{
	int N;
	int i,j;
	char c;
	int sum_space,min_space,space;
	while (scanf("%d",&N),N)
	{
		sum_space=0;
		min_space=9999;
		for (i=1;i<=N;i++)
		{
			getchar();
			space=0;
			for (j=1;j<=25;j++)
				if (scanf("%c",&c),c==' ')space++;
			sum_space+=space;
			if (space<min_space)min_space=space;
		}
		printf("%d\n",sum_space-N*min_space);
	}

}
