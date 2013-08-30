#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,M;
int degree[50009];
int main()
{
	scanf("%d%d",&N,&M);
	memset(degree,0,sizeof(degree));
	while (M--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		degree[a]++;
		degree[b]++;
	}
	int ans=0;
	for (int i=1;i<=N;i++)
	{
		if (degree[i]<=1)
		{
			if (degree[i]==0)
				ans+=4;
			else
				ans+=1;
		}
	}
	ans++;
	printf("%d\n",ans>>1);
	return 0;
}