#include <cstdio>
#include <cstring>
const int p3[13]={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};
char ans[531444];
int N,t;
int main()
{
	int i,j;
	memset(ans,' ',sizeof(ans));
	ans[1]='-';
	for (i=0;i<12;i++)
		for (j=2*p3[i]+1;j<=3*p3[i];j++)
			ans[j]=ans[j-2*p3[i]];
	while (scanf("%d",&N)!=EOF)
	{
		t=ans[p3[N]+1];
		ans[p3[N]+1]=0;
		printf("%s",ans+1);
		printf("\n");
		ans[p3[N]+1]=t;
	}
}
