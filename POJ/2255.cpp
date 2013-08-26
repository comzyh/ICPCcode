#include <cstdio>
#include <cstring>
char F[100],M[100];
int dfs(int f,int b,int e)
{
	int i,j;
	for (i=b;i<=e && M[i]!=F[f];i++);
	if (b!=i)
		f=dfs(f+1,b,i-1);
	if (i!=e)
		f=dfs(f+1,i+1,e);
	printf("%c",M[i]);
	return f;//读到F最后一个元素
}
int main()
{
	while (scanf("%s%s",&F,&M)!=EOF)
	{
		dfs(0,0,strlen(F)-1);
		printf("\n");
	}
	return 0;
}