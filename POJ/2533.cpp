#include <cstdio>
#include <cstring>
int N,ANS=0;
int f[10005];
inline int bin(int x);
int main()
{
	int i,j,n;
	scanf("%d",&N);
	f[0]=0;
	for (i=1;i<=N;i++)
		f[i]=0x7fffffff;
	for (i=1;i<=N;i++)
	{
		scanf("%d",&n);
		j=bin(n-1);
		if (n<f[j+1])f[j+1]=n;
		if (j+1>=ANS)ANS=j+1;
	}
	printf("%d",ANS);
}
inline int bin(int x)
{
	int b=0,e=N,k=(b+e+1)>>1;
	while (b<e)
	{
		if (f[k]>x)e=k-1;
		else
			if (f[k]<=x)b=k;
		k=(b+e+1)>>1;
	}
	return k;
}