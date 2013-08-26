//POJ 2388 
#include <cstdio>
int tab[10001],t;
int N;
int qselect(int b,int e,int x);
int main()
{
	int i;
	while (scanf("%d",&N)!=EOF)
	{
		for (i=1;i<=N;i++)
			scanf("%d",&tab[i]);
		printf("%d\n",qselect(1,N,(N>>1)+1));
	}
}
int qselect(int b,int e,int x)
{
	//printf("b=%4d,e=%4d\n",b,e);
	int i=b,j=e,k=tab[(b+e)>>1];
	while (i<=j)
	{
		while(tab[i]<k)i++;
		while(tab[j]>k)j--;
		if (i<=j)
		{
			t=tab[i];
			tab[i]=tab[j];
			tab[j]=t;
			i++;j--;
		}
	} 
	
	if (b<j && x<=j) return qselect(b,j,x);
	if (i<e && x>=i) return qselect(i,e,x);
	return tab[x];
}
