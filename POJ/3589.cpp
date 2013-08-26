#include <cstdio>
#include <cstring>
int T;
char str[20],n1[10],n2[10];
int main()
{
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(str+1);
		int A=0,B=0;
		memset(n1,0,sizeof(n1));
		memset(n2,0,sizeof(n2));
		for (int i=1;i<=4;i++)
		{
			if (str[i]==str[i+5])
				A++;
			n1[str[i]  -'0']++;
			n2[str[i+5]-'0']++;
		}
		for (int i=0;i<=9;i++)
			B+=(n1[i]<n2[i])?n1[i]:n2[i];
		printf("%dA%dB\n",A,B-A);
	}
}
