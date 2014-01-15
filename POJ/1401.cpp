#include <cstdio>
#include <iostream>
using namespace std;
//变为5进制,看最后有多少个0,等差数列求和
int main()
{
	int T,N;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int ans=0;
		while ((N/=5)>0)
			ans+=N;
		printf("%d\n",ans);
	}
	return 0;
}