#include <cstdio>
#include <cstring>
int T;
char s1[200],s2[200];
int main()
{
	int i,j,l1,l2,ans;
	scanf("%d",&T);
	while (T--)
	{
		getchar();
		scanf("%s%s",&s1,&s2);
		l1=strlen(s1);
		l2=strlen(s2);
		j=-1;
		for (i=0;i<l2;i++)
		{
			j++;
			while (s1[j]!=s2[i] && j<l1)j++;
			if (j>=l1)break;
		}
		if (j<l1 && s1[j]==s2[i-1])
		{
			printf("YES\n");
			continue;
		}
		j=l1;
		for (i=0;i<l2;i++)
		{
			j--;
			while (s1[j]!=s2[i] && j>=0)j--;
			if (j<0)break;
			
		}
		if (j>=0 && s1[j]==s2[i-1])
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
}
