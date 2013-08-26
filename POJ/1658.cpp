#include <cstdio>
#include <cstring>
int T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d %d %d ",a,b,c,d);
		if (b*b==a*c && c*c==b*d)
			printf("%d\n",d*d/c);
		else
			printf("%d\n",2*d-c);
	}
}
