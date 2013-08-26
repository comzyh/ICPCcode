#include <cstdio>
#include <algorithm>
int a[6];
int main()
{
	while (scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]),a[0] || a[1] || a[2] || a[3] || a[4] || a[5])
	{
		std::sort(a,a+6);
		printf("%g\n",(double)(a[1]+a[2]+a[3]+a[4])/4);
	}
}
