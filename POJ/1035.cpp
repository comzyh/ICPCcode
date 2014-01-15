#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct T_Trie
{
	T_Trie *next[26];
	int val;
	inline T_Trie *init()
	{
		memset(next,0,sizeof(next));
		val=0;
		return this;
	}
}ns[160000];
int R;
char dic[10002][16];
vector<int> ans;
inline void make(char *s,int v)
{
	T_Trie *t=&ns[1];
	while(*s)
	{
		if (!t->next[*s-'a'])
			t->next[*s-'a']=ns[++R].init();
		t=t->next[*s-'a'];
		s++;
	}
	t->val=v;
}
inline int exist(char *s)
{
	T_Trie *t=&ns[1];
	while(*s)
	{
		if (!t->next[*s-'a'])
			return 0;
		t=t->next[*s-'a'];
		s++;
	}
	return t->val>0;
}
inline void find(char *s,T_Trie *t,int oper)
{

	if (*s=='\0')
	{
		if (t->val)
			ans.push_back(t->val);
		//printf("%s\n",dic[t->val]);
		if (oper)
		for (int i=0;i<26;i++)
			if (t->next[i])
				find(s,t->next[i],0);
		return;
	}
	if (t->next[*s-'a'])
		find(s+1,t->next[*s-'a'],oper);
	if (oper)
	{
		//del
		find(s+1,t,0);
		for (int i=0;i<26;i++)
		{
			//replace
			if (t->next[i] && *s!='a'+i)
				find(s+1,t->next[i],0);
			//insert before
			if (t->next[i])
				find(s,t->next[i],0);
		}
	}
}
int main()
{
	int i=0;
	ns[1].init();
	R=1;
	while(scanf("%s",dic[++i]),dic[i][0]!='#')	
		make(dic[i],i);
	i--;
	char tmp[30];
	while(scanf("%s",tmp),tmp[0]!='#')
	{
		if (exist(tmp))
			printf("%s is correct\n",tmp);
		else
		{
			printf("%s:",tmp);
			ans.clear();
			find(tmp,&ns[1],1);
			sort(ans.begin(),ans.end());
			for (int i=0;i<ans.size();i++)
				if(i==0 || (i>0 && ans[i]!=ans[i-1]))
					printf(" %s",dic[ans[i]]);
			printf("\n");
		}
	}
	return 0;
}