#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Node
{
	int l,r,s,v;
}ns[150000];
int N,M,R;
int stack[50005],top;
int Root;
inline void left_r(int &T)
{
	int k=ns[T].r;
	ns[T].r=ns[k].l;
	ns[k].l=T;
	ns[k].s=ns[T].s;
	ns[T].s=ns[ns[T].l].s+ns[ns[T].r].s+1;
	T=k;
}
inline void right_r(int &T)
{
	int k=ns[T].l;
	ns[T].l=ns[k].r;
	ns[k].r=T;
	ns[k].s=ns[T].s;
	ns[T].s=ns[ns[T].l].s+ns[ns[T].r].s+1;
	T=k;
}
void Maintain(int &T,int flag)
{
	if (flag==0)
	{
		if (ns[ns[ns[T].l].l].s>ns[ns[T].r].s)
			right_r(T);
		else if (ns[ns[ns[T].l].r].s>ns[ns[T].r].s)
		{
			left_r(ns[T].l);
			right_r(T);
		}
		else return ;

	}
	else
	{
		if (ns[ns[ns[T].r].r].s>ns[ns[T].l].s)
			left_r(T);
		else if (ns[ns[ns[T].r].l].s>ns[ns[T].l].s)
		{
			right_r(ns[T].r);
			left_r(T);
		}
		else return ;
	}
	Maintain(ns[T].l,0);
	Maintain(ns[T].r,0);
	Maintain(T,0);
	Maintain(T,1);
}
void Insert(int &T,int v)
{
	if (T==0)
	{
		T=++R;
		ns[T].l=0;
		ns[T].r=0;
		ns[T].s=1;
		ns[T].v=v;
	}
	else
	{
		ns[T].s++;
		if (v<ns[T].v)
			Insert(ns[T].l,v);
		else
			Insert(ns[T].r,v);
		//Maintain(T,v>ns[T].v);
	}
}
int Less(int T,int v)
{
	int ans=0;
	while (T!=0)
	{
		if (v>ns[T].v)
		{
			ans+=ns[ns[T].l].s+1;
			T=ns[T].r;
		}
		else if (v<ns[T].v)
			T=ns[T].l;
		else
			return -1;
	}
	return ans;
}
int rank(int T,int k)
{
	while (ns[T].s>1)
	{
		if (k<=ns[ns[T].l].s)
			T=ns[T].l;
		else if (k>ns[ns[T].l].s+1)
		{
			k-=ns[ns[T].l].s+1;
			T=ns[T].r;	
		}
		else
			return T;
	}
	return T;
}
int del(int &T,int v)
{
	ns[T].s--;
	if (ns[T].v==v || (ns[T].l==0 && v<ns[T].v) || (ns[T].r==0 && v>ns[T].v))
	{
		int delnum=ns[T].v;
		if (ns[T].l==0 || ns[T].r==0)
			T=ns[T].l+ns[T].r;
		else
			ns[T].v=del(ns[T].l,0x3f3f3f3f);
		return delnum;
	}
	if (v<ns[T].v)return del(ns[T].l,v);
	else return del(ns[T].r,v);
}
void pri(int e)
{
	printf("Root:%4d\n",Root);
	for (int i=1;i<=e;i++)
		printf("node %4d:l=%4d,r=%4d,v=%4d,s=%4d\n",i,ns[i].l,ns[i].r,ns[i].v,ns[i].s);
}
int main()
{
	char s[10];
	scanf("%d%d",&N,&M);
	R=0;
	Root=0;
	Insert(Root,0);
	Insert(Root,N+1);
	top=0;
	while (M--)
	{
		getchar();
		int x,l;
		scanf("%s",s);
		switch(s[0])
		{
			case 'D':
				scanf("%d",&x);
				Insert(Root,x);
				stack[++top]=x;
				break;
			case 'Q':
				scanf("%d",&x);
				l=Less(Root,x);
				//printf("l=%4d\n",l);
				if (l==-1)
					printf("0\n");
				else
				{
					//printf("r%4d l%4d\n",ns[rank(Root,l+1)].v,ns[rank(Root,l)].v);
					//pri(R);
					printf("%d\n",ns[rank(Root,l+1)].v-ns[rank(Root,l)].v-1);
				}
				break;
			case 'R':
				del(Root,stack[top--]);
				break;
		}
	}
	return 0;
}

