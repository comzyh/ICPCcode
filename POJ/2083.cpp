#include <cstdio>
#include <cstring>
const int p3[8]={0,1,3,9,27,81,243,729};
int L;
int tab[1000][1000];
inline void cpy(int l)
{
	int i,j;
	for (i=1;i<=l;i++)
		for (j=1;j<=l;j++)
				tab[2*l+i][j]=
				tab[l+i][l+j]=
				tab[i][2*l+j]=
				tab[2*l+i][2*l+j]=
				tab[i][j];
}
int main()
{
	int i,j,k;
	memset(tab,0,sizeof(tab));
	tab[1][1]=1;L=1;
	for (k=1;k<=6;k++)
		cpy(p3[k]);
	while (scanf("%d",&L),L>0)
	{
		for (i=1;i<=p3[L];i++)
		{
			for (j=1;j<=p3[L];j++)
				if (tab[i][j])
					printf("X");
				else
					printf(" ");
			printf("\n");
		}
		printf("-\n");
	}
	
}
