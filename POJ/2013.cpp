#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,T=0;
char strs[20][40];
int main()
{
	while (scanf("%d",&N),N)
	{
		for (int i=1;i<=N;i++)
			scanf("%s",strs[i]);
		printf("SET %d\n",++T);
		for (int i=1;i<=N;i+=2)
			printf("%s\n",strs[i]);
		for (int i=N-N%2;i>=1;i-=2)
			printf("%s\n",strs[i]);
	}
	return 0;
}