#include <cstdio>
#include <cstring>
int N,M,ANS;
int t1,t2,na;
int find(int n,int k);
inline int lowbit(int x)
{
	return x&(x^(x-1));
}
//inline void pri(int n);
int main()
{

	int i,j;
	char c;
	while (scanf("%d",&N)!=EOF)
	{
		t1=t2=0;
		getchar();
		for (i=0;i<N;i++)
		if(scanf("%c",&c),c=='*')
		{
				t1+=1<<i;
				t2+=1<<(N-i-1);
		}
		scanf("%d",&M);
		if (t1)
		{
		while (!(t1 & 1))
		{
			t1>>=1;
			N--;
		}
		while (!(t2 & 1))
		{ 
			t2>>=1;
			N--;
		}
		//pri(t1);
		//pri(t2);
		
		na=(1<<M)-1;
		//pri(na);
		if (t1)
		
			ANS=M;
			find(0,0);
			printf("%d\n",ANS);
		}
		else
			printf("-1\n");
	}
	
}
int find(int n,int k)//Nails,deep,lowbit
{
	n&=na;
	//printf("k=%d ",k);pri(n);getchar();
	if (n==na && k<ANS)ANS=k;
	if (k>=ANS)return 0;
	int l=lowbit(~n);
	for (int i=l;i;i>>=1)
	{
		//printf("i=%d ",i);pri(~na);
		if (l&(t1*i))find(n | (t1*i),k+1);
		//if (((n | (t1*i))&na)!=((n | (t2*i))&na))
		if (l&(t2*i))find(n | (t2*i),k+1);
	}
}
/*
inline void pri(int n)
{
	int b=M;
	if (N>b)b=N;
	for (int i=0;i<b;i++)
		if ((n & (1<<i))!=0)
			printf("1");
		else 
			printf("0");
	printf(" %d\n",n);
}*/
