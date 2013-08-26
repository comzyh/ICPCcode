#include <cstdio>
#include <cstring>
#define MS(a) memset(a,0,sizeof(a));
int T;
char str[401],str1[201],str2[201];
int mem[401][201];
int dfs(int s,int s1);
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%s %s %s",str1,str2,str);
		MS(mem);
		printf("Data set %d: ",TT);
		if (dfs(0,0)==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
int dfs(int s,int s1)
{
	if (mem[s][s1]!=0)
		return mem[s][s1];
	if (str[s]==0)
		return 1;
	mem[s][s1]=-1;
	int i=s1,j=s-s1,k=s;
	while (str[k]!=0 && str1[i]!=str2[j])
	{
		if (str[k]!=str1[i] && str[k]!=str2[j])
			return -1;
		if (str[k]==str1[i])
			i++;
		else
			j++;
		k++;
	}
	if (str[k]==0)
		return mem[s][s1]=1;
	if (dfs(s+1,s1+1)==1 || dfs(s+1,s1)==1)
		mem[s][s1]=1;
	return mem[s][s1];
}