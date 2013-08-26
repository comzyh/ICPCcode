#include <cstdio>
int N,K;
double W;
int main()
{
	while (scanf("%d%lf%d",&N,&W,&K)!=EOF)
	{
		N+=2;
		int NMK=N%K;
		printf("%.2lf\n",W*(((N-NMK)*(K-1)/K) + NMK)/(double)2);
	}
}
