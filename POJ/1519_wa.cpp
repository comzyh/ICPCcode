#include <cstdio>
int N;
int Root(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=x%10;
		x/=10;
	}
	if (ans<10)
		return ans;
	else
		return Root(ans);
}
int main()
{
	while (scanf("%d",&N),N)
		printf("%d\n",Root(N));
}
