#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return a;		
	}
	long long r=exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
long long N,M,X,Y,L;
int main()
{
	while (scanf("%lld%lld%lld%lld%lld",&X,&Y,&M,&N,&L)!=EOF)
	{
		if (N<M)
		{
			swap(M,N);
			swap(X,Y);
		}
		long long MN=N-M,LL=L,XY=X-Y,A,B,gcd;
		gcd=exgcd(MN,LL,A,B);
		if (XY%gcd!=0|| M==N)
		{
			printf("Impossible\n");
			continue;
		}
		MN/=gcd;//a
		LL/=gcd;//b
		XY/=gcd;//c
		exgcd(MN,LL,A,B);
		//A*=XY;
		long long ANS=(A*XY);
		ANS=(ANS%LL+LL)%LL;
		printf("%lld\n",ANS);
	}
	return 0;
}
