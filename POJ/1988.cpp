#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int f[30005],dis[30005],size[30005];
int P;
int getf(int x)
{
	if (f[x]==x)return x;
	int fx=getf(f[x]);
	dis[x]+=dis[f[x]];
	return f[x]=fx;
}
inline void move(int x,int y)//move x on y
{
	int fx=getf(x),fy=getf(y);
	dis[fx]=size[fy];
	size[fy]+=size[fx];
	f[fx]=fy;
}
int main()
{
	while (scanf("%d",&P)!=EOF)
	{
		for (int i=1;i<=30000;i++)
		{
			f[i]=i;
			dis[i]=0;
			size[i]=1;
		}
		while (P--)
		{
			getchar();
			char c;
			int a,b;
			scanf("%c",&c);
			if (c=='M')
			{
				scanf("%d%d",&a,&b);
				move(a,b);
			}
			else
			{
				scanf("%d",&a);
				getf(a);
				printf("%d\n",dis[a]);
			}

		}
	}
	return 0;
	
}
