#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX=1048576;
struct T_segment
{
	int max,min;
}seg[4*MAX+10];
int maxa[MAX],mina[MAX];
int N,K,L2K;
int log2ceil(int x);
void getm(int x);
inline int NextInt();
int main()
{
	
	while (scanf("%d%d",&N,&K)!=EOF)
	{
		int i;
		L2K=log2ceil(K)-1;
		//memset(seg,0,sizeof(seg));
		//memset(max,0,sizeof(max));
		//memset(min,0,sizeof(min));
		for (i=1;i<=K;i++)
		{
			scanf("%d",&seg[L2K+i].max);
			seg[L2K+i].min=seg[L2K+i].max;
		}
		for (i=K+1;i<=L2K+1;i++)
		{
			seg[L2K+i].max=0x80000000;
			seg[L2K+i].min=0x7fffffff;
		}
		getm(1);
		// for (i=1;i<=2*(L2K+1);i++)
			// printf("%4d:%4d %4d\n",i,seg[i].max,seg[i].min);
		int R=1;
		maxa[R]=seg[1].max;
		mina[R]=seg[1].min;
		for (i=K+1;i<=N;i++)
		{
			int M=((i-1)%K)+1;
			//scanf("%d",&seg[L2K+M].max);
			seg[L2K+M].max=NextInt();
			seg[L2K+M].min=seg[L2K+M].max;
			//printf("%d\n",M);
			M+=L2K;
			while (M>1)
			{
				int ma=max(seg[M].max,seg[M^0x1].max),mi=min(seg[M].min,seg[M^0x1].min);;
				if (seg[M>>1].max==ma && seg[M>>1].min==mi)
					break;
				seg[M>>1].max=ma;
				seg[M>>1].min=mi;
				M>>=1;
			}
			R++;
			//printf("R=%d\n",R);
			maxa[R]=seg[1].max;
			mina[R]=seg[1].min;
		}
		for (i=1;i<=R;i++)
			printf("%d ",mina[i]);
		printf("\n");
		for (i=1;i<=R;i++)
			printf("%d ",maxa[i]);
		printf("\n");
		
	}
}
int log2ceil(int x)
{
	int i;
	for (i=1;i<x;i<<=1);
	return i;
}
void getm(int x)
{
	if (x>L2K)
		return ;
	getm(x<<1);
	getm((x<<1)+1);
	seg[x].max=max(seg[x<<1].max,seg[(x<<1)+1].max);
	seg[x].min=min(seg[x<<1].min,seg[(x<<1)+1].min);
}
inline int NextInt()
{
	static int ret,flag;
	ret=0;
	flag=1;
	static char c;
	while (c=getchar(),c==' ' || c=='\n');
	if (c=='-')
	{
		flag=-1;
		c=getchar();
	}
	do
	{
		ret =(ret <<3) + (ret <<1) + c - '0';
		c=getchar(); 
	}while (c >='0' && c<='9');
	//printf("ret=%d\n",ret);
	return flag*ret;
}
