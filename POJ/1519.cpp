#include <cstdio>
#include <cstring>
char str[10001];
int ans;
int main()
{
	while (gets(str),(str[0]!='0' || strlen(str)>1))
	{
		ans=0;
		for (int i=0;str[i]!='\0';i++)
			ans+=str[i]-'0';
		printf("%d\n",((ans-1)%9)+1);
	}
}
