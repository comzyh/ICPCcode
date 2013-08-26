#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N;
int tab[10001];
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
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d",&tab[i]);
	QuickSelect(tab,1,N,(1+N)>>1);
	printf("%d\n",tab[(1+N)>>1]);
	return 0;
}