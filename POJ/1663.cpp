#include <cstdio>
int main()
{
	int N,x,y;
	scanf("%d",&N);
	while (N--)
		if (scanf("%d%d",&x,&y),(x-y==0) || (x-y==2))	
			printf("%d\n",(x<<1) -(x-y)-(x&1));
		else
			printf("No Number\n");
}
