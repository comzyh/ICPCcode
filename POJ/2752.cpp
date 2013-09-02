#include <cstdio>
#include <cstring>
const int DS=400000;
char str[DS+1];
int next[DS+1];
int ans[DS],tot;
int main()
{
	while (gets(str)!=NULL)
	{
		int i;
		next[0]=0;
		for (i=1;str[i];i++)
		{
			int j=next[i-1];
			while (str[i]!=str[j] && j!=0)
				j=next[j-1];
			if (str[i]==str[j])
				next[i]=j+1;
			else
				next[i]=0;
		}
		tot=0;
		ans[++tot]=i;
		i--;
		while (next[i])
		{
			ans[++tot]=next[i];
			i=next[i]-1;
		}
		while (tot)
			printf("%d ",ans[tot--]);
		printf("\n");
	}
	return 0;
}