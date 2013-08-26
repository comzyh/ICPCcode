#include <cstdio>
#include <cmath>
//#define 
const float pi=3.141592654;
int T;
int main()
{
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		float R,r;
		int n;
		scanf("%f%d",&R,&n);
		float theta=2*pi/n;
		if (n==1)
			r=R;
		if (n==2)
			r=R/2;
		if (n>2)
			r=R/((sin((pi-theta)/2)/sin(theta))*2.0+1.0);
		printf("Scenario #%d:\n%.3f\n\n",i,r);
	}
}