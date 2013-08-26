#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct bignum
{
	int num[100],l;
	bignum &operator *=(int x)
	{
		int i;
		
		for (i=1;i<=l;i++)
			num[i]*=x;
		if (x==0)
			l=0;
		for (i=1;i<=l || num[i]>0;i++)
		{
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
		l=i-1;
		return *this;
	}
	bignum &operator +=(const bignum &x)
	{
		if (x.l>l)
			l=x.l;
		int i;
		for (i=1;i<=l || num[i]>0;i++)
		{
			num[i]+=x.num[i];
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
		l=i-1;
		return *this;
	}
	void init()
	{
		fill(num,num+100,0);
		l=0;
	}
	void init1()
	{
		init();
		num[1]=1;
		l=1;
	}
	void print()
	{
		if (l==0)
			printf("0");
		for (int i=l;i>=1;i--)
			printf("%d",num[i]);
		printf("\n");
	}
};
bignum arrange(int a,int b)
{
	bignum ans;
	ans.init1();
	while (b--)
		ans*=a--;
	return ans;
}
int N,L;
char str[100];
int main()
{
	bignum ANS;
	while (scanf("%d",&N),N)
	{
		ANS.init();
		scanf("%s",str);
		for (int i=0;i<N;i++)
		{
			int m=str[i]-'A';
			for (int j=0;j<i;j++)
				m-=str[i]>str[j];
			bignum t;
			t=arrange(26-i-1,N-i-1);
			//t.print();
			t*=m;
			ANS+=t;
		}
		ANS.print();
		//printf("\n");
	}
}