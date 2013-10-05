//等比数列求和
#include <cstdio>
const int MOD=9901;
int A,B;
int sum(int n,long long k)
{
	n%=MOD;
	int ans=0;
	int power=n;
	int powersum=n;
	int mul=1;
	while (k)
	{
		if (k&1)
		{
			ans+=mul*powersum;	ans%=MOD;
			mul*=power;			mul%=MOD;
		}
		powersum*=(power+1);	powersum%=MOD;
		power*=power;			power%=MOD;
		k>>=1;
	}
	return ans;
}
int factors[200];
int main()
{
	while (scanf("%d%d",&A,&B)!=EOF)
	{
		//factoring
		factors[0]=0;
		for (int i=2;i*i<=A;i++)
			if(A%i==0)
			{
				factors[++factors[0]]=i;
				A/=i;
				i--;
			}
		if (A>1)
			factors[++factors[0]]=A;			
		int ans=1;
		long long tcount=1;
		for (int i=1;i<=factors[0];i++)
		{
			if (factors[i]==factors[i+1] && i+1<=factors[0])
			{
				tcount++;
				continue;
			}
			//printf("factor=%6d,tcount=%6d\n",factors[i],tcount);
			ans*=(1+sum(factors[i]%MOD,tcount*B));
			ans%=MOD;
			tcount=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}