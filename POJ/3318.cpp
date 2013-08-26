#include <cstdio>
#include <cstring>
struct T_Matrix
{
	int rol,col;
	int num[505][505];
	inline int *operator [](int x)
	{
		return num[x];
	}
	T_Matrix(){}
	T_Matrix (int r,int c)
	{
		init(r,c);
	}
	inline void init(int r,int c)
	{
		rol=r;
		col=c;
		memset(num,0,sizeof(num));
	}
	inline T_Matrix operator *(T_Matrix &t )
	{
		T_Matrix ans(rol,t.col);
		int i,j,k;
		for (i=1;i<=rol;i++)
			for (j=1;j<=t.col;j++)
				for (k=1;k<=col;k++)
					ans[i][j]+=num[i][k]*t[k][j];
		return ans;
	}
	inline int operator ==(T_Matrix &t)
	{
		int i,j;
		for (i=1;i<=rol;i++)
			for (j=1;j<=col;j++)
				if (num[i][j]!=t[i][j])
					return 0;
		return 1;
	}
	inline void read(int rol,int col)
	{
		init(rol,col);
		int i,j;
		for (i=1;i<=rol;i++)
			for (j=1;j<=col;j++)
				scanf("%d",&num[i][j]);
	}
	inline void pri()
	{
		int i,j;
		for (i=1;i<=rol;i++)
		{
			for (j=1;j<=col;j++)
				printf("%4d",num[i][j]);
			printf("\n");
		}
	}
}A,B,C,T;
int main()
{
	int n,i;
	while (scanf("%d",&n)!=EOF)
	{
		T.init(n,1);
		A.read(n,n);
		B.read(n,n);
		C.read(n,n);
		for (i=1;i<=n;i++)
			T[i][1]=(i%499)+1;
		B=B*T;
		A=A*B;
		C=C*T;
		if (A==C)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
