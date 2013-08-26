#include <cstdio>
int T;
int main()
{
	int a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		if ((a-b)>=0 && !((a-b)&0x1))
			printf("%d %d\n",(a+b)>>1,(a-b)>>1);
		else
			printf("impossible\n");
	}
}