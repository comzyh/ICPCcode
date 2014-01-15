#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.1415927;
int TT=0;
int main()
{
	double D,T;
	int R;
	while (scanf("%lf%d%lf",&D,&R,&T),R)
		printf("Trip #%d: %.2lf %.2lf\n",++TT,D*R*pi/12.0/5280.0,D*R*pi/12.0/5280.0/T*3600.0);
	return 0;
}