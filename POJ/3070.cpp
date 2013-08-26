#include <cstdio>
#include <cstring>
const int MOD=10000;
struct Matrix
{
	int tab[3][3];
	Matrix operator *(const Matrix &x)
	{
		Matrix ans;
		memset(ans.tab,0,sizeof(ans.tab));
		for (int i=1;i<=2;i++)
			for (int k=1;k<=2;k++)
				for (int j=1;j<=2;j++)
				{
					ans.tab[i][j]+=tab[i][k]*x.tab[k][j];
					ans.tab[i][j]%=MOD;
				}
		return ans;
	}
}A,ANS;
int N;
int main()
{
	while (scanf("%d",&N),N!=-1)
	{
		A.tab[1][1]=1;
		A.tab[1][2]=1;
		A.tab[2][1]=1;
		A.tab[2][2]=0;
		ANS.tab[1][1]=1;
		ANS.tab[1][2]=0;
		ANS.tab[2][1]=0;
		ANS.tab[2][2]=1;
		while (N)
		{
			if (N&1)
			{
				ANS=ANS*A;
			}
			A=A*A;
			N>>=1;
		}
		printf("%d\n",ANS.tab[1][2]);
	}
}