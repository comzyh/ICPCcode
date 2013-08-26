#include <cstdio>
long long SUM;
int stack[80000],t,N;
int main()
{
	int x;
	while (scanf("%d",&N)!=EOF)
	{
		t=0;
		SUM=0;
		while (N--)
		{
			scanf("%d",&x);
			while (stack[t]<=x && t>0)
				t--;
			SUM+=t;
			stack[++t]=x;
		}
		printf("%lld\n",SUM);
	}
}
