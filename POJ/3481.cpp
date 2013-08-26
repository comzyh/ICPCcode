#include <cstdio>
#include <cstring>
const int MAX=1000095;
struct node
{
	int key,value;
	int s,left,right;
	void init(int k,int v)
	{
		s=1;
		left=right=0;
		key=k;
		value=v;
	}
}SBT[MAX];
int tail;
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
	SBT[t].left=SBT[k].right;//错误
	SBT[k].right=t;//错误
	SBT[k].s=SBT[t].s;
	SBT[t].s=SBT[SBT[t].left].s+SBT[SBT[t].right].s+1;
	return t=k;
}
int maintain(int &t,int flag)
{
	if (flag==0)
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
			left_rotate(t);//错误
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
int find_max_del(int &t)
{
	if (SBT[t].right)
		return find_max_del(SBT[t].right);
	int ans=SBT[t].value;
	t=SBT[t].left;
	return ans;
}
int find_min_del(int &t)
{
	if (SBT[t].left)
		return find_min_del(SBT[t].left);
	int ans=SBT[t].value;
	t=SBT[t].right;
	return ans;
}
int insert(int &t,int key,int value)
{
	//printf("t=%4d,value=%4d,key=%4d\n",t,value,key);
	if (t==0)
	{
		t=++tail;
		SBT[t].init(key,value);
		return t;
	}
	else
	{	
		SBT[t].s++;
		if (key<SBT[t].key)
			insert(SBT[t].left,key,value);
		else
			insert(SBT[t].right,key,value);
		//printf("maintain\n");
		//maintain(t,key>=SBT[t].key);
		return t;
	}
}
int head;
int main()
{
	int req,K,P;
	head=0;
	tail=0;
	SBT[0].init(0,0);
	SBT[0].s=0;
	while (scanf("%d",&req),req)
	switch(req)
	{
		case 1:
			scanf("%d%d",&K,&P);
			insert(head,P,K);
			break;
		case 2:
			printf("%d\n",find_max_del(head));
			break;
		case 3:
			printf("%d\n",find_min_del(head));
			break;
	}
}
