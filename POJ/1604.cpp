#include <cstdio>
int main()
{
	int A,ans;
	while (scanf("%d",&A)!=EOF)
	{
		ans=1;
		for (int i=1;i<=A;i++)
		{
			ans*=i;
			while (ans%10==0)
				ans/=10;
			ans%=100000;
		}
		while (ans%10==0)
			ans/=10;
		printf("%5d -> %d\n",A,ans%10);
	}
	return 0;
}