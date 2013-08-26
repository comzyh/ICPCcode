#include <cstdio>
#include <cstring>
const char dic2[]="       ;    M0,.9 12345678 L -   \\VXSWDFGUHJKNBIO=EARYCQZT'P][";
char str[1000];
int main()
{
	int i,j,l;
	while (gets(str)!=NULL)
	{
		l=strlen(str);
		for (i=0;i<l;i++)
			printf("%c",dic2[str[i]-' ']);
		printf("\n");
	}
}
