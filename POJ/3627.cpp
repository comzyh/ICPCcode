#include <cstdio>
#include <iostream>
int N,B;
int H[20001],T;
void qsort(int b,int e);
int main()
{
	int i,sum=0;
	scanf("%d%d",&N,&B);
	for (i=1;i<=N;i++)
		scanf("%d",&H[i]);
	qsort(1,N);	
	for (i=1;sum<B;i++)
		sum+=H[i];
	printf("%d",i-1);
}
void qsort(int b,int e)
{
	int i=b,j=e,k=H[(b+e)>>1];
	while (i<j)
	{
		while (H[i]>k)i++;
		while (H[j]<k)j--;
		if (i<=j)
		{
			std::swap(H[i],H[j]);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}