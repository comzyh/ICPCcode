#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int SIZE=999*999+9;
int line[SIZE];
int N,M;
int mergesort(int b,int e,int k)
{
	static int tmp[SIZE];
	int ans=0,mid=(b+e)>>1;
	if (b!=mid)
	{
		ans+=mergesort(b,mid);
		ans+=mergesort(mid+1,e);
	}
	int i=b,j=mid+1,k=b;
	while (i<=mid || j<=e)
	{
		if ((i<=mid && line[i]<=line[j]) || j>e)
			tmp[k++]=line[i++];
		else
		{
			tmp[k++]=line[j++];
			ans+=mid-i+1;
		}
	}
	for (i=b;i<=e;i++)
		line[i]=tmp[i];
	//printf("ans %4d %4d=%4d\n",b,e,ans);
	return ans;

}
int main()
{
	while (scanf("%d%d",&N,&M),N && M)
	{
		int k=0,inv=0;
		for(int i=0;i<N;i++)
			for (int j=0;j<M;j++)
			{
				scanf("%d",&line[k++]);
				if (line[k-1]==0)
				{
					k--;
					inv=N-1-i;
				}
			}
		if (M&1)inv=0;
		inv+=mergesort(0,N*M-2);
		if (inv&1)
			printf("NO\n");
		else
			printf("YES\n");
		//printf("inv=%d\n",inv);

	}
	return 0;

}
