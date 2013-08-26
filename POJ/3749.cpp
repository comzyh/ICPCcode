#include <cstdio>
#include <cstring>
int main()
{
	char str[300];
	while (gets(str),strcmp("ENDOFINPUT",str)!=0)
	{
		gets(str);
		int l=strlen(str);
		for (int i=0;i<l;i++)
			if (str[i]>='A' && str[i]<='Z')
				str[i]=((str[i]-'A')+21)%26 +'A';
		puts(str);
		gets(str);
	}
}