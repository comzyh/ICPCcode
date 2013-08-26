#include <cstdio>
#include <cstring>
const int MASK=0xffff;
const int bxy[16]={0,0,0,0,4,4,4,4,8,8,8,8,12,12,12,12};
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
	int	tab[16][16],empty;
	inline int fill()
	{
		int i,j,filled;
		do
		{
			filled=0;
			for(i=0;i<16;i++)
				for(j=0;j<16;j++)
				if(!tab[i][j])
				{
					int ans=possible(i,j);
					if (count(ans)==1)
					{
						tab[i][j]=ans;
						filled++;
						empty--;
					}
				}
		}while(filled);
	}
	inline int possible(int x,int y)
	{
		int i,j,ans=0;
		for (i=0;i<16;i++)
			ans|=(tab[x][i]|tab[i][y]);
		for (i=bxy[x];i<bxy[x]+4;i++)
			for (j=bxy[y];j<bxy[y]+4;j++)
				ans|=tab[i][j];
		return (ans^MASK);
	}
	inline int read()
	{
		memset(tab,0,sizeof(tab));
		empty=0;
		char str[20];
		for(int i=0;i<16;i++)
		{
			if  (gets(str)!=NULL)
				for(int j=0;j<16;j++)
				{
					if (str[j]!='-')
						tab[i][j]=1<<(str[j]-'A');
					else
						empty++;
				}
			else
				return 0;
		}
		return 1;
	}
	inline void fillat(int x,int y,int s)
	{
		empty--;
		tab[x][y]=s;
	}
	inline void print()
	{
		for (int i=0;i<16;i++)
		{
			for (int j=0;j<16;j++)
			{
				char n;
				//printf("%d\n",tab[i][j]);
				switch(tab[i][j])
				{
					case 0x0001:n='A';break;
					case 0x0002:n='B';break;
					case 0x0004:n='C';break;
					case 0x0008:n='D';break;
					case 0x0010:n='E';break;
					case 0x0020:n='F';break;
					case 0x0040:n='G';break;
					case 0x0080:n='H';break;
					case 0x0100:n='I';break;
					case 0x0200:n='J';break;
					case 0x0400:n='K';break;
					case 0x0800:n='L';break;
					case 0x1000:n='M';break;
					case 0x2000:n='N';break;
					case 0x4000:n='O';break;
					case 0x8000:n='P';break;
					default:n='-';
				}
				printf("%c",n);
			}
			printf("\n");
		}
	}
}Begin,ANS;
int T;
inline int lowbit();
int DFS(State s);
int main()
{
	while(Begin.read())
	{
		printf("ANS:%d\n",DFS(Begin));
		DFS(Begin);
		ANS.print();
	}
}
int DFS(State s)
{
	s.fill();
	if (s.empty==0)
	{
		ANS=s;
		return 1;
	}
	   printf("-----------%d\n",s.empty);
	   s.print();
	   getchar();
	int i,j,x,y,t,max=20;
	for (i=0;i<16;i++)
		for (j=0;j<16;j++)
		if (s.tab[i][j]==0 && (t=count(s.possible(i,j)))<max)
		{
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
