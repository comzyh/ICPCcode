#include <cstdio>
int f1,f2,f3;
int main()
{
	while (scanf("%d%d%d",&f1,&f2,&f3)!=EOF)
	{
		int d2=f3-f2,dd=d2-(f2-f1),f4=f3+dd+d2,f5=f4+2*dd+d2,f6=f5+3*dd+d2;
		printf("%d %d %d\n",f4,f5,f6);
	}
	return 0;
}