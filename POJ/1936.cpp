#include <cstdio>
#include <cstring>
char str1[100001],str2[100001];
int main()
{
	int l1,l2,i,j;
	while (scanf("%s %s",&str1,&str2)!=EOF)
	{
		l1=strlen(str1);
		l2=strlen(str2);
		j=0;
		for (i=0;i<l1;i++)
		{
			while (str2[j]!=str1[i] && j<l2)j++;
			if (j==l2)break;
			j++;
		}
		if (i==l1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}