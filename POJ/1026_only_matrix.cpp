#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Matrix
{
	int n,m;
	int tab[202][202];
	inline Matrix operator *(const Matrix &x)
	{
		Matrix ans;
		ans.init(n,x.m);
		for (int i=1;i<=n;i++)
			for (int k=1;k<=m;k++)
				if (tab[i][k])
					for (int j=1;j<=x.m;j++)
						ans[i][j]+=tab[i][k]*x[k][j];
		return ans;
	}
	inline void init(int tn,int tm)
	{
		n=tn;
		m=tm;
		memset(tab,0,sizeof(tab));
	}
	inline int* operator [](int x){return tab[x];}
	inline const int* operator [](int x)const{return tab[x];}
	void print(char * forma)
	{
		printf("n=%4d,m=%4d\n",n,m);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				printf(forma,tab[i][j]);
			printf("\n");
		}
	}

};
Matrix MP(Matrix a,int p)
{
	Matrix ans,f=a;
	ans.init(a.n,a.n);
	for (int i=1;i<=a.n;i++)
		ans[i][i]=1;
	//ans.print("%2d");
	//f.print("%3d");
	while (p)
	{
		if (p&1)
			ans=ans*f;
		f=f*f;
		p>>=1;
	}
	return ans;
}
int N,K;
Matrix A,B;
int main()
{
	while (scanf("%d",&N),N)
	{
		A.init(N,N);
		for (int i=1;i<=N;i++)
		{
			int x;
			scanf("%d",&x);
			A[i][x]=1;
		}
		while (scanf("%d",&K),K)
		{
			char str[300];
			getchar();
			gets(str);
			for (int i=strlen(str);i<N;i++)
				str[i]=' ';
			A=MP(A,K);
			//A.print("%4d");
			B.init(1,N);
			for (int i=1;i<=N;i++)
				B[1][i]=str[i-1];
			B=B*A;
			for (int i=1;i<=N;i++)
				printf("%c",B[1][i]);
			printf("\n");
		}
	}
	return 0;
}
//Time Limit Exceeded
