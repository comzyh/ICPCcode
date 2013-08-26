#include <cstdio>
const int MAX=0x0fffffff;
int N,M,ANS;
int tab[101][101];
int main()
{
	int i,j,k,f,t;
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			tab[i][j]=MAX;
	for (i=1;i<=N;i++)
		tab[i][i]=0;
	for (i=1;i<=M;i++)
	{
		scanf("%d%d",&f,&t);
		tab[f][t]=1;
	}
	//Floyd
	for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				if (i!=j && tab[i][k]<MAX && tab[k][j]<MAX && tab[i][k]+tab[k][j]>tab[i][j])
					tab[i][j]=tab[i][k]+tab[k][j];		
					
							
	for (i=1;i<=N,0;i++)
	{
		for (j=1;j<=N;j++)
			if (tab[i][j]==MAX)
				printf(" MAX");
			else
				printf("%4d",tab[i][j]);
		printf("\n");
	}
	
	
	int alone=1;
	for (i=1;i<=N;i++)
	{
		
		for (j=1;j<=N;j++)
			if ((i!=j) && (tab[i][j]<MAX || tab[j][i]<MAX))
			{
				alone=0;
				break;
			}
		if (alone)break;
	}
	if (alone)
	{
		printf("0\n");
	}
	else
	{
		ANS=0;
		//small
		int nsmall=0,small;
		for (i=1;i<=N;i++)
		{
			int ismall=1;
			for (j=1;j<=N;j++)
				if (i!=j && tab[i][j]<MAX)
				{
					ismall=0;
					break;
				}
			
			if (ismall)
			{
				nsmall++;
				small=i;
				if (nsmall>1)
					break;
			}
		}
		if (nsmall==1)
		{
			do
			{
				ANS++;
				nsmall=0;
				int osmall=small;
				for (i=1;i<=N;i++)
					if (i!=osmall && tab[i][osmall]==1)
					{
						nsmall++;
						small=i;
					}
			//printf("nsmall=%d\n",nsmall);
			}while (nsmall==1);
		}
		//printf("ANS(small)=%d\n",ANS);
		//big
		int nbig=0,big;
		for (i=1;i<=N;i++)
		{
			int ibig=1;
			for (j=1;j<=N;j++)
				if (i!=j && tab[j][i]<MAX)
				{
					ibig=0;
					break;
				}
			if (ibig)
			{
				nbig++;
				big=i;
				if (nbig>1)
					break;
			}
		}
		if (nbig==1)
		{
			do
			{
				ANS++;
				nbig=0;
				int obig=big;
				for (i=1;i<=N;i++)
					if (i!=obig && tab[obig][i]==1)
					{
						nbig++;
						big=i;
					}
			//printf("nbig=%d\n",nbig);
			}while (nbig==1);
		}
		if (ANS<N)
			printf("%d\n",ANS);
		else
			printf("%d\n",N);
	}
	
}
