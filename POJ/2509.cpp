#include <cstdio>
int N,K,ANS;
int main()
{
	int t;
	while (scanf("%d%d",&N,&K)!=EOF)
	{
		ANS=0;
		while (N>=K)
		{
			t=N/K;
			ANS+=t*K;
			N%=K;
			N+=t;
		}
		ANS+=N;
		printf("%d\n",ANS);
	}
}