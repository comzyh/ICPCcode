#include <cstdio>
#include <cstring>
int N,ANS;
int tab[100001],inv[100001];
int main()
{
	int i;
	while (scanf("%d",&N),N)
	{
		for (i=1;i<=N;i++)
		{
			scanf("%d",&tab[i]);
			inv[tab[i]]=i;
		}
		ANS=1;
		for (i=1;i<=N && ANS;i++)
			ANS&=(inv[i]==tab[i]);
		if (!ANS)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
	}
}
