#include <cstdio>
#include <cstring>
int MAX=1000000;
int NotPrime[1000005];
int A,D,N;
int main()
{
	int i,j;
	memset(NotPrime,0,sizeof(NotPrime));
	NotPrime[1]=1;
	for (i=2;i<=MAX;i++)
		if (!NotPrime[i])
			for (j=i+i;j<=MAX;j+=i)
				NotPrime[j]=1;
	while (scanf("%d%d%d",&A,&D,&N),A && D && N)
	{
		for (i=A;N>0;i+=D)
			if (!NotPrime[i])
				N--;
		printf("%d\n",i-D);
		
	}
}