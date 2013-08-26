#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const char Target[3][3]={{1,2,3},{4,5,6},{7,8,0}};
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
const char oper[]={'u','d','l','r'};
int op[10000];
inline int abs(int x){return x>0?x:-x;}
struct State
{
	char n[3][3];
	inline int g(int &x,int &y)
	{
		int ans=0;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			{
				if(n[i][j]==0)
				{
					x=i;
					y=j;
				}
				if (n[i][j])
					ans+=abs(i-(n[i][j]-1)/3)+abs(j-(n[i][j]-1)%3);
			}
			return ans;
	}
	//debug
	void pri()
	{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
				printf("%2d",n[i][j]);
			printf("\n");
		}
		int gg,a,b;
		gg=g(a,b);
		printf("g=%4d,%4d,%4d\n",gg,a,b);
	}
};
int dfs(State s,int k,int d)
{
	int x,y;
	static int gg;
	gg=s.g(x,y);
	if (gg>k)
		return 0;
	if (k==0)
		return gg==0;
	//printf("k=%4d,d=%4d\n",k,d);
	//s.pri();
	for (int i=0;i<4;i++)
	if (i!=(d^1) && x+dx[i]<3 && x+dx[i]>=0 && y+dy[i]<3 && y+dy[i]>=0)
	{
		State ss=s;
		swap(ss.n[x][y],ss.n[x+dx[i]][y+dy[i]]);
		op[k]=i;
		if (dfs(ss,k-1,i))
			return 1;
	}
	return 0;
}
int main()
{
	char str[100];
	while (gets(str)!=NULL)
	{
		State b;
		int line[9],lp=0,inv=0,p=0;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			{
				while (str[p]==' ')p++;
				if (str[p]=='x')
					b.n[i][j]=0;
				else
					line[lp++]=b.n[i][j]=str[p]-'0';
				p+=2;
			}
		for (int i=0;i<8;i++)
			for (int j=i+1;j<8;j++)
				if (line[j]<line[i])
					inv++;
		//printf("iverse:%d\n",inv);
		if (inv &1)
			printf("unsolvable\n");
		else
		{
			int ANS=0x3fffffff;
			for (int i=0;ANS==0x3fffffff;i++)
			{
				if (dfs(b,i,5))
					ANS=i;
			}
			for (int i=ANS;i>0;i--)
				printf("%c",oper[op[i]]);
			printf("\n");
		}
	}
	return 0;
}