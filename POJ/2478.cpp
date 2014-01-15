#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int euler[1000009];
long long sum[1000009];
int notPrime[1000009];
vector<int> prime;
int main()
{
	memset(notPrime,0,sizeof(notPrime));
	notPrime[1]=1;
	for (int i=2;i<=1000000;i++)
		euler[i]=i;
	for (int i=2;i<=1000000;i++)
		if (!notPrime[i])
		{
			prime.push_back(i);
			euler[i]=i-1;
			for (int j=i+i;j<=1000000;j+=i)
			{
				notPrime[j]=1;
				euler[j]/=i;
				euler[j]*=i-1;
			}
		}
	for (int i=2;i<=1000000;i++)
		sum[i]=sum[i-1]+euler[i];
	int x;
	while (scanf("%d",&x),x)
		printf("%lld\n",sum[x]);
	return 0;
}