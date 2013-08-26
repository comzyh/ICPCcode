#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main()
{
	LL X,Y,M,N,L;
	while (scanf("%lld%lld%lld%lld%lld",&X,&Y,&M,&N,&L)!=EOF)
	{
		LL a=M-N,b=L,c=Y-X,gcd,x,y;
		if (a<0)
		{
			a=-a;
			c=-c;
		}
		gcd=exgcd(a,b,x,y);
		if (c%gcd || M==N)
		{
			printf("Impossible\n");
			continue ;
		}
		a/=gcd;
		b/=gcd;
		c/=gcd;
		exgcd(a,b,x,y);
		LL ans=x*c;
		//printf("%lld\n",ans);
		ans=(ans%b+b)%b;
		printf("%lld\n",ans);		
	}
	return 0;
}
