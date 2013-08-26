#include <cstdio>
int A,a,B,b,P;
int main()
{
	scanf("%d%d%d%d%d",&A,&a,&B,&b,&P);
	if ((A+B<=P) || (A<=b && B<=P) || (B<=a && A<=P))
		printf("Yes\n");
	else 
		printf("No\n");
}
