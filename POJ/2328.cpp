#include <cstdio>
#include <cstring>
int high,low,x;
int main()
{
	char str[50];
	do
	{
		high=11;
		low=0;
		int honest=1;
		while(scanf("%d",&x),x)
		{
			getchar();
			gets(str);
			if (strcmp(str,"right on")==0)
			{
				if (honest && x>low && x<high)
					printf("Stan may be honest\n");
				else
					printf("Stan is dishonest\n");
				x=1;
				break;
			}
			if (strcmp(str,"too high")==0)
				high=(x<high)?x:high;
			else
				low=(x>low)?x:low;
			if (high-low<=1)
				honest=0;
		}
	}while(x);
}
