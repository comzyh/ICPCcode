#include <cstdio>
#include <cstring>
//#include <iostream>
//using namespace std;
int N,R,Root;
struct node 
{
	int size,left,right,value;
}ns[200009];
inline void Left_Rotate(int &T)
{
	int k=ns[T].right;
	ns[T].right=ns[k].left;
	ns[k].left=T;
	ns[k].size=ns[T].size;
	ns[T].size=ns[ns[T].left].size+ns[ns[T].right].size+1;
	T=k;
}
inline void Right_Rotate(int &T)
{
	int k=ns[T].left;
	ns[T].left=ns[k].right;
	ns[k].right=T;
	ns[k].size=ns[T].size;
	ns[T].size=ns[ns[T].left].size+ns[ns[T].right].size+1;
	T=k;
}
void Maintain(int &T,int flag)
{
	//memset(ns,0,sizeof(ns));
	//flag 0=left 1=right
	if (!flag)
	{
		if (ns[ns[ns[T].left].left].size>ns[ns[T].right].size)
			Right_Rotate(T);
		else
		if (ns[ns[ns[T].left].right].size>ns[ns[T].right].size)
		{
			Left_Rotate(ns[T].left);
			Right_Rotate(T);
		}
		else
		return ;
	}
	else
	{
		if (ns[ns[ns[T].right].right].size>ns[ns[T].left].size)
			Left_Rotate(T);
		else
		if (ns[ns[ns[T].right].left].size>ns[ns[T].left].size)
		{
			Right_Rotate(ns[T].right);
			Left_Rotate(T);
		}
		else
		return ;
	}
	Maintain(ns[T].left,0);
	Maintain(ns[T].right,1);
	Maintain(T,0);
	Maintain(T,1);
}
void Insert(int &T,int pos,int v)
{
	if (T==0)
	{
		T=++R;
		ns[T].left=ns[T].right=0;
		ns[T].size=1;
		ns[T].value=v;
		return ;
	}
	int flag=(pos>=ns[ns[T].left].size+1);
	ns[T].size++;
	if (pos<ns[ns[T].left].size+1)
		Insert(ns[T].left,pos,v);
	else
		Insert(ns[T].right,pos-ns[ns[T].left].size-1,v);
	Maintain(T,flag);
}
void DFS(int T)
{
	if (T==0)
		return;
	DFS(ns[T].left);
	printf("%d ",ns[T].value);
	DFS(ns[T].right);
}
int main()
{
	ns[0].left=ns[0].right=ns[0].size=ns[0].value=0;
	while (scanf("%d",&N)!=EOF)
	{
		memset(ns,0,sizeof(ns));
		int i;
		Root=0;
		R=0;
		for (i=1;i<=N;i++)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			Insert(Root,p,v);
			//DFS(Root);
			//printf("\n");
		}
		DFS(Root);
		printf("\n");
	}
	return 0;
}