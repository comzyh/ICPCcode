#include <cstdio>
int next[1000009];
char str[1000009];
int main()
{
	next[0]=0;
	while (gets(str)!=NULL,str[0]!='.')
	{
		int i,len=0;
		for (i=1;str[i];i++)
		{
			int j=next[i-1];
			while (str[i]!=str[j] &&j!=0)
				j=next[j-1];
			if (str[i]==str[j])
				next[i]=j+1;
			else
				next[i]=0; 
			//printf("%4d ",next[i]);
		}
		len=i;
		if (len%(len-next[len-1])==0)
			printf("%d\n",len/(len-next[len-1]));
		else
			printf("1\n");
	}
	return 0;
}