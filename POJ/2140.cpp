#include <cstdio>
#include <cstring>
int N,NN,ANS;
int main()
{
	int i,j;
	while (scanf("%d",&N)!=EOF)
	{
		NN=N*2;
		ANS=0;
		for (i=NN;i*i>NN;i--)//2mid
			if (NN % i==0 && !(NN/i==2 && i%2==0))
			{
				ANS++;
				printf("i=%d\n",i);
			}
		printf("%d\n",ANS);
	}
}
