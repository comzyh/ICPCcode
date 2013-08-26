#include <cstdio>
#include <cstring>
#include <iostream>
struct T_word
{
	int app[26];
	char word[150];
	void get()
	{
		gets(word);
		memset(app,0,sizeof(app));
		for (int i=0;word[i]!='\0';i++)
			app[word[i]-'a']++;
	}
	int notend()
	{
		return strcmp(word,"XXXXXX");
	}
	int cmp(const T_word &w)
	{
		for (int i=0;i<26;i++)
			if(w.app[i]!=app[i])
				return 0;
		puts(word);
		return 1;
	}
}words[101];
int N;
void qsort(int b,int e);
int main()
{
	int i;
	N=1;
	while (words[N].get(),words[N].notend())
		N++;
	N--;
	qsort(1,N);
	T_word w;
	while (w.get(),w.notend())
	{
		int ans=0;
		for (i=1;i<=N;i++)
			ans|=words[i].cmp(w);
		if (!ans)
			puts("NOT A VALID WORD");
		puts("******");
	}
}
void qsort(int b,int e)
{
	int i=b,j=e;
	T_word k=words[(b+e)>>1];
	while (i<j)
	{
		while (strcmp(words[i].word,k.word)<0)i++;
		while (strcmp(words[j].word,k.word)>0)j--;
		if (i<=j)
		{
			std::swap(words[i],words[j]);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}