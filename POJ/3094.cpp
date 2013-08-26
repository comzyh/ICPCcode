#include <cstdio>
#include <cstring>
char str[300];
int main()
{
	while (gets(str),str[0]!='#')
	{
		int i,sum=0;
		for (i=0;str[i]!='\0';i++)
			if (str[i]!=' ')
				sum+=(str[i]-'A'+1)*(i+1);
		printf("%d\n",sum);
	}	
}