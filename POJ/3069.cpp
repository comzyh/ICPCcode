#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int R,N;
int arr[1001];
int main()
{
	while (scanf("%d%d",&R,&N),R!=-1 || N!=-1)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&arr[i]);
		sort(arr+1,arr+N+1);
		int ans=0,b=1;
		for (int i=1;i<=N;i++)
			if (i==N || arr[i+1]-arr[b]>R )
			{
				//printf("i=%d,pos: %d\n",i,arr[i]);
				ans++;
				for (b=i;b<=N && arr[b]-arr[i]<=R;b++);
				i=b-1;
			}
		printf("%d\n",ans);
	}
	return 0;
}