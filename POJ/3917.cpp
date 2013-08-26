#include <cstdio>
#include <cstring>
char str1[80],str2[80];
int main()
{
	int i,l,w1,w2;
	while (gets(str1),gets(str2),str1[0]!='E')
	{
		w1=w2=0;
		l=strlen(str1);
		for (i=0;i<l;i++)
		if (str1[i]!=str2[i])
		switch (((int)str1[i])<<8 | str2[i])
		{
			case 21075:
			case 20562:
			case 21328:
			w1++;
			break;
			default:
			w2++;
		}
		printf("P1: %d\nP2: %d\n",w1,w2);
	}
}
