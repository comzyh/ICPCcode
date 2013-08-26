#include <cstdio>
#include <cstring>
char str[300],key[300],ans[300];
int main()
{
	int i,j,l1,l2;
	while (gets(str)!=NULL)
	{
		l1=strlen(str);
		while (gets(key),strcmp(key,"END")!=0)
		{
			if (strcmp(key,"NULL")==0)
			{
				printf("0 NULL\n");
				continue;
			}
			l2=strlen(key);
			for (i=0;i<l1;i++)
			{
				for (j=0;j<l2;j++)
					if (str[i+j]!=key[j])
						break;
				if (j==l2)
				{
					printf("%d ",i);
					for (j=0;j<i;j++)
						printf("%c",str[j]);
					if (i==0)
						printf("NULL");
					printf("\n");
					break;
				}
				
			}
			if (i==l1)
			{
				//printf("0 NULL\n");
				printf("%d %s\n",l1,str);
			}
		}
	}
}