#include <cstdio>
int N;
int rev(int x)
{
	int ans=0;
	while (x)
	{
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	scanf("%d",&N);
	while (N--)
	{
		int a,b,c;
		scanf("%d%d",&a,&b);
		c=rev(rev(a)+rev(b));
		printf("%d\n",c);
	}
}