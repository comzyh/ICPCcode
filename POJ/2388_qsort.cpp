#include <cstdio>
int tab[10001],t;
int N;
int qsort(int b,int e,int x);
int main()
{
	int i;
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&tab[i]);
		printf("%d\n",qsort(1,N,(N+1)>>1));
	}
}
int qsort(int b,int e,int x)
{
	int i=b,j=e,k=tab[(b+e)>>1];
	while (i<j)
	{
		while (tab[i]<k)i++;
		while (tab[j]>k)j--;
		if (i<=j)
		{
			t=tab[i];
			tab[i]=tab[j];
			tab[j]=t;
			i++;j--;
		}
	}
	if (b<j && x<=j)  qsort(b,j,x);
	if (i<e && x>=i)  qsort(i,e,x);
	return tab[x];	
}
