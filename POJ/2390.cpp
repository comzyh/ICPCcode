#include <cstdio>
#include <cmath>
double M,R;
int Y;
int main()
{
	scanf("%lf%lf%d",&R,&M,&Y);
	while (Y--)
		M*=(1.0+R/100.0);
	printf("%d",(int)M);
}
