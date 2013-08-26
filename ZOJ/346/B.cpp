#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
/*
1011111 95
0001100 12
1110110 118
1111100 124
0101101 45
1111001 121
1111011 123
0011100 28
1111111 127
1111101 125
*/
const int nbin[10]={95,12,118,124,45,121,123,28,127,125};
const long long MOD=1000000007;
int T,N;
char str[5][25000];
int num[15000];
long long dp[15000][4];
inline void pribin(int x)
{
	for (int i=6;i>=0;i--)
		printf("%d",(x & (1<<i))>0);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		memset(str,0,sizeof(str));
		getchar();
		gets(str[0]);gets(str[1]);
		gets(str[2]);
		memset(num,0,sizeof(num));
		for (int i=1;i<=N;i++)
		{
			int i2=i<<1;
			num[i]=(str[1][i2-2]=='|') |
				  ((str[2][i2-2]=='|')<<1) |
				  ((str[1][i2]=='|')<<2) |
				  ((str[2][i2]=='|')<<3) |
				  ((str[0][i2-1]=='_')<<4) |
				  ((str[1][i2-1]=='_')<<5) |
				  ((str[2][i2-1]=='_')<<6) ;
		}
		// for (int i=1;i<=N;i++)
		// {
			// pribin(num[i]);
			// printf(" %d\n",num[i]);
		// }
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		// if ((num[1]&0x3)==0x3)
			// dp[0][3]=1;
		for (int i=1;i<=N;i++)
		{
			for (int j=0;j<=9;j++)
				if ((num[i] & nbin[j])==nbin[j])//j能够放在当前位
				{
					//printf("i=%4d,j=%4d\n",i,j);
					int right=(nbin[j]&0xc)>>2;
					for (int k=0;k<=3;k++)
					{
						if (i!=1 && k==0)
							continue ;
						if (dp[i-1][k] /*&& ((nbin[j]&0x3)|k==(num[i]&0x3))*/ &&  (((nbin[j]|k)&0x73)==(num[i]&0x73)) )// 
						{
							//printf("add %4d\n",j);
							dp[i][right]+=dp[i-1][k];
							if (dp[i][right]>MOD)
								dp[i][right]-=MOD;
						}
					}
				}
		}
		// for (int j=0;j<=3;j++)
		// {
			// for (int i=0;i<=N;i++)
				// printf("%4d ",dp[i][j]);
			// printf("--\n");
		// }
		printf("%d\n",dp[N][(num[N]&0xc)>>2]);
	}
	return 0;
}
