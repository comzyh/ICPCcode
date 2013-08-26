#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,M;
int	num[100001];
int diving[100001];
void QuickSelect(int arr[],int b,int e,int k)
{
	int i=b,j=e,mid=arr[(b+e)>>1];
	while (i<j)
	{
		while (arr[i]<mid)i++;
		while (arr[j]>mid)j--;
		if (i<=j)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	if (b<j && k<=j)QuickSelect(arr,b,j,k);
	if (i<e && k>=i)QuickSelect(arr,i,e,k);
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		int i,j,b,e,k;
		for (i=1;i<=N;i++)
			scanf("%d",&num[i]);
		for (i=1;i<=M;i++)
		{
			scanf("%d%d%d",&b,&e,&k);
			for (j=b;j<=e;j++)
				diving[j]=num[j];
			QuickSelect(diving,b,e,k+b-1);
			printf("%d\n",diving[k+b-1]);
		}
	}
	return 0;
}