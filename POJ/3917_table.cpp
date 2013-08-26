#include <cstdio>
#include <cstring>
char str[100];
int main()
{
	while (gets(str)!=NULL)
	{
		printf("%d\n",((int)str[0])<<8 | str[1]);
	}
}
