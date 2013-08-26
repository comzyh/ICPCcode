#include <cstdio>
#include <cstring>
const int MAX= 10000;
int notprime[20000];
int prime[3000],np;
int compose[MAX+5];
void dfs(int sum,int b);
int main()
{
	int i,j;
	//筛素数
	for (i=2;i<=MAX;i++)
		if(!notprime[i])
			for (j=i+i;j<=MAX;j+=i)
				notprime[j]=1;
	//素数表
	np=0;
	for (i=2;i<=MAX;i++)
		if(!notprime[i])
			prime[++np]=i;
	//组合方式表
	memset(compose,0,sizeof(compose));
	for (i=1;i<=np;i++)
		dfs(prime[i],i+1);
	//输出
	int n;
	while(scanf("%d",&n),n)
		printf("%d\n",compose[n]);
}
void dfs(int sum,int b)
{
	if (sum>MAX)
		return ;
	compose[sum]++;
	if(b<np && sum+prime[b]<MAX)
		dfs(sum+prime[b],b+1);
}