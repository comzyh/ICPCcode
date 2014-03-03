#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double esp= 0.00001;
int B,W,C;
inline int le(double a,double b)
{
	return a-b<esp && a-b>-esp;
}
int main()
{
	while (scanf("%d%d%d",&B,&W,&C),B || W || C)
	{
		B*=16;
		W*=16;
		double b=1.0,w=0.0,bw=(double)B/W;
		int i=0;
		while (!le(b/(1.0-b),bw) || !le(w/(1.0-w),bw))
		{
			//if(i>25)break;
			i++;
			w=(b*C+w*W)/(W+C);
			b=(b*(B-C)+w*C)/B;
			//printf("b=%8lf,w=%8lf,bw=%8lf\n",b/(1.0-b),w/(1.0-w),bw);
		}
		printf("%d\n",i);
	}
	return 0;
}