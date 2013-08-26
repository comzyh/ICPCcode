#include <cstdio>
#include <cstring>
int N,D;
int attend[200];
int main()
{
	while (scanf("%d%d",&N,&D),N &&D)
	{
		int i,x;
		for (i=1;i<=N;i++)
			attend[i]=1;
		while(D--)
			for (i=1;i<=N;i++)
			{
				scanf("%d",&x);
				attend[i]&=x;
			}
		int yes=0;
		for (i=1;i<=N;i++)
			yes|=attend[i];
		if (yes)
			printf("yes\n");
		else
			printf("no\n");	
	}
}
