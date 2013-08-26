#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=0x3fffffff;
struct Cow
{
	int num,pos;
}cs[10005];
int N,ANS;
int cd[10005];
inline int cmp_num(const Cow &x,const Cow &y)
{
	return x.num<y.num;
}
int main()
{
	int globemin=MAX;
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&cs[i].num);
			globemin=min(globemin,cs[i].num);
			cs[i].pos=i;
		}
		sort(cs+1,cs+N+1,cmp_num);
		//开始寻找环
		memset(cd,0,sizeof(cd));
		ANS=0;
		for (int i=1;i<=N;i++)
		if (!cd[i] && cs[i].pos!=i)
		{
			int tmin=MAX,now=i,sum=0,tans,n=0;
			do
			{
				cd[now]=1;//遍历过
				n++;//环长度
				if (cs[now].num<tmin)
					tmin=cs[i].num;
				sum+=cs[now].num;
				now=cs[now].pos;
			}while (now!=i);
			tans=min(sum+tmin*(n-2),sum-tmin+globemin*(n-1)+2*(tmin+globemin));
			ANS+=tans;
		}
		printf("%d\n",ANS);
	}
	return 0;
}