#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int T;
int solve(int N)
{
	int ans=0x3f3f3f3f;
	for (int i=1;i<=N;i++)
		if (N%i==0)
		for (int j=1;j<=N;j++)
			if ((N/i)%j==0)
			{
				int c=N/i/j;
				ans=min(ans,i*j+i*c+j*c);
			}
	return 2*ans;

}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}