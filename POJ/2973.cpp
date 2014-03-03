#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N;
char strs[1000][8];
inline int check(char s1[],char s2[])
{
	static int remain[27];
	memset(remain,0,sizeof(remain));
	for (;*s1;s1++)
		if (*s1!='_')
			remain[*s1-'A']++;
		else
			remain[26]++;
	for (;*s2;s2++)
		if (remain[*s2-'A'])
			remain[*s2-'A']--;
		else
			remain[26]--;
	return remain[26]>=0;
}
int main()
{
	while (scanf("%d",&N),N)
	{
		char target[8];
		for (int i=0;i<N;i++)
			scanf("%s",&strs[i]);
		int ans=0;
		scanf("%s",target);
		for (int i=0;i<N;i++)
			ans+=check(target,strs[i]);
		printf("%d\n",ans);
	}
	return 0;
}