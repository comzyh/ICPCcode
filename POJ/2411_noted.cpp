#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int MASK;
int H,W;
long long  f[16][2048];
int legal[2048],R;
/* void pribin(int x)
{
	do
	{	
		printf("%d",x&1);
		x>>=1;
	}while(x);
	printf("\n");
} */
void dfs(int now,int pos)
{
	legal[++R]=now;//pribin(now);
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
	//printf("R=%d\n",R);
	while (scanf("%d%d",&H,&W),H && W)
	{
		if (H<W)
			swap(H,W);
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
		/* printf("H=%d,W=%d\n",H,W);
		for (i=1;i<=H;i++)
		{
			for (j=0;j<=MASK;j++)
				printf("%5lld ",f[i][j]);
			printf("\n");
		} */
		printf("%lld\n",f[H][MASK]);
	}
}