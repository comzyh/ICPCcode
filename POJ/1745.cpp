#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,K;
int f[2][101];
inline int MOD(const int &x)
{
	static int a;
	a=x%K;
	if (a>=0)
		return a;
	else
		return K+a;
}
int main()
{
	scanf("%d%d",&N,&K);
	int i,j;
	memset(f,0,sizeof(f));
	//printf("%d--\n",(3-5)%7);
	int k;
	f[0][0]=1;
	for (i=1;i<=N;i++)
	{
		scanf("%d",&k);
		int cur=i&1,pre=cur^1;
		memset(f[cur],0,sizeof(f[cur]));
		for (j=0;j<K;j++)
			if (f[pre][j])
			{
				//printf("--%4d,%4d--\n",(j+k)%K,(j-k)%K);
				f[cur][MOD(j+k)]=1;
				f[cur][MOD(j-k)]=1;
			}
		// for (int ii=0;ii<K;ii++)
			// printf("%2d",f[cur][ii]);
		// printf("\n");
	}
	if (f[N&1][0])
		printf("Divisible\n");
	else
		printf("Not divisible\n");
}
