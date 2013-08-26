#include <cstdio>
int N,B,ANS;
int H[30];
void DFS(int k,int sum)
{
	//printf("sum=%d\n",sum);
	if (sum>=B)
	{
		if (sum<ANS)
			ANS=sum;
		return ;
	}
	if (k>N)
		return ;
	DFS(k+1,sum+H[k]);
	DFS(k+1,sum);
}
int main()
{
	scanf("%d%d",&N,&B);
	for (int i=1;i<=N;i++)
		scanf("%d",&H[i]);
	ANS=0x7fffffff;
	DFS(1,0);
	printf("%d\n",ANS-B);
}