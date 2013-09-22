#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Trie
{
	Trie *next[26];
	int index,num;
}ns[20009];
char words[1009][22];
int R,word;
inline void build(char *w,int index)
{
	Trie *node=&ns[1];
	while (*w)
	{
		if (!node->next[*w-'a'])
			node->next[*w-'a']=&ns[++R];
		node=node->next[*w-'a'];
		node->num++;
		w++;
	}
	node->index=index;
}
int find(char *w)
{
	int ans=0;
	Trie *node=&ns[1];
	do
	{
		node=node->next[*w-'a'];
		w++;
		ans++;
	}while(node->num>1 && *w);
	return ans;
}
int main()
{
	memset(ns,0,sizeof(ns));
	char str[22];
	R=1;
	word=0;
	while (scanf("%s",words[++word])!=EOF)
		build(words[word],word);
	//printf("word=%4d\n",word);
	for(int i=1;i<word;i++)
	{
		printf("%s ",words[i]);
		words[i][find(words[i])]='\0';
		puts(words[i]);
	}
	return 0;
}