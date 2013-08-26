#include <cstdio>
int main()
{
	int N,r,e,c;
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d%d%d",&r,&e,&c);
		if (e-r>c)
			printf("advertise\n");
		if (e-r<c)
			printf("do not advertise\n");
		if (e-r==c)
			printf("does not matter\n");
	}
}