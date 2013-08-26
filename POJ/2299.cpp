//POJ 2299
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int tab[2][500005],t,N;
long long Msort(int b,int e,int d);
int main()
{
	int i;
	while (scanf("%d",&N),N!=0)
	{
		for (i=1;i<=N;i++)
		{
			scanf("%d",&tab[0][i]);
			tab[1][i]=tab[0][i];
		}	
		printf("%lld\n",Msort(1,N,1));
	}
	
}
long long Msort(int b,int e,int d)
{
	//printf("b=%4d,e=%4d\n",b,e);
	if (b>=e-1)
	{
		if (tab[d][b]<=tab[d][e])return 0;
		swap(tab[d][b],tab[d][e]);
		return 1;
	}
	else
	{
		long long ans;
		int mid=(b+e)>>1,i=b,j=mid+1,k,dd=d^1;
		ans=Msort(b,mid,dd)+Msort(mid+1,e,dd);
		for (k=b;k<=e;k++)
		{
			if ((tab[dd][i]<=tab[dd][j] && i<=mid)|| j>e)
				tab[d][k]=tab[dd][i++];
			else
			{
				tab[d][k]=tab[dd][j++];
				ans+=mid+1-i;
			}
		}
		
		//printf("ans=%6d\n",ans);
		return ans;
	}
}
