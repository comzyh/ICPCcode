#include <cstdio>
#include <cstring>
const int MAX=30001;
struct node
{
	int key;
	int left,right,s;
	void init(int v)
	{
		key=v;
		s=1;
		left=right=0;
	}
}SBT[MAX];
int tail;
inline int free_node(){return ++tail;}
int left_rotate(int &t)
{
	int k=SBT[t].right;
	SBT[t].right=SBT[k].left;
	SBT[k].left=t;
	SBT[k].s=SBT[t].s;
	SBT[t].s=SBT[SBT[t].left].s+SBT[SBT[t].right].s+1;
	return t=k;
}
int right_rotate(int &t)
{
	int k=SBT[t].left;
	SBT[t].left=SBT[k].right;
	SBT[k].right=t;
	SBT[k].s=SBT[t].s;
	SBT[t].s=SBT[SBT[t].left].s+SBT[SBT[t].right].s+1;
	return t=k;
}
int maintain(int &t,int flag)
{
	if (flag==0)//
	{
		if (SBT[SBT[SBT[t].left].left].s>SBT[SBT[t].right].s)
			right_rotate(t);
		else if (SBT[SBT[SBT[t].left].right].s>SBT[SBT[t].right].s)
		{
			left_rotate(SBT[t].left);
			right_rotate(t);
		}
		else return t;
	}
	else
	{
		if (SBT[SBT[SBT[t].right].right].s>SBT[SBT[t].left].s)
			left_rotate(t);
		else if (SBT[SBT[SBT[t].right].left].s>SBT[SBT[t].left].s)
		{
			right_rotate(SBT[t].right);
			left_rotate(t);
		}
		else return t;
	}
	maintain(SBT[t].left,0);
	maintain(SBT[t].right,1);
	maintain(t,0);
	maintain(t,1);
	return t;
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
		maintain(t,v>=SBT[t].key);	
	}
	
	return t;
}
int getkth(int t,int k)
{
	if (k<=SBT[SBT[t].left].s)
		return getkth(SBT[t].left,k);
	if (k>=SBT[SBT[t].left].s+2)
		return getkth(SBT[t].right,k-SBT[SBT[t].left].s-1);
	return SBT[t].key;
}
int II,N,M;
int A[MAX],u[MAX];
int head=0;
void qsort(int b,int e);
int main()
{
	int i,j;
	tail=0;
	II=0;
	head=0;
	
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for (i=1;i<=M;i++)
		scanf("%d",&u[i]);
	//Work
	j=1;
	SBT[0].init(0);
	SBT[0].s=0;
	for (i=1;i<=N;i++)
	{
		insert(head,A[i]);
		while (j<=M && i==u[j])
		{
			printf("%d\n",getkth(head,++II));
			j++;
		}
	}
}

