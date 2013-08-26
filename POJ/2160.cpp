#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Plane
{
	int h,w;
	inline int operator < (const Plane &x)const 
	{
		return h<x.h || (h==x.h && w<x.w);
	}
	void read()
	{
		scanf("%d%d",&h,&w);
		if (h>w)
			swap(h,w);
	}
}ps[7];
int main()
{
	for (int i=1;i<=6;i++)
		ps[i].read();
	sort(ps+1,ps+7);
	int succ=1;
	for (int i=1;i<=5;i+=2)
		succ&=ps[i].h==ps[i+1].h && ps[i].w==ps[i+1].w;
	succ&=(ps[1].h^ps[1].w^ps[3].h^ps[3].w^ps[5].h^ps[5].w)==0;
	if (succ)
		printf("POSSIBLE\n");
	else
		printf("IMPOSSIBLE\n");
	return 0;
}
