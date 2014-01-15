#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N;
char str[30009],ans[30009];
inline int check(int a,int b)
{
	while (str[a]==str[b] && a<b)
	{
		a++;
		b--;
	}
	return str[a]<str[b];
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%s",str+i);
	int l=1,r=N;
	ans[N]='\0';
	for (int i=0;i<N;i++)
		if (check(l,r))
			ans[i]=str[l++];
		else
			ans[i]=str[r--];
	for (int i=0;i<N;i++)
	{
		if (i!=0 && i%80==0)
			printf("\n");
		putchar(ans[i]);
	}
	printf("\n");
	return 0;
}