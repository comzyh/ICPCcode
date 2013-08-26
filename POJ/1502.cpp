#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX=0x3fffffff;
int N;
int tab[105][105];
inline int next_int()
{
	int ans=0;
	char c;
	do
	{
		c=getchar();
	}while (c==' '|| c=='\n');
	while (c!=' ' && c!='\n' && c!=EOF)
	{
		
		if (c>='0' && c<='9')
		{
			ans*=10;
			ans+=c-'0';
		}
		if (c=='x')
			return MAX;
		c=getchar();
	}
	return ans;
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		memset(tab,0x3f,sizeof(tab));
		for (int i=2;i<=N;i++)
			for (int j=1;j<i;j++)
				tab[i][j]=tab[j][i]=next_int();
		for (int i=1;i<=N;i++)
			tab[i][i]=0;
		//Floyd
		int i,j,k;
		for ( k=1;k<=N;k++)
			for (i=1;i<=N;i++)
				for (j=1;j<=N;j++)
					tab[i][j]=min(tab[i][j],tab[i][k]+tab[k][j]);
		int ans=0;
		for (i=1;i<=N;i++)
			ans=max(ans,tab[1][i]);
		printf("%d\n",ans);
	}
	return 0;
}