#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,W;
int ps[6];
typedef long long ll;
ll gcd(ll a,ll b)
{
	if (a<b)
		swap(a,b);
	while(b)
	{
		a=a%b;
		swap(a,b);
	}
	return a;
}
int main()
{
	scanf("%d",&N);
	while (N--)
	{
		int x;
		ll ans=1,g;
		scanf("%d",&W);
		while(W--)
		{
			
			scanf("%d",&x);
			g=gcd(ans,x);
			ans*=x;
			ans/=g;
		}
		if (ans>1e9)
			printf("More than a billion.\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}