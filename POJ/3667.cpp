/*
Program:3667
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
struct segment
{
	int b,e,mid,l;
	int state;//0,1,2=different
	int empty_head,empty_tail,emp;
}seg[200009];
int N,M;
inline int max(int a,int b,int c);
void build(int s,int b,int e);
int update(int s,int b,int e,int flag);
int query(int s,int d);

int main()
{
	int i,j,bb;
	int command,xi,di;
	scanf("%d%d",&N,&M);
	build(1,1,N);
	
	while (M--)
	{
		scanf("%d",&command);
		switch(command)
		{
			case 1:
				scanf("%d",&di);
				if ((bb=query(1,di))!=0)
					update(1,bb,bb+di-1,1);
				printf("%d\n",bb);
				break;
			case 2:
				scanf("%d%d",&xi,&di);
				update(1,xi,xi+di-1,0);
				break;
		}
	}
	return 0;
}
void build(int s,int b,int e)
{
	//sprintf("build %4d,%4d,%4d\n",s,b,e);
	seg[s].b=b;
	seg[s].e=e;
	seg[s].mid=(seg[s].b+seg[s].e)>>1;
	seg[s].emp=seg[s].l=seg[s].empty_head=seg[s].empty_tail=e-b+1;
	seg[s].state=0;
	if (b!=e)
	{
		build(s<<1,b,seg[s].mid);
		build((s<<1)+1,seg[s].mid+1,e);
	}
}
int update(int s,int b,int e,int flag)
{
	//printf("update %4d,%4d,%4d,%4d\n",s,b,e,flag);
	//printf("seg[%4d][%4d,%4d].state=%4d\n",s,seg[s].b,seg[s].e,seg[s].state);
	int mid=seg[s].mid;
	if (b<=seg[s].b && e>=seg[s].e)
	{
		seg[s].state=flag;
		if (flag==0)
			seg[s].emp=seg[s].empty_head=seg[s].empty_tail=seg[s].l;
		else
			seg[s].emp=seg[s].empty_head=seg[s].empty_tail=0;
	}
	else
	{
		int ss=s<<1;
		if (seg[s].state!=2)
		{
			update(ss  ,seg[s].b,seg[s].mid,seg[s].state);
			update(ss+1,seg[s].mid+1,seg[s].e,seg[s].state);
			seg[s].state=2;
		}
		//左更新
		if (e<=seg[s].mid)		
			update(ss,b,e,flag);
		//右更新
		if (b>=mid+1)
			update(ss+1,b,e,flag);
		//两边更新
		if (b<=mid && e>mid)
		{
			update(ss,b,mid,flag);
			update(ss+1,mid+1,e,flag);
		}
		//前空位
		if (seg[ss].state==0)
			seg[s].empty_head=seg[ss].empty_head+seg[ss+1].empty_head;
		else
			seg[s].empty_head=seg[ss].empty_head;
		//后空位
		if (seg[ss+1].state==0)
			seg[s].empty_tail=seg[ss].empty_tail+seg[ss+1].empty_tail;
		else
			seg[s].empty_tail=seg[ss+1].empty_tail;
		
		if (seg[ss].state==seg[ss+1].state)
			seg[s].state=seg[ss].state;
		else
			seg[s].state=2;
		seg[s].emp=max(seg[ss].emp,seg[ss+1].emp,seg[ss].empty_tail+seg[ss+1].empty_head);
		//printf("seg[%4d][%4d,%4d].emp=%4d\n",s,seg[s].b,seg[s].e,seg[s].emp);
	}
	return 0;
}

int query(int s,int d)
{
	//printf("query %4d,%4d,%4d,%4d\n",s,seg[s].b,seg[s].e,seg[s].emp);
	if (seg[s].emp<d)return 0;
	int ans;
	if (ans=query(s<<1,d),ans)
		return ans;
	if (seg[s<<1].empty_tail+seg[(s<<1)+1].empty_head>=d)
		return (seg[s].mid-seg[s<<1].empty_tail+1);
	return query((s<<1)+1,d);
}
inline int max(int a,int b,int c)
{
	int ans=a;
	if (b>ans)ans=b;
	if (c>ans)ans=c;
	return ans;
}
