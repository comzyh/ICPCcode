#include <cstdio>
#include <cstring>
#include <iostream>
int T;
struct bignum
{
	int num[100000],l;
	void init()
	{
		memset(num,0,sizeof(num));
	}
	bignum operator +(bignum &n)
	{
		int i,j,ll=l;
		if (n.l>ll)ll=n.l;
		bignum ans;
		ans.init();
		for (i=1;(i<=ll);i++)
		{
			ans[i]+=(num[i]+n[i]);
			if (ans[i]>=10)
			{
				ans[i+1]++;
				ans[i]-=10;
			}else if (ans[i]<=-10)
			{
				ans[i+1]--;
				ans[i]+=10;
			}
		}
		ll=i+1;
		while(ans[i]==0 && i>=1)i--;
		
		if (ans[i]<0)
		{
			for (i=i;i>=1;i--)
				if (ans[i-1]>0)
				{
					ans[i]++;
					if (ans[i]>0)
					{
						j=i;
						while (ans[j]>0&& (j<ll+10) )
						{
							ans[j]-=10;
							ans[++j]++;
						}
					}
					ans[i-1]-=10;
				}
		}
		else
		{
			for (i=1;i<=ll;i++)
				if (ans[i]<0)
				{
					ans[i]+=10;
					ans[i+1]--;
				}
		}
		
		i=ll+1;
		while(ans[i]==0 && i>=1)i--;
		//printf("l=%4d\n",i);
		ans.l=i;
		return ans;
	}
	int &operator [](int k)
	{
		return num[k];
	}
	void read()
	{
		init();
		char c;
		int sign=1,i=0;
		while (scanf("%c",&c),(c==10)||(c==' '));
		while (c=='+')
		{
			sign=1;
			scanf("%c",&c);
		}
		while (c=='-')
		{
			sign=-1;
			scanf("%c",&c);
		}
		while (c==' ')scanf("%c",&c);
		while (c>='0' && c<='9')
		{
			num[++i]=sign*(c-'0');
			if (scanf("%c",&c)==EOF)//数据最后可能没有字符
				break;
		}
		l=i;
		for (i=1;i+i<=l;i++)
			std::swap(num[i],num[l-i+1]);
	}
	void pri()
	{
		if (l==0)
		{
			printf("0");
			return ;
		}
		if (num[l]<0)
		{
			printf("-");
			for (int i=l;i>=1;i--)
				printf("%d",-num[i]);
		}
		else
			for (int i=l;i>=1;i--)
				printf("%d",num[i]);
	}
}A,B;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		A.read();
		B.read();
		(A+B).pri();
		printf("\n");
	}
}
