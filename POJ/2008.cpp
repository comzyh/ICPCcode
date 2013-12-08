#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int N,A,B,C,ANS;
struct point
{
	int x,y;
	inline int F()const
	{
		return A*x+B*y;
	}
}cs[1009];
struct pnode:point//inherit
{
	pnode *next,*pre;
	int index;
	inline pnode operator =(const point &p)
	{
		x=p.x;
		y=p.y;
		next=pre=NULL;
		index=0;
	}
	inline void del()
	{
		if (pre!=NULL)
			pre->next=next;
		if (next!=NULL)
			next->pre=pre;
	}
}ns[1009],*sorty[1009];
inline int cmpx(const point &a,const point &b)
{
	return a.x<b.x;
}
inline int cmpy(const point &a,const point &b)
{
	return a.y<b.y;
}
inline int cmpF(const point &a,const point &b)
{
	return a.F()<b.F();
}
int main()
{
	while (scanf("%d%d%d%d",&N,&A,&B,&C)!=EOF)
	{
		ANS=0;
		for (int i=1;i<=N;i++)
			scanf("%d%d",&cs[i].x,&cs[i].y);
		sort(cs+1,cs+N+1,cmpx);//sort by x
		for (int b=1;b<=N;b++)
		{
			while (b+1<=N && cs[b].x==cs[b+1].x)
				b++;
			int R=0;
			for (int i=1;i<=N;i++)
				if (cs[i].x>=cs[b].x)
					ns[++R]=cs[i];
			printf("R=%d\n",R);
			sort(ns+1,ns+R+1,cmpy);
			for (int i=1;i<=R;i++)
				ns[i].index=i;
			sort(ns+1,ns+R+1,cmpF);
			//list
			for (int i=1;i<=R;i++)
			{
				//if (i-1>=1)
					ns[i].pre=&ns[i-1];
				if (i+1<=R)
					ns[i].next=&ns[i+1];
				sorty[ns[i].index]=&ns[i];
			}
			ns[0].next=&ns[1];
			//
			int minx=cs[b].x;
			int miny=sorty[1]->y;
			pnode *last=&ns[1];
			int length=1;
			//printf("begin b(%4d,%4d)\n",cs[b].x,cs[b].y);
			for (int i=1;i<=R;i++)
			{
				while(last->next!=NULL && last->next->F()-(A*minx+B*sorty[i]->y)<=C)
				{
					last=last->next;
					length++;
				}
				//printf("len=%4d,minx=%4d,miny=%4d,last(%4d,%4d)\n",length,minx,sorty[i]->y,last->x,last->y);
				ANS=max(ANS,length);
					sorty[i]->del();
				length--;
				//printf("(%4d,%4d)\n",sorty[i]->x,sorty[i]->y);
			}
			printf("ANS=%d\n",ANS);
		}
		printf("%d\n",ANS);	
	}
	return 0;
}