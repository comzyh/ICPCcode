//http://hi.baidu.com/absolute8511/item/f32efc0eeec5507dbee97e4a
#include <cstdio>
int N;
int main()
{
	int i,j,m,sum;
	while (scanf("%d",&N)!=EOF)
	{
		sum=0;
		for (i=2;sum+i<=N;i++)
			sum+=i;
		if (N-sum==i-1)//给所有前面的值(共n-1个,n=i-1)+1 还有剩余1
		{
			for (j=3;j<i;j++)
				printf("%d ",j);
			printf("%d\n",N-sum+2);//最后一项要多加一个
		}
		else
		{
			m=i-(N-sum);
			for (j=2;j<m;j++)
				printf("%d ",j);
			for (j=m+1;j<=i;j++)
				printf("%d ",j);
		}
	}
}
