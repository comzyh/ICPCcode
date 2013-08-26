#include<cstdio>
const int MAX=10000;
int self[10009];
inline int generate(int n)
{
	int ans=n;
	while (n>0)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int main()
{
	int i,j,k;
	for (i=1;i<=MAX;i++)
		self[i]=1;
	for (i=1;i<=MAX;i++)
		if (self[i])
		{
			printf("%d\n",i);
			k=i;
			while (k=generate(k),self[k])
				self[k]=0;
		}
	
}