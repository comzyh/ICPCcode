#include <cstdio>
#include <cstring>
int node[1005];
int tab[1005][1005];
int DFN[1005],LOW[1005],Time;
int in[1005],stack[1005],top;
int ans[1005],nans;
int B;
inline void addedge(int f,int t);
void tarjan(int x);
int main()
{
	int f,t;
	while (scanf("%d",&f),f)
	{	
		memset(tab,0,sizeof(tab));
		B=f;
		scanf("%d",&t);
		addedge(f,t);
		while (scanf("%d",&f),f)
		{
			sacnf("%d",&t);
			addedge(f,t);
		}
		//
		top=0;
		memset(DFN,0,sizeof(DFN));
		memset(LOW,0,sizeof(LOW));
		memset(in,0,sizeof(in));
		nans=0;
		tarjan(B);
	}
}
inline void addedge(int f,int t)
{
	tab[f][++tab[f][0]]=t;
	tab[t][++tab[t][0]]=f;
}
void tarjan(int x)
{
	DFN[x]=LOW[x]=++Time;
	in[x]=1;
	stack[++top]=x;
	for (int i=1;i<=tab[x][0];i++)
	if (!DFN[tab[x][i]])
	{
		tarjan(tab[x][i]);
		if (LOW[tab[x][i]<LOW[x])
			LOW[x]=LOW[tab[x][i]];
	}
	else
	if(in[tab[x][i]] && DFN[tab[x][i]<LOW[x])
		LOW[x]=DFN[tab[x][i]];
	
}