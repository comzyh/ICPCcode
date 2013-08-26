#include <cstdio>
#include <cmath>
int main()
{
	int y,i,j;
	double MAX,T,MAXLOG;
	while (scanf("%d",&y),y)
	{
		MAX=4;
		for (i=1970;i<=y;i+=10)
			MAX+=MAX;
		//printf("MAX=%lf\n",MAX);
		T=0;
		for (i=1;T<MAX;i++)
			T+=log2(i);
		printf("%d\n",i-2);
		
		
	}
}