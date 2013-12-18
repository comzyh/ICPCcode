#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Snow
{
	int l[6];
	inline int operator < (const Snow &s)const
	{
		for (int i=0;i<6;i++)
			if(l[i]!=s.l[i])
				return l[i]<s.l[i];
		return 0;
	}
	inline int operator == (const Snow &s)const
	{
		for (int i=0;i<6;i++)
			if (l[i]!=s.l[i])
				return 0;
		return 1;
	}
	inline void ref()
	{
		for (int i=0;i<3;i++)
			swap(l[i],l[5-i]);
	}
	inline void shl()
	{
		for (int i=0;i<5;i++)
			swap(l[i],l[i+1]);
	}
	inline Snow min()
	{
		Snow s,ans;
		ans=s=*this;
		for (int i=1;i<6;i++)
		{
			s.shl();
			if (s<ans)
				ans=s;
		}
		s.ref();
		if (s<ans)
			ans=s;
		for (int i=1;i<6;i++)
		{
			s.shl();
			if (s<ans)
				ans=s;
		}
		return ans;
	}
	inline void pri()
	{
		for (int i=0;i<6;i++)
			printf("%4d ",l[i]);
		printf("\n");
	}

}ss[200009];
int N,R;
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		Snow tmp;
		R=0;
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<6;j++)
				scanf("%d",&tmp.l[j]);
			//tmp.pri();
			ss[i]=tmp.min();
		}
		sort(ss,ss+N);
		int ans=0;
		// for (int i=0;i<N;i++)
		// 	ss[i].pri();
		for (int i=1;i<N;i++)
			ans|=ss[i]==ss[i-1];
		if (ans)
			printf("Twin snowflakes found.\n");
		else
			printf("No two snowflakes are alike.\n");
	}
	return 0;
}