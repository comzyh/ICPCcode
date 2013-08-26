#include <cstdio>
int main()
{
	double a;
	while (scanf("%lf",&a),a>0.0)
	{
		double sum=0;
		int i;
		for (i=1;sum+=1.0/(i+1),sum<a;i++);
		printf("%d card(s)\n",i);
	}
	return 0;
}
