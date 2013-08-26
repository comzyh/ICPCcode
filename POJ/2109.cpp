#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct T_bignum
{
	int l,num[2000];
	inline int& operator [](int k){return num[k];}
	inline int operator [](int k)const{return num[k];}
	
	inline T_bignum operator *(const T_bignum &tn)
	{
		T_bignum ans;
		if (l>0 && tn.l>0)ans.l=l+tn.l-1;
		int i,j,k;
		 for (i=1;i<=l;i++)
			for (j=1;j<=tn.l;j++)
			{
				k=i+j-1;
				ans[k]+=num[i]*tn[j];
				ans[k+1]+=ans[k]/10;
				ans[k]%=10;
				if (ans[k+1]>0 && k+1>ans.l)ans.l=k+1;
			}
		while (ans[ans.l]>10)
		{
			ans[ans.l+1]+=ans[ans.l]/10;
			ans[ans.l]%=10;
			ans.l++;
		}
		return ans;
	}
	inline int operator ==(const T_bignum &tn)
	{
		if (l!=tn.l)return 0;
		for (int i=1;i<=l;i++)
			if (num[i]!=tn[i])return 0;
		return 1;
	}
	inline int operator <(const T_bignum &tn)
	{
		if (l<tn.l)return 1;
		if (l>tn.l)return 0;
		for (int i=l;i>=1;i--)
		{
			if (num[i]<tn[i])return 1;
			if (num[i]>tn[i])return 0;
		}
		return 0;
	}
	
	T_bignum()
	{
		memset(num,0,sizeof(num));
		l=0;
	}
	void init()
	{
		memset(num,0,sizeof(num));
		l=0;
	}
	inline void read()
	{
		char c[200];
		
		scanf("%s",c+1);
		init();
		do
		{
			l++;
			num[l]=c[l]-'0';
		}while (c[l+1]>0);
		for (int i=1;i+i<=l;i++)
			swap(num[i],num[l-i+1]);
		while (num[l]==0)l--;
	}
	inline void print()
	{
		for (int i=l;i>=1;i--)
			printf("%d",num[i]);
	}
	inline T_bignum &operator =(int n)
	{
		init();
		while (n>0)
		{
			num[++l]=n%10;
			n/=10;
		}
		return *this;
	}
}p;
inline T_bignum times(int k,int n)
{
	T_bignum ans,tim;
	ans=1;
	tim=k;
	while (n>0)
	{
		if (n & 1)ans=ans*tim;
		n>>=1;
		tim=tim*tim;
	}
	return ans;
}
inline int bin(int n)
{
	int b,e,k;
	T_bignum tt;
	b=1;e=1000000000;k=(b+e)>>1;
	while (b<e)
	{
		tt=times(k,n);
		if (tt<p)b=k;
		else
		{
			if (p<tt)e=k-1;
			else return k;
		}
		k=(b+e+1)>>1;
	}
	return k;
}
int main()
{
	T_bignum a,b;
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		p.read();
		printf("%d\n",bin(n));
	}
}
