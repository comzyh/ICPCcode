#include <cstdio>
int T;
double ANS;
int main()
{
	 int m,n,t,i;
	 scanf("%d",&T);
	 for (i=1;i<=T;i++)
	 {
		scanf("%d%d",&m,&n);
		
		if (n>m)
		{
			t=m;
			m=n;
			n=t;
		}
		m--;
		n--;
		
		ANS=2*(m+n);
		if (n>=2)
		{
			if ((m-2)*(n-1)<(n-2)*(m-1))
				ANS+=(m-2)*(n-1);
			else
				ANS+=(n-2)*(m-1);
		}
		else
		{
			ANS+=(m-2)*(n-1);
		}
		printf("Scenario #%d:\n",i);
		printf("%.2f\n\n",ANS);
	 }
}