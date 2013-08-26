#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct  person
{
	int clay;
	char name[10];
	inline int operator <(const person &t)const
	{
		return clay<t.clay;
	}
}ps[10];
int N;
int main()
{
	while (scanf("%d",&N),N>0)
	{
		for (int i=1;i<=N;i++)
		{
			int x,y,z,m;
			scanf("%d%d%d%s",&x,&y,&z,&ps[i].name);
			ps[i].clay=x*y*z;
		}
		sort(ps+1,ps+N+1);
		printf("%s took clay from %s.\n",ps[N].name,ps[1].name);
	}
	return 0;
}