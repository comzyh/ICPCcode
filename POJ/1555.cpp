#include <cstdio>
int a[9];
int main()
{
	while (scanf("%d",&a[8])!=EOF)
	{
		int i,b;
		for (i=7;i>=0;i--)
			scanf("%d",&a[i]);
		for (b=8;a[b]==0 && b>=0;b--);
		for (i=b;i>=0;i--)
		if (a[i])
		{
			if (i==b)
			{
				if (a[i]<0)
					printf("-");
			}
			else
			{
				if (a[i]<0)
					printf(" - ");
				else
					printf(" + ");
			}
			if ((a[i]!=1 && a[i]!=-1) || i==0)
			{
				if (a[i]>0)
					printf("%d",a[i]);
				else
					printf("%d",-a[i]);
			}
			if(i>=1)
				printf("x");
			if (i>=2)
				printf("^%d",i);
		}
		if (b==-1)
			printf("0\n");
		else 
			printf("\n");
	}
}