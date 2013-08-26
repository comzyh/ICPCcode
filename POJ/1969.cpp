#include <cstdio>
#include <cstring>
const int MAX=4471;
int N;
int tab[4500];//4471
int bin(int n)
{
	int b=0,e=MAX,k=(b+e+1)>>1;
	while (b<e)
	{
		if (tab[k]>n)
			e=k-1;
		else
			b=k;
		k=(b+e+1)>>1;
	}
	return k;
}


int main()
{
	int i,p,a,b,d;
	for (i=1;((1+i)*i)/2<=10000000;i++)
		tab[i]=((1+i)*i)/2;
	//printf("i=%d\n",i);
	//for (i=1;i<=10;i++)
	//	printf("%d\n",tab[i]);
	tab[0]=0;
	while (scanf("%d",&N)!=EOF)
	{
		//  a/b
		p=bin(N-1);
		//printf("p=%d\n",p);
		d=(N-((p+1)*p/2));
		if (p%2==0)
		{
			a=p+2-d;
			b=d;
		}
		else
		{
			a=d;
			b=p+2-d;
		}
		printf("TERM %d IS %d/%d\n",N,a,b);
	}
	return 0;
	
}
