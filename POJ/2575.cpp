#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dif[3001];
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		int a,b,j;
		scanf("%d",&a);
		for (int i=2;i<=N;i++)
		{
			scanf("%d",&b);
			dif[i]=max(a-b,b-a);
			a=b;
		}
		sort(dif+2,dif+N+1);
		j=dif[2]==1 || N<2;
		for (int i=2;i<N;i++)
			j&=dif[i]==dif[i+1]-1;
		printf("%s\n",j?"Jolly":"Not jolly");
	}
	return 0;
}