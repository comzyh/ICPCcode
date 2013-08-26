#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		int ans=1,n=N;
		N--;
		for (int i=2;N>1;i++)
		{
			if (N%i==0)
			{
				ans=(ans*(i-1))%n;
				while(N%i==0)
				{
					N/=i;
					if (N%i==0)
						ans=(ans*i)%n;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
