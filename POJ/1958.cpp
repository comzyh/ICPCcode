#include <cstdio>
#include <iostream>
using namespace std;
int dp3[13],dp4[13];
int main()
{	
	dp4[0]=0;dp4[1]=1;
	for (int i=0;i<=12;i++)
		dp3[i]=(1<<i)-1;
	for (int i=2;i<=12;i++)
	{
		int tans=0x7fffffff;
		for (int k=1;k<=i;k++)
			if (2*dp4[i-k]+dp3[k]<tans)
				tans=2*dp4[i-k]+dp3[k];
		dp4[i]=tans;
	}
	for (int i=1;i<=12;i++)
		printf("%d\n",dp4[i]);
	return 0;
}