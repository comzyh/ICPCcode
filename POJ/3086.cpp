#include <cstdio>
int N;
int tab[302];
int main()
{
	int i,n;
	scanf("%d",&N);
	tab[0]=0;
	for (i=1;i<=300;i++)
		tab[i]=tab[i-1]+((i*(i+2)*(i+1))>>1);
	for (i=1;i<=N;i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,tab[n]);
	}
}