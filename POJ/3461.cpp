//KMP POJ3461
#include <cstdio>
char str1[10009],str2[1000009];
int next[100009];
int T;
int main()
{
	scanf("%d",&T);
	getchar();
	next[0]=0;
	while (T--)
	{
		gets(str1);
		gets(str2);
		int i,j,len1,ans=0;
		//构建Next
		for (i=1;str1[i];i++)
		{
			j=next[i-1];
			while (str1[i]!=str1[j] && j!=0)
				j=next[j-1];
			if (str1[i]==str1[j])
				next[i]=j+1;
			else
				next[i]=0;
		}
		len1=i;
		j=0;
		//匹配
		for (int i=0;str2[i];i++)
		{
			while (str2[i]!=str1[j] && j!=0)
				j=next[j-1];
			if (str2[i]==str1[j])
				j++;
			if (j==len1)//找到匹配
			{
				ans++;
				j=next[len1-1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}