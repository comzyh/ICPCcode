#include <cstdio>
int main()
{
	int i,a,b,c,m;
	for (i=1000;i<=9999;i++)
	{
		a=(i%10)+(i/10)%10+(i/100)%10+i/1000;
		b=(i&0xF)+((i>>4)&0xF)+((i>>8)&0xF)+(i>>12);
		if (a!=b)continue;
		c=(i%12)+(i/12)%12+(i/144)%12+i/1728;
		if (a!=c)continue;
		printf("%d\n",i);
	}
}
