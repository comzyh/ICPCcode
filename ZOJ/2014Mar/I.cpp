#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=200000+100000+9;
struct Node
{
	int lc,rc,value,size,state;
}ns[maxn];
struct Segmet
{
	int l,r,lc,rc,gcd[2],num[2];
}segs[maxn*32];
int N,Q,RT,RS,Root,InTree;
//Size Balanced Tree
inline void Left_Rotate(int &T)
{
	int k=ns[T].rc;
	ns[T].rc=ns[k].lc;
	ns[k].lc=T;
	ns[k].size=ns[T].size;
	ns[k].size=ns[ns[k].lc].size+ns[ns[k].rc].size+1;
	T=k;
}
inline void Right_Rotate(int &T)
{
	int k=ns[T].lc;
	ns[T].lc=ns[k].rc;
	ns[k].rc=T;
	ns[k].size=ns[T].size;
	ns[k].size=ns[ns[k].lc].size+ns[ns[k].rc].size+1;
	T=k;
}
void Mantain(int &T,int left)
{
	if (left)
	{
		if (ns[ns[ns[T].lc].lc].size>ns[ns[T].rc].size)
			Right_Rotate(T);
		else if (ns[ns[ns[T].lc].rc].size>ns[ns[T].rc].size)
		{
			Left_Rotate(ns[T].lc);
			Right_Rotate(T);
		}
		else return ;
	}
	else
	{
		if (ns[ns[ns[T].rc].rc].size>ns[ns[T].lc].size)
			Left_Rotate(T);
		else if (ns[ns[ns[T].rc].lc].size>ns[ns[T].lc].size)
		{
			Right_Rotate(ns[T].rc);
			Left_Rotate(T);
		}
		else return ;
	}
	Mantain(ns[T].lc,1);
	Mantain(ns[T].rc,0);
	Mantain(T,0);
	Mantain(T,1);
}
void InsertT(int &T,int i,int v,int s)
{
	if (T==0)
	{
		T=++RT;
		ns[T].value=v;
		ns[T].state=s;
		ns[T].lc=ns[T].rc=0;
		ns[T].size=1;
		return ;
	}
	ns[T].size++;
	if (i<=ns[ns[T].lc].size)
	{
		InsertT(ns[T].lc,i,v,s);
		Mantain(T,1);
	}
	else
	{
		InsertT(ns[T].rc,i-ns[ns[T].lc].size-1,v,s);
		Mantain(T,0);
	}
}
int &FindT(int &T,int i)
{
	if (i==ns[ns[T].lc].size+1)
		return T;
	if (i<=ns[ns[T].lc].size) 
		return FindT(ns[T].lc,i);
	else
		return FindT(ns[T].rc,i-ns[ns[T].lc].size-1);
}
int RemoveT(int &T,int i)
{
	ns[T].size--;
	if (i==ns[ns[T].lc].size+1)
	{
		int pos=T;
		if (ns[T].lc==0 || ns[T].rc==0)
			T=ns[T].lc+ns[T].rc;
		else
		{
			T=RemoveT(ns[T].lc,ns[T].size);
			ns[T].lc=ns[pos].lc;
		}
		return pos;
	} 	
	if (i<=ns[ns[T].lc].size)
		return RemoveT(ns[T].lc,i);
	else
		return RemoveT(ns[T].rc,i-ns[ns[T].lc].size-1);
}
//Segment Tree
inline int gcd(int a,int b)
{
	if (a<b)swap(a,b);
	if (b==0)return a;
	while (b!=0)
	{
		a=a%b;
		swap(a,b);
	}
	return a;
}
inline void BuildS(int &seg,int l,int r)
{
	if (seg==0)
	{
		seg=++RS;
		Segment &s=segs[seg];
		s.l=l;
		s.r=r;
		s.lc=s.rc=0;
		s.gcd[0]=s.gcd[1]=s.num[0]=s.num[1]=0;
	}
}
void InsertS(int seg,int value,int state)
{
	Segment &s=segs[seg];
	if (s.l==s.r)
	{
		s.gcd[state]=value;
		s.num[state]++;
	}
	else
	{
		int mid=(s.l+s.r)>>1;
		BuildS(s.lc,s.l,mid);
		BuildS(s.rc,mid+1,s.r);
		if (value<=mid)
			InsertS(s.lc,v,s);
		else
			InsertS(s.rc,v,s);
		s.gcd[0]=gcd(segs[s.lc].gcd[0],segs[s.rc].gcd[0])
	}

}
int main()
{
	while (scanf("%d%d",&N,&Q)!=EOF)
	{
		memset(ns,0,sizeof(ns));
		memset(segs,0,sizeof(segs));
		RT=RS=Root=InTree=0;
		segs[1].l=1;segs[1].r=1000000000;
		for (int i=1;i<=N;i++)
		{
			int v,s;
			scanf("%d%d",&v,&s);
			InsertT(Root,InTree+1,v,s);
			InsertS(1,v,s);
		}
		while (Q--)
		{
			char str[5];
			scanf("%s",str);
			switch(str[0])
			{
				case 'Q':
				{
					int l,r,s;
					scanf("%d%d%d",&l,&r,&s);
					int ans=queryS(1,l,r,s);
					if (ans!=0)
						printf("%d\n",ans);
					else
						printf("-1\n");
					break;
				}
				case 'I':
				{
					int i,v,s;
					scanf("%d%d%d",&i,&v,&s);
					InsertT(Root,i+1,v,s);
					InsertS(1,v,s);
					break;
				}
				case 'D':
				{
					int i,pos;
					scanf("%d",&i);
					pos=RemoveT(Root,i);
					RemoveS(1,ns[pos].value,ns[pos].state);
					break;
				}
				case 'R':
				{
					int i,pos;
					scanf("%d",&i);
					pos=FindT(Root,i);
					RemoveS(1,ns[pos].value,ns[pos].state);
					InsertS(1,ns[pos].value,ns[pos].state^1);
					ns[pos].value^=1;
					break;
				}
				case 'M':
				{
					int i,x,pos;
					scanf("%d%d",&i,&x);
					pos=FindT(Root,i);
					RemoveS(1,ns[pos].value,ns[pos].state);
					InsertS(1,x,ns[pos].value);
					ns[pos].value=x;
					break;
				}
			}	
		}
		//Case End
	}
	return 0;
}