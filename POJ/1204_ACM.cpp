#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
struct Trie
{
	Trie *next[26],*fail;
	int val;
}ns[500000];
struct T_ans
{
	int x,y,d;
	inline void set(int sx,int sy,int sd)
	{
		x=sx;
		y=sy;
		d=sd;
	}
}ans[1009];
char str[1009][1009];
char word[1009];
int N,M,W,R;
inline void reverse(char *s)
{
	int i=0,j=0;
	while(s[j])j++;
	j--;
	while (i<j)
	{
		swap(s[i],s[j]);
		i++;
		j--;
	}
}
inline void build(char *w,int x)
{
	Trie *node=&ns[1];
	while(*w)
	{
		if (node->next[*w-'A']==0)
			node->next[*w-'A']=&ns[++R];
		node=node->next[*w-'A'];
		w++;
	}
	node->val=x;
}
void build_ac()
{
	queue<Trie*>q;
	q.push(&ns[1]);
	ns[1].fail=&ns[1];
	while (!q.empty())
	{
		Trie *h=q.front(),*f;
		q.pop();
		for (int i=0;i<26;i++)
			if (h->next[i])
			{
				f=h->fail;
				while (f->next[i]==0 && f!=&ns[1])
					f=f->fail;
				if (f->next[i] && h!=&ns[1])
					h->next[i]->fail=f->next[i];
				else
					h->next[i]->fail=&ns[1];
				q.push(h->next[i]);
			}
	}
}
inline void find(int x,int y,int d)
{
	Trie *node=&ns[1];
	int i=x,j=y;
	while (str[i][j])
	{
		char c=str[i][j];
		while(node->next[c-'A']==0 && node!=&ns[1])
			node=node->fail;
		if (node->next[c-'A'])
			node=node->next[c-'A'];
		for (Trie *f=node;f!=&ns[1];f=f->fail)
			if (f->val)
				ans[f->val].set(i,j,d);
		i+=dx[d];
		j+=dy[d];
	}
}
int main()
{
	while (scanf("%d%d%d",&N,&M,&W)!=EOF)
	{
		memset(str,0,sizeof(str));
		for (int i=0;i<N;i++)
			scanf("%s",str[i]);
		memset(ns,0,sizeof(ns));

		R=1;
		for (int i=1;i<=W;i++)
		{
			scanf("%s",word);
			reverse(word);
			build(word,i);
		}
		//AC
		build_ac();
		memset(ans,0,sizeof(ans));
		for (int i=0;i<N;i++)
		{
			find(i,0,1);
			find(i,0,2);
			find(i,0,3);
			find(i,M-1,5);
			find(i,M-1,6);
			find(i,M-1,7);

		}
		for (int i=0;i<M;i++)
		{
			find(0,i,3);
			find(0,i,4);
			find(0,i,5);
			find(N-1,i,0);
			find(N-1,i,1);
			find(N-1,i,7);
		}
		for (int i=1;i<=W;i++)
			printf("%d %d %c\n",ans[i].x,ans[i].y,(ans[i].d+4)%8+'A');
	}
	return 0;
}