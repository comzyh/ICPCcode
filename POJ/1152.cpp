#include <cstdio>
#include <cstring>
int tab[20],ANS;
int main()
{
	int i,j;
	while (scanf("%d",&tab[1]),tab[1]>0)
	{
		ANS=0;
		for (i=2;scanf("%d",&tab[i]),tab[i]!=0;i++);
		while (--i)
			for (j=i-1;j>=1;j--)
				if (tab[i]==2*tab[j] || tab[i]*2==tab[j])
					ANS++;
		printf("%d\n",ANS);
			
	}
}

