#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
struct T_Trie
{
	T_Trie *next[26];
	int val;
	inline void init()
	{
		memset(next,0,sizeof(next));
		val=0;
	}
}ns[2111111];
struct T_ans
{
	int x,y,d;
	inline void set(int x,int y,int d)
	{
		this->x=x;
		this->y=y;
		this->d=d;
	}
}ans[1009];
char str[1009][1009];
int N,M,W,H,R;
inline void build(const char *w,int n)
{
	T_Trie *node=&ns[1];
	while(*w>='A' && *w<='Z')
	{
		if (node->next[*w-'A']==0)
		{
			ns[++R].init();
			node->next[*w-'A']=&ns[R];
		}
		node=node->next[*w-'A'];
		w++;
	}
	node->val=n;
}
inline void find(int i,int j,int d)
{
	T_Trie *node=&ns[1];
	int x=i,y=j;
	while (x<N && x>=0 && y<M && y>=0 && node)
	{
		node=node->next[str[x][y]-'A'];

		if (node && node->val)
			ans[node->val].set(i,j,d);
		x+=dx[d];
		y+=dy[d];
	}
}
int main()
{
	while (scanf("%d%d%d",&N,&M,&W)!=EOF)
	{
		char word[10009];
		for (int i=0;i<N;i++)
			scanf("%s",str[i]);
		
		R=1;
		ns[1].init();
		for (int i=1;i<=W;i++)
		{
			scanf("%s",word);
			build(word,i);
		}
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				for (int k=0;k<8;k++)
					find(i,j,k);
		for (int i=1;i<=W;i++)
			printf("%d %d %c\n",ans[i].x,ans[i].y,ans[i].d+'A');
	}
	return 0;
}