#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct T_point
{
	int x,y;
	T_point operator -(const T_point &p)const
	{
		return T_point(x-p.x,y-p.y);
	}
	T_point operator +(const T_point &p)const
	{
		return T_point(x+p.x,y+p.y);
	}
	T_point(){}
	T_point(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	int area(const T_point &p)
	{
		return x*p.y-y*p.x;
	}
	T_point &read()
	{
		scanf("%d%d",&x,&y);
		return *this;
	}
};
int T,N;
inline int gcd(int a,int b)
{
	a=max(a,-a);
	b=max(b,-b);
	if (a<b)
		swap(a,b);
	while (b!=0)
	{
		a=a%b;
		swap(a,b);
	}
	//printf("a=%d\n",a);
	return a;
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		T_point pre=T_point(0,0),now;
		
		scanf("%d",&N);
		int I=0,E=N,A=0;
		for (int i=1;i<=N;i++)
		{
			now.read();
			E+=gcd(now.x,now.y)-1;
			now=now+pre;
			A+=pre.area(now);
			pre=now;
		}
		//A=I+E/2-1;
		//I=A-E/2+1;
		I=(double)A/2-(double)E/2+1.0;
		printf("Scenario #%d:\n%d %d %.1f\n\n",TT,I,E,A/2.0);
	}
	return 0;
}