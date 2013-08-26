#include <cstdio>
#include <iostream>
using namespace std;
int N,K;
int dfs(int k,int n,int l)//1:*2 2:+1 3:-1
{
	if (k==0)
		return n==K;
	if (n>K)
		return k>=n-K;
	switch (l)
	{
		case 1:
			return dfs(k-1,n*2,1)||dfs(k-1,n+1,2)||(n>1 && dfs(k-1,n-1,3));
		case 2:
			return dfs(k-1,n*2,1)||dfs(k-1,n+1,2);
		case 3:
			return dfs(k-1,n*2,1)||(n>1 && dfs(k-1,n-1,3));
	}
}
int main()
{
	scanf("%d%d",&N,&K);
	int i;
	for (i=0;dfs(i,N,1)==0;i++);
	printf("%d\n",i);
	return 0;
}