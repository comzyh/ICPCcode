#include <cstdio>
#include <cstdlib>
#include <ctime>
int T;
int main()
{
	int a,b;
	scanf("%d",&T);
	srand ((int)time(0));
	printf("%d\n",T);
	while (T--)
	{
		a=rand()+rand()+rand()+rand()-0xffff;
		b=rand()+rand()+rand()+rand()-0xffff;
		printf("%d %d\n",a,b);
	}
}
