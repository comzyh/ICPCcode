#include <cstdio>
#include <cstring>
const int MAX=1000000;
int N;
int ans[MAX+5],tab[100],R;
void dfs(int sum,int k)
{
	if(k>R)
	{
		if (sum<MAX)
			ans[sum]=1;
		return ;
	}
	dfs(sum,k+1);
	dfs(sum+tab[k],k+1);	
}
int main()
{
	int i;
	tab[0]=1;
	for (i=1;tab[i-1]<=MAX;i++)
		tab[i]=i*tab[i-1];
	R=i-1;
	memset(ans,0,sizeof(ans));
	dfs(0,0);
	ans[0]=0;
	while (scanf("%d",&N),N>=0)
		if(ans[N])
			printf("YES\n");
		else
			printf("NO\n");
}