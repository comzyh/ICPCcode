#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
double ans[100000];
int main()
{
	printf("Cards  Overhang\n");
	ans[0]=0.0;
	for (int i=1;i<=99999;i++)
		ans[i]=ans[i-1]+1.0/2/i;
	int N;
	while (scanf("%d",&N)!=EOF)
		printf("%5d%10.3lf\n",N,ans[N]);
	return 0;
}