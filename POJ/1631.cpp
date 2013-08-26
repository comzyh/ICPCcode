#include <cstdio>
#include <cstring>
int T,N,ANS;
int f[40001];//f[i] 表示长度为 i 最长上升子序列最小的结尾
int bin(int arr[],int b,int e,int x)
{
	int k;
	while (b<e)
	{
		k=(b+e+1)>>1;
		if (arr[k]>=x)
			e=k-1;
		else
			b=k;
	}
	return b;

	}
int main()
{
	f[0]=0;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		ANS=0;
		for (int i=1;i<=N;i++)
			f[i]=0x3fffffff;
		for (int i=1;i<=N;i++)
		{
			int x,y;
			scanf("%d",&x);
			y=bin(f,0,i-1,x);
			if(y+1>ANS)
				ANS=y+1;
			if(x<f[y+1])
				f[y+1]=x;
		}
		printf("%d\n",ANS);
	}
	return 0;

}