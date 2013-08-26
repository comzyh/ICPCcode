#include <cstdio>
#include <cstring>
const int d='a'-'A';
int T,L;
char str[100],ans[100];
int ap[128];
void dfs(int k);
int main()
{
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(str);
		memset(ap,0,sizeof(ap));
		int i;
		for (i=0;str[i]!='\0';i++)
			ap[str[i]]++;
		L=i;
		ans[L]='\0';
		dfs(0);
	}
	
}
void dfs(int k)
{
	if (k==L)
	{
		puts(ans);
		return ;
	}
	for (int i='A';i<='Z';i++)
	{
		if(ap[i])
		{
			ans[k]=i;
			ap[i]--;
			dfs(k+1);
			ap[i]++;
		}
		if(ap[i+d])
		{
			ans[k]=i+d;
			ap[i+d]--;
			dfs(k+1);
			ap[i+d]++;
		}
	}
}
