#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct subt
{
	char str[3005];
	subt(){}
	void init(char *tstr,int b,int e)
	{
		int i,j=0;
		for (i=b;i<=e;i++)
			str[j++]=tstr[i];
		str[j]='\0';
	}
	inline int operator < (const subt &x)const
	{
		return strcmp(str,x.str)<0;
	}
}strs[3005];
char str1[3005],str2[3005];
int N;
void ssort(char *str,int b,int e,int top)
{
	//printf("b=%4d,e=%4d,top=%4d\n",b,e,top);
	int r=top,i,j;
	i=b;j=b;
	while (i<e)
	{
		int sum=0;
		//puts(str);
		do
		{
			if (str[j++]=='0')
				sum++;
			else
				sum--;
		}while (sum!=0);
		if (j-1-i>1)
			ssort(str,i+1,j-2,r);
		strs[++r].init(str,i,j-1);
		i=j;
	}
	sort(strs+top+1,strs+r+1);
	//puts("puts");
	//puts((strs+top+2)->str);
	//puts((strs+r+1)->str);
	int p=b;
	//printf("b=%4d,e=%4d\n",b,e);
	for (i=top+1;i<=r;i++)
	{
		for (j=0;strs[i].str[j];j++)
			str[p++]=strs[i].str[j];
		//puts(strs[i].str);
	}
}

int main()
{
	scanf("%d",&N);
	getchar();
	while (N--)
	{
		gets(str1);
		gets(str2);
		ssort(str1,0,strlen(str1)-1,0);
		//puts(str1);
		ssort(str2,0,strlen(str2)-1,0);
		//puts(str2);
		//printf("putsed\n");
		if (strcmp(str1,str2)==0)
			puts("same");
		else
			puts("different");
	}
	return 0;
}
