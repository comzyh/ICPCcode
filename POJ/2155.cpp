#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,N,M;
int BIT[1009][1009];
inline void change(int x,int y)
{
	for (int i=x;i>0;i-=i&-i)
		for (int j=y;j>0;j-=j&-j)
			BIT[i][j]^=1;
}
inline int get(int x,int y)
{
	int ans=0;
	for (int i=x;i<=N;i+=i&-i)
		for (int j=y;j<=N;j+=j&-j)
			ans^=BIT[i][j];
	return ans;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&M);
		memset(BIT,0,sizeof(BIT));
		while (M--)
		{
			getchar();
			char c=getchar();
			int x1,y1,x2,y2;
			
			if (c=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				change(x2,y2);
				change(x2,y1-1);
				change(x1-1,y2);
				change(x1-1,y1-1);
			}
			else
			{
				scanf("%d%d",&x1,&x2);
				printf("%d\n",get(x1,x2));
			}
		}
		puts("");
	}

	return 0;
}