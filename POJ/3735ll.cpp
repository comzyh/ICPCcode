
// Problem: 3735		User: comzyh
// Memory: 896K		Time: 407MS
// Language: C++		Result: Accepted

#include <cstdio>
#include <cstring>
//#include <iostream>
//using namespace std;
struct T_Matrix
{
	int n,m;
	long long tab[102][102];
	inline const long long* operator [](const int x)const
	{
		return tab[x];
	}
	inline long long* operator [](const int x)
	{
		return tab[x];
	}
	inline void init(int _n=0,int _m=0,int I=0)
	{
		n=_n;
		m=_m;
		memset(tab,0,sizeof(tab));
		if (I)
			for (int i=1;i<=n;i++)
				tab[i][i]=I;
	}
	inline T_Matrix operator *(const T_Matrix &x)
	{
		T_Matrix ans;
		ans.init(n,x.m);
		for (int k=1;k<=m;k++)
			for (int j=1;j<=x.m;j++)
				if (x[k][j])
					for (int i=1;i<=n;i++)
						ans[i][j]+=tab[i][k]*x[k][j];
		return ans;
	}
	inline void print(int _n=0,int _m=0)
	{
		if (_n==0)_n=n;
		if (_m==0)_m=m;
		for (int i=1;i<=_n;i++)
		{
			for (int j=1;j<=_m;j++)
				printf("%lld ",tab[i][j]);
			printf("\n");
		}
	}
}B,A,T;
int N,M,K;
inline T_Matrix power(T_Matrix &x,int p)
{
	T_Matrix ans,t;
	ans.init(x.n,x.m,1);
	t=x;
	while (p)
	{
		if (p&1)
			ans=ans*t;
		t=t*t;
		p>>=1;
	}
	return ans;
	
}
int main()
{
	int i,j,k;
	while (scanf("%d%d%d",&N,&M,&K),N || M || K)
	{
		
		int c,a,b;
		A.init(N+1,N+1,1);
		while (K--)
		{
			getchar();
			scanf("%c",&c);
			T.init(N+1,N+1,1);
			switch (c)
			{
				case 'g':
					scanf("%d",&a);
					T[N+1][a]=1;
					// T.print();
					// printf("---------------\n");
					break;
				case 'e':
					scanf("%d",&a);
					T[a][a]=0;
					break;
				case 's':
					scanf("%d%d",&a,&b);
					T[a][a]=T[b][b]=0;
					T[a][b]=T[b][a]=1;
					break;
			}
			A=(A*T);
			// printf("A-------------\n");
			// A.print();
			// printf("-------------A\n");
		}
		B.init(1,N+1);
		B[1][N+1]=1;
		//A.print();
		A=power(A,M);
		(B*A).print(1,N);
	}
}
