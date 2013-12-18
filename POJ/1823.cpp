#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct segment
{
	int l,r;
	int state;
	int emp,emp_l,emp_r;
	inline int len()
	{
		return r-l+1;
	}
}segs[4*16009];
int N,P;
void build(int seg,int l,int r)
{
	segment &s=segs[seg];
	s.l=l;
	s.r=r;
	s.state=0;
	s.emp=s.emp_l=s.emp_r=r-l+1;
	if (l==r)return ;
	int mid=(l+r)>>1;
	build(seg<<1,l,mid);
	build((seg<<1)+1,mid+1,r);
}
void update(int seg,int l,int r,int st)
{
	segment &s=segs[seg];
	if (l<=s.l && r>=s.r)
		s.state=st;
	else
	{
		int mid=(s.l+s.r)>>1;
		if (s.state!=2)
		{
			update(seg<<1,s.l,mid,s.state);
			update((seg<<1)+1,mid+1,s.r,s.state);
			s.state=2;
		}
		if (l<=mid)
			update(seg<<1,l,r,st);
		if (r>=mid+1)
			update((seg<<1)+1,l,r,st);
	}
	if (s.state!=2)
		s.emp=s.emp_l=s.emp_r=(s.state^1)*s.len();
	else
	{
		s.emp_l=segs[seg<<1].emp_l;
		s.emp_r=segs[(seg<<1)+1].emp_r;
		if (segs[seg<<1].state==0)
			s.emp_l+=segs[(seg<<1)+1].emp_l;
		if (segs[(seg<<1)+1].state==0)
			s.emp_r+=segs[seg<<1].emp_r;
		s.emp=max(segs[seg<<1].emp,segs[(seg<<1)+1].emp);
		s.emp=max(s.emp,segs[seg<<1].emp_r+segs[(seg<<1)+1].emp_l);
		if (s.emp==0)s.state=1;
		if (s.emp==s.len())s.state=0;
	}
}
int main()
{
	while (scanf("%d%d",&N,&P)!=EOF)
	{
		build(1,1,N);
		while(P--)
		{
			int c,b,m;
			scanf("%d",&c);
			if (c==1 || c==2)
			{
				scanf("%d%d",&b,&m);
				update(1,b,b+m-1,2-c);
			}
			if (c==3)
				printf("%d\n",segs[1].emp);
		}
	}
	return 0;
}