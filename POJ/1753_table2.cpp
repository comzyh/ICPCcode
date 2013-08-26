#include <cstdio>
#include <cstring>
int tab[6][6];
inline int print()
{
	int ans=0;
	int i,j;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			ans+=tab[i][j]<<(4*(i-1)+(j-1));
	return ans;
}
inline void change(int i,int j)
{
	tab[i  ][j  ]^=1;
	tab[i+1][j  ]^=1;
	tab[i-1][j  ]^=1;
	tab[i  ][j+1]^=1;
	tab[i  ][j-1]^=1;
}
int main()
{
	int i,j,k;
	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
		{
			memset(tab,0,sizeof(tab));
			change(i,j);
			printf("0x%x,",print());
		}		
	
}
