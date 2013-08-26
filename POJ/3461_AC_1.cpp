#include <cstdio>
#include <cstring>
char str1[1000005],str2[10005];
int di[10005];
int T,ANS;
void answer(int k)
{
	ANS++;
	//printf("Answer %4d:%-6d\n",ANS,k);
}
int match(char *src,char *key)
{
	int i,j;
	int l1=strlen(src+1),l2=strlen(key+1);
	for (i=1;i<=l1-l2+1;i++)
	{
		for (j=1;src[i+j-1]==key[j] && j<=l2;j++);
		if (j==l2+1)
			answer(i);
		else
			continue;
	}
	return 0;
}
int match2(char *src,char *key)
{
	int i,j;
	int l1=strlen(src+1),l2=strlen(key+1);
	j=1;
	for (i=1;i<=l1-l2+1;)
	{
		if (j<1)j=1;
		for (;j<=l2;j++)
			if (src[i+j-1]!=key[j])
				break;
		if (j>l2)
			answer(i);
		i+=di[j];
		j-=di[j];		
	}
	return 0;
}
int main()
{
	
	int i,j,k,l1,l2;
	scanf("%d",&T);getchar();
	while (T--)
	{
	ANS=0;
	gets(str2+1);
	gets(str1+1);
	
	l1=strlen(str1+1);
	l2=strlen(str2+1);
	di[0]=1;
	for (k=1;k<=l2+1;k++)//di,jj数组下标
          for (i=di[k-1];i<=k;i++)//di
          {
               for (j=1;j+i<k;j++)
                    if (str2[j]!=str2[i+j])break;
               if (j+i>=k)
               {
                    di[k]=i;
					//jj[k]=k-di[k];
					//if (jj[k]<1)jj[k]=1;
                    break;
               }
          }
	//匹配
	match2(str1,str2);
	printf("%d\n",ANS);
	}
	return 0;
}

