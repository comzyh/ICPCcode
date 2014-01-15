#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,N;
int main()
{
	int L,A,B;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&L,&N);
		A=0;
		B=0;
		while (N--)
		{
			int x;
			scanf("%d",&x);
			A=max(A,min(x,L-x));
			B=max(B,max(x,L-x));
		}
		printf("%d %d\n",A,B);
	}
	return 0;
}