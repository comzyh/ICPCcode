#include <cstdio>
#include <cstring>
int N,A;
char str[100];
int main()
{
	scanf("%d",&N);
	getchar();
	int i,j,k;
	while (N--)
	{
		gets(str);
		j=0;
		k=4;
		while (k--)
		{
			A=0;
			for (i=0;i<8;i++)
			{
				A<<=1;
				A+=str[j++]-'0';
			}
			if (k==3)
				printf("%d",A);
			else
				printf(".%d",A);
		}
		printf("\n");
	}
}