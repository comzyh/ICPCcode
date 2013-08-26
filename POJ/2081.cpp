#include <cstdio>
#include <cstring>
const int Large=5000000;
int K;
int q[500000],exist[Large];
int main()
{
	int i,j;
	q[0]=0;
	memset(exist,0,sizeof(exist));
	exist[0]=1;
	for (i=1;i<=500000;i++)	
	{
		if (q[i-1]-i>0 && !exist[q[i-1]-i])
			q[i]=q[i-1]-i;
		else
			q[i]=q[i-1]+i;
		exist[q[i]]=1;
		
	}
	while (scanf("%d",&K),K!=-1)
		printf("%d\n",q[K]);
}