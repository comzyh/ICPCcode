#include <cstdio>
#include <cstring>
int tab[101][101];
int T;
int main()
{
	int x,y,l;
	int i,j;
	char str[10];
	scanf("%d",&T);
	memset(tab,0,sizeof(tab));
	while (T--)
	{
		getchar();
		scanf("%s %d%d%d",str,&x,&y,&l);
		switch (str[0])
		{
			case 'W':
				for (i=0;i<l;i++)
					for (j=0;j<l;j++)
						tab[x+i][y+j]=0;
				break;
			case 'B':
				for (i=0;i<l;i++)
					for (j=0;j<l;j++)
						tab[x+i][y+j]=1;
				break;
			case 'T':
				int num=0;
				for (i=0;i<l;i++)
					for (j=0;j<l;j++)
						num+=tab[x+i][y+j];
				printf("%d\n",num);
		}
	}
}