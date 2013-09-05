#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> tab[1009];
int DFN[1009],LOW[1009],Time;
int stack[1009],top;
int Belong[1009],Br,degree[1009];
int instack[1009];
void tarjan(int x,int f)
{
	LOW[x]=DFN[x]=++Time;
	stack[++top]=x;
	for (int i=0;i<tab[x].size();i++)
		if (tab[x][i]!=f)
		{
			if (!DFN[tab[x][i]])
				tarjan(tab[x][i],x);	
			LOW[x]=min(LOW[x],LOW[tab[x][i]]);		
		}
	if (LOW[x]==DFN[x])
	{
		Br++;
		int j;
		do
		{
			j=stack[top--];
			Belong[j]=Br;
		}while(j!=x);
	}
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		for (int i=1;i<=N;i++)
			tab[i].clear();
		for (int i=1;i<=M;i++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			tab[f].push_back(t);			
			tab[t].push_back(f);
		}
		memset(DFN,0,sizeof(DFN));
		memset(LOW,0,sizeof(LOW));
		Time=top=Br=0;
		tarjan(1,0);
		memset(degree,0,sizeof(degree));
		for (int i=1;i<=N;i++)
			for (int j=0;j<tab[i].size();j++)
				if (Belong[i]!=Belong[tab[i][j]])
					degree[Belong[i]]++;
		int ans=0;
		for (int i=1;i<=Br;i++)
			ans+=(degree[i]==1);
		printf("%d\n",(ans+1)>>1);
	}
	return 0;
}
