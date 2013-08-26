#include <cstdio>
#include <cmath>
const double pi=3.14159265358979323846;
int T;
int N,F;
double r[10005],sum;
inline int calc(double x)
{
	int ans=0;
	for (int i=1;i<=N;i++)
		ans+=(int)(r[i]/x);
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&F);
		F++;
		sum=0;
		for (int i=1;i<=N;i++)
		{
			scanf("%lf",&r[i]);
			r[i]*=r[i];
			sum+=r[i];
		}
		double b=0.0,e=sum/F,k;
		while(e-b>0.00001)
		{
			k=(b+e)/2;
			if(calc(k)>=F)
				b=k;
			else
				e=k;
		}
		printf("%.4lf\n",b*pi);
	}
	
}
