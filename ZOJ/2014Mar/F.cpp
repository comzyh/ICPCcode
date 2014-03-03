#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int N;
struct Point
{
	double x,y;
}ps[509];
inline double height(Point &A,Point &B,Point &C)
{
	return 	abs((B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x))
			/
			sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
			scanf("%lf%lf",&ps[i].x,&ps[i].y);
		double ans=0.0;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				for (int k=1;k<=N;k++)
					if (i!=j && j!=k && i!=k)
						ans=max(ans,height(ps[i],ps[j],ps[k]));
		printf("%.7lf\n",ans);
	}
	return 0;
}