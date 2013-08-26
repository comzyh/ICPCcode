#include <cstdio>
#include <cstring>
char str[201],t,ans[201];
int used[201],l;
void qsort(int b,int e);
void DFS(int k);
int main()
{
	gets(str);
	l=strlen(str);
	qsort(0,l-1);
	memset(used,0,sizeof(used));
	DFS(0);
}
void DFS(int k)
{
	if (k==l)
	{
		ans[k]='\0';
		puts(ans);
		return ;
	}
	int i=0;
	do
	{
		if (used[i]==0)
		{
		used[i]=1;
		ans[k]=str[i];
		DFS(k+1);
		used[i]=0;
		i++;
		while (str[i]==str[i-1])i++;
		}
		else
		i++;
		
	}while (i<l);
}
void qsort(int b,int e)
{
	int i=b,j=e;
	char k=str[(b+e)>>1];
	while (i<j)
	{
		while (str[i]<k)i++;
		while (str[j]>k)j--;
		if (i<=j)
		{
			t=str[i];
			str[i]=str[j];
			str[j]=t;
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
