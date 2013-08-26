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
	di[1]=1;
	for (k=2;k<=l2+1;k++)
	{
		//用[1..k]匹配[1..k]
		j=0;
		for (i=di[k-1];i<=k;)
		{
			if (j<1)j=1;
			//两个指针,一个是j对应关键字,一个是i+j源,但是只匹配一个
			for (;i+j<k;j++)
				if (str2[i+j]!=str2[j])
					break;
			if (j+i>=k)
			{
				di[k]=i;
				//j=0;
				break;
			}	
			i+=di[j];//j<k di[j]一定存在
			j-=di[j];
		}
	}
	//匹配
	match2(str1,str2);
	printf("%d\n",ANS);
	}
	return 0;
}

