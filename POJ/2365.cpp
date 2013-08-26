#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const double pi=acos(-1.0);
int N;
struct Point
{
	double x,y;
	double abs(const Point &t)
	{
		return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
	}
}A,B,C;
double R;
int main()
{
	while (scanf("%d%lf",&N,&R)!=EOF)
	{
		double ans=0;
		scanf("%lf%lf",&A.x,&A.y);
		B=A;
		for (int i=2;i<=N;i++)
		{
			scanf("%lf%lf",&C.x,&C.y);
			ans+=C.abs(B);
			B=C;
		}
		if (N>1)
			ans+=B.abs(A);
		printf("%.2f\n",ans+2*pi*R);
	}
	return 0;
}
