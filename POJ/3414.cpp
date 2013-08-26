#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int P[2],C;
struct T_state
{
	int p[3],pre,ope;
	int fill(T_state &t,int x)
	{
		if (p[x]==P[x])
			return 0;
		t=*this;
		t.ope=0x00|x;
		t.p[x]=P[x];
		return 1;
	}
	int drop(T_state &t,int x)
	{
		if(p[x]==0)
			return 0;
		t=*this;
		t.ope=0x10|x;
		t.p[2]+=p[x];
		t.p[x]=0;
		return t.p[2]<=C;
	}
	int pour(T_state &t,int x)
	{
		if (p[x]==0 || p[x^1]==P[x^1])
			return 0;
		t=*this;
		t.ope=0x100|x;
		if (p[x]>P[x^1]-p[x^1])
		{
			t.p[x]-=P[x^1]-p[x^1];
			t.p[x^1]=P[x^1];
		}
		else
		{
			t.p[x^1]+=p[x];
			t.p[x]=0;
		}
		return 1;
	}
}q[1000000];
int h,r;
void dfs(int x,int deep)
{
	if (x==1)
	{
		printf("%d\n",deep);
		return;
	}
	dfs(q[x].pre,deep+1);
	//printf("x=%6d ",x);
	switch (q[x].ope&0x110)
	{
		case 0x00:
			printf("FILL(%d)\n",(q[x].ope&1)+1);
			break;
		case 0x10:
			printf("DROP(%d)\n",(q[x].ope&1)+1);
			break;
		case 0x100:
			printf("POUR(%d,%d)\n",(q[x].ope&1)+1,((q[x].ope&1)^1)+1);
			break;
	}	
	
}
int main()
{
	scanf("%d%d%d",&P[0],&P[1],&C);
	h=0;r=2;
	q[1].pre=q[1].p[0]=q[1].p[1]=q[1].p[2]=0;
	while (h+1<r)
	{
		h++;
		if (r>=9999999)
			while(1);
		if (h%1000==0)printf("h=%5d,r=%5d|%4d%4d%4d\n",h,r,q[h].p[0],q[h].p[1],q[h].p[2]);
		if(q[h].fill(q[r],0)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
		if(q[h].fill(q[r],1)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
		if(q[h].drop(q[r],0)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
		if(q[h].drop(q[r],1)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
		if(q[h].pour(q[r],0)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
		if(q[h].pour(q[r],1)){q[r].pre=h;if(q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)break;r++;}
	}
	if (q[r].p[2]==C || q[r].p[1]==C || q[r].p[0]==C)
	{
		dfs(r,0);
	}
	else
	printf("impossible\n");
}//90 100 95