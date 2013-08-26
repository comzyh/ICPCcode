#include <cstdio>
#include <cstring>
const int MAX=1000;
int Fail,T=0;
int f[MAX+1],exist[MAX+1];
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)//x is child of y
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy || fx!=x)
	{
		Fail=1;
		return ;
	}
	f[fx]=fy;		
}
int main()
{
	while (1)
	{	
		int i,x,y;
		for (i=1;i<=MAX;i++)
			f[i]=i;
		memset(exist,0,sizeof(exist));
		Fail=0;
		while (scanf("%d%d",&x,&y),x!=0 && y!=0)
		{
			if (x==-1 && y==-1)
				return 0;
			exist[y]=1;
			exist[x]=1;
			add(y,x);
		}
		int fa=0;
		for (i=1;i<=MAX;i++)
			if (exist[i] && f[i]==i)
				fa++;
		if (fa>1)
			Fail=1;
		if (Fail)
			printf("Case %d is not a tree.\n",++T);
		else
			printf("Case %d is a tree.\n",++T);
	}
	return 0;
}
