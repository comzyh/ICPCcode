#include <cstdio>
int main()
{
	int a,b,c,d1,d2,dd;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		d1=b-a;
		d2=c-b;
		dd=d2-d1;
		printf("%d %d %d\n",c+d2+dd,c+2*d2+3*dd,c+3*d2+6*dd);
	}
	return 0;
}