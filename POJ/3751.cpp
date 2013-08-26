#include <cstdio>
#include <cstring>
int T;
int main()
{
	int y,m,d,h,min,s;
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		scanf("%d/%d/%d-%d:%d:%d",&y,&m,&d,&h,&min,&s);
		printf("%02d/%02d/%04d-%02d:%02d:%02d",m,d,y,((h+11)%12)+1,min,s);
		if (h<12)
			printf("am\n");
		else
			printf("pm\n");
	}
}
