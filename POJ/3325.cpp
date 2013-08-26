#include <cstdio>
#include <cstring>
int N;
int arr[1002],t;
void qsort(int b,int e);
int main()
{
	int i,sum;
	while (scanf("%d",&N),N)
	{
		for (i=1;i<=N;i++)
			scanf("%d",&arr[i]);
		qsort(1,N);
		sum=0;
		for (i=2;i<N;i++)
			sum+=arr[i];
		printf("%d\n",sum/(N-2));
	}
}
void qsort(int b,int e)
{
	int i=b,j=e,k=arr[(b+e)>>1];
	while (i<j)
	{
		while (arr[i]<k)i++;
		while (arr[j]>k)j--;
		if (i<=j)
		{
			t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
