#include <cstdio>
#include <cstring>
const int MASK=0x1ff;
const int bxy[9]={0,0,0,3,3,3,6,6,6};
inline int count(int x)
{
	x=(x&0x5555)+((x>>1)&0x5555);
	x=(x&0x3333)+((x>>2)&0x3333);
	x=(x&0x0f0f)+((x>>4)&0x0f0f);
	x=(x&0x00ff)+((x>>8)&0x00ff);
	return x;
}
struct State
{
	int	tab[9][9],empty;
	inline int fill()
	{
		int i,j,filled;
		do
		{
			filled=0;
			for(i=0;i<9;i++)
				for(j=0;j<9;j++)
				if(!tab[i][j])
				{
					int ans=possible(i,j);
					int c=count(ans);
					if (c==1)
					{
						tab[i][j]=ans;
						filled++;
						empty--;
					}
					if (c==0)
						return -1;
				}
		}while(filled);
		return filled;
	}
	inline int possible(int x,int y)
	{
		int i,j,ans=0;
		for (i=0;i<9;i++)
			ans|=(tab[x][i]|tab[i][y]);
		for (i=bxy[x];i<bxy[x]+3;i++)
			for (j=bxy[y];j<bxy[y]+3;j++)
				ans|=tab[i][j];
		return (ans^MASK);
	}
	inline int* operator [](int x)
	{
		return tab[x];
	}
	inline int read()
	{
		memset(tab,0,sizeof(tab));
		empty=0;
		char str[100];
		gets(str);
		if (strcmp(str,"end")==0)
			return 0;
		//printf("\asdfasdfasdfn\n");
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			{
				if (str[i*9+j]!='.')
					tab[i][j]=1<<(str[i*9+j]-'0'-1);
				else
					empty++;
			}
		//print();
		return 1;
	}
	inline void fillat(int x,int y,int s)
	{
		empty--;
		tab[x][y]=s;
	}
	inline void print()
	{
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				int n;
				//printf("%d\n",tab[i][j]);
				switch(tab[i][j])
				{
					case 0x001:n=1;break;
					case 0x002:n=2;break;
					case 0x004:n=3;break;
					case 0x008:n=4;break;
					case 0x010:n=5;break;
					case 0x020:n=6;break;
					case 0x040:n=7;break;
					case 0x080:n=8;break;
					case 0x100:n=9;break;
					default:n=0;
				}
				printf("%d",n);
			}
			
		}
		printf("\n");
	}
}Begin,ANS;
int T;
inline int lowbit();
int DFS(State s);
int main()
{
	int i,j;
	while(Begin.read())
	{

		//printf("ANS:%d\n",DFS(Begin));
		DFS(Begin);
		ANS.print();
	}
}
int DFS(State s)
{
	if (s.fill()==-1)
		return 0;
	if (s.empty==0)
	{
		ANS=s;
		return 1;
	}
	 // printf("-----------%d\n",s.empty);
	 // s.print();
	int i,j,x,y,t,max=10;
	for (i=8;i>=0;i--)
		for (j=8;j>=0;j--)
		if (s.tab[i][j]==0 && (t=count(s.possible(i,j)))<max)
		{
			if (!t)
				return 0;
			max=t;
			x=i;
			y=j;
		}
		int poss=s.possible(x,y);
		while (poss)
		{
			State v=s;
			int lowbit=poss&-poss;
			poss-=lowbit;
			v.fillat(x,y,lowbit);
			if(DFS(v))
				return 1;	
		}
		return 0;
}
