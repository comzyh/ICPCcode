#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct T_str
{
	char str[11];
	inline int operator <(const T_str &t)const
	{
		return strcmp(str,t.str)<0;
	}
	inline int operator ==(const T_str &t)const
	{
		for (int i=0;str[i] && t.str[i];i++)
			if (str[i]!=t.str[i])
				return 0;
		return 1;
	}
}strs[15];
int T=0;
int main()
{
	while (scanf("%s",&strs[0].str)!=EOF)
	{
		T++;
		int r=0;
		while (scanf("%s",&strs[++r].str),strs[r].str[0]!='9');
		sort(strs,strs+r);
		//for (int i=0;i<r;i++)
		//	puts(strs[i].str);
		while (--r)
			if (strs[r]==strs[r-1])
			{
				printf("Set %d is not immediately decodable\n",T);
				break;
			}
		if (r==0)
			printf("Set %d is immediately decodable\n",T);
	}
	return 0;
}