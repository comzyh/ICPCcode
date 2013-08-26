#include <cstdio>
#include <cstring>
int N,K,ANS;
int full;
int map[10];
inline int lowbit(int k)
{
	return k&(k^(k-1));
}
void DFS(int state,int k,int remain)
{
	//printf("%x,k=%d,remain=%d\n",state,k,remain);
	if (remain==0)
	{
		ANS++;
		return ;
	}
	if (k>N)
		return;
	int ts=state&map[k],tc;
	if (remain+k<=N)DFS(state,k+1,remain);
	while (ts!=0)
	{
		tc=lowbit(ts);
		DFS(state&(~tc),k+1,remain-1);
		ts-=tc;
	}
}
int main()
{
	int i,j;
	char c;
	while (scanf("%d%d",&N,&K),N>0 && K>0)
	{
		full=(1<<N)-1;
		for (i=1;i<=N;i++)
		{
			getchar();
			map[i]=full;
			for (j=0;j<N;j++)
			{
				scanf("%c",&c);
				if (c=='.')
					map[i]&=(~(1<<(j)));
			}
		}
		ANS=0;
		DFS(full,1,K);
		printf("%d\n",ANS,K);
	}
	
}
