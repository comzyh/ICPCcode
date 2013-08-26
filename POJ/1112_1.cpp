#include <cstdio>
int N;
int main()
{
	int i,b,e,last;
	
	while (scanf("%d",&N)!=EOF){
	int sum=0;
	switch (N)
	{
		case 5:
			printf("2 3\n");break;
		case 6:
			printf("2 4\n");break;
		case 7:
			printf("3 4\n");break;
		case 8:
			printf("3 5\n");break;
		default:
			for (i=3;N-sum>=2*i+1;i++)
				sum+=i;
			e=i-1;
			if (N-sum-2>i-1)
			{
				b=2;
				last=N-sum-2;				
			}
			else 
			{
				b=3;
				last=N-sum;
			}
			for (i=b;i<=e;i++)
				printf("%d ",i);
			printf("%d\n",last);
			break;
	}
	}
}
