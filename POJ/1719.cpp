#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,C,R;
int ans[1009];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&R,&C);
		int fail=0;
		for (int i=1;i<=C;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(b<a)
				swap(a,b);
			//if (a+1==b)fail=1;
			if (a==1)ans[i]=a;
			if (b==R)ans[i]=b;
			if (a!=1 && b!=R)
				fail=1;
		}
		if (fail)
			printf("NO");
		else
			for (int i=1;i<=R;i++)
				printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
