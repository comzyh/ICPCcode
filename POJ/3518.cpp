#include <cstdio>
#include <cstring>
const int MAX=1299709;
int notprime[MAX+10],N;
int main()
{
	int i,j;
	notprime[1]=1;
	for (i=2;i<=MAX;i++)
	if(!notprime[i])
	{
		for (j=i+i;j<=MAX;j+=i)
			notprime[j]=1;
	}
	while(scanf("%d",&N),N)
	{
		i=j=N;
		while(notprime[i])i++;
		while(notprime[j])j--;
		printf("%d\n",i-j);
	}
}
