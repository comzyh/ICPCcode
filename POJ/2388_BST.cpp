/*
Program:Size Balanced Tree
*/
#include <cstdio>
#include <cstring>
struct node
{
	int s;
	int  left,right;
	int key;
	void pri(){printf("s=%4d,left=%4d,right=%4d,key=%4d\n",s,left,right,key);}
	void init(int k)
	{
		key=k;
		s=1;
		left=right=0;
	}
}SBT[100000];
int tail=0;
inline int free_node()
{return ++tail;}
node &left_rotate(int &t)
{	
	int k=SBT[t].right;
	SBT[t].right=SBT[k].left;
	SBT[k].left=t;
	SBT[k].s=SBT[t].s;
	SBT[t].s=SBT[SBT[t].left].s+SBT[SBT[t].right].s+1;
	t=k;
	return SBT[k];
}
node &right_rotate(int &t)
{
	int k=SBT[t].left;
	SBT[t].left=SBT[k].right;
	SBT[k].right=t;
	SBT[k].s=SBT[t].s;
	SBT[t].s=SBT[t].s=SBT[SBT[t].left].s+SBT[SBT[t].right].s+1;
	t=k;
	return SBT[k];
}
int maintain(int &t,bool flag)
{
	
}
int insert(int &t,int v)
{
	if (t==0)
	{
		t=free_node();
		SBT[t].init(v);
	}
	else
	{
		SBT[t].s++;
		if (v<SBT[t].key)
			insert(SBT[t].left,v);
		else
			insert(SBT[t].right,v);
		maintain(t,v<SBT[t].key);
	}
}
node &getk(const int t,int k)
{
	//printf("t=%4d,",t);SBT[t].pri();getchar();
	if (k<=SBT[SBT[t].left].s  )return getk(SBT[t].left,k);
	if (k>=SBT[SBT[t].left].s+2)return getk(SBT[t].right,k-SBT[SBT[t].left].s-1);
	return SBT[t];
}
int head;
int N;
int main()
{
	int i,j;
	int a,b;
	char c;
	head=0;
	SBT[0].s=0;
	scanf("%d",&N);
	for (i=1;i<=N;i++)
	{
		scanf("%d",&a);
		insert(head,a);
	}
	printf("%d\n",getk(head,(N+1)>>1).key);
}
//11066884	comzyh	2388	Accepted	516K	32MS	G++	1478B	2012-11-30 23:46:26
