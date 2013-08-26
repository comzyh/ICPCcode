#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>=y)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}
