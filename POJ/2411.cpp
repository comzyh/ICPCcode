#include <cstdio>
#include <cstring>
#include <iostream>
int MASK;
int H,W;
long long  f[16][2048];
int legal[2048],R;
void dfs(int now,int pos)
{
	legal[++R]=now;
	if (pos>=10)
		return;
	for (int i=pos;i<=9;i++)
		dfs(now|(0x3<<i),i+2);
}
int main()
{
	int i,j,k;
	memset(legal,0,sizeof(legal));
	R=0;
	dfs(0,0);
	while (scanf("%d%d",&H,&W),H && W)
	{
		if (H<W)
			std::swap(H,W);
		memset(f,0,sizeof(f));
		MASK=(1<<W)-1;
		f[0][MASK]=1;
		for (i=1;i<=H;i++)
		{
		
			for (j=0;j<=MASK;j++)
			if (f[i-1][j])
			{
				int jj=j^MASK;
				for (k=1;k<=R;k++)
				if(((jj^legal[k])&jj)==jj)
					f[i][jj|legal[k]]+=f[i-1][j];
			}
		}
		printf("%lld\n",f[H][MASK]);
	}
}