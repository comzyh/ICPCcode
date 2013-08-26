#include <cstdio>
#include <cstring>
char str[100];
int main()
{
	int i,l;
	while (gets(str) && str[0]!='#')
	{
		l=strlen(str);
		for (i=0;i<l;i++)
		switch (str[i])
		{
			case ' ':
				printf("%%20");break;
			case '!':
				printf("%%21");break;
			case '$':
				printf("%%24");break;
			case '%':
				printf("%%25");break;
			case '(':
				printf("%%28");break;
			case ')':
				printf("%%29");break;
			case '*':
				printf("%%2a");break;
			default:
				printf("%c",str[i]);
		}
		printf("\n");
	}
}
/*
" " (space)	%20
"!" (exclamation point)	%21
"$" (dollar sign)	%24
"%" (percent sign)	%25
"(" (left parenthesis)	%28
")" (right parenthesis)	%29
"*" (asterisk)	%2a
*/
