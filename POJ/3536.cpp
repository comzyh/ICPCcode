#include <cstdio>
#include <cmath>
int N;
int main()
{
	int i,j,k,Ni,sq,min,ans[3];
	while (scanf("%d",&N)!=EOF)
	{
		min=0x3fffffff;
		sq=(int)ceil(sqrt((double) N));
		for (i=1;i<=sq;i++)
		if (N%i==0)
		{	
			Ni=N/i;
			for (j=1;j<=sq;j++)
			if (Ni%j==0)
			{
				k=Ni/j;
				if (i*j+j*k+i*k<min)
				{
					min=i*j+j*k+i*k;
					ans[0]=i;
					ans[1]=j;
					ans[2]=k;
				}
			}
		}
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	}
}