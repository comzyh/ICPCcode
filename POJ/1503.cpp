#include <cstdio>
#include <cstring>
#include <iostream>

struct big_num
{
	int num[120],l;
	inline void init()
	{
		l=0;
		memset(num,0,sizeof(num));
	}
	inline int read()
	{
		char c;
		init();
		while (scanf("%c",&c),!(c>='0' && c<='9'));
		while (c>='0' && c<='9')
		{
			num[++l]=c-'0';
			scanf("%c",&c);
		}
		for (int i=1;i+i<=l;i++)
			std::swap(num[i],num[l-i+1]);
		while (num[l]==0 && l>0)l--;
		return l;
	}
	big_num &operator +=(big_num &n)
	{
		int i;
		for (i=1;i<=l || i<=n.l || num[i]!=0;i++)
		{
			num[i]+=n.num[i];
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
		l=i-1;
		return *this;
	}
	void print()
	{
		for (int i=l;i>=1;i--)
			printf("%d",num[i]);
	}
}sum,a;
int main()
{
	sum.init();
	while (a.read())
		sum+=a;
	sum.print();
	return 0;
}
