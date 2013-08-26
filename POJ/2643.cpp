#include <cstdio>
#include <cstring>
struct candidate
{
	char name[100],party[100];
}cas[21];
struct party
{
	char name[100];
	int vote;
}pas[30];
int np;
int N,M;
inline void vote(char *pname);
inline bool is_independent(char *name);
int main()
{
	int i,j;
	scanf("%d",&N);
	getchar();
	char name[80];
	for (i=1;i<=N;i++)
	{
		gets(cas[i].name);
		gets(cas[i].party);
		if (strcmp(cas[i].party,"independent")==0)
			strcat(cas[i].party,cas[i].name);
	}
	scanf("%d",&M);
	getchar();
	np=0;
	for (i=1;i<=M;i++)
	{
		gets(name);
		for (j=1;j<=N;j++)
			if (strcmp(name,cas[j].name)==0)
				vote(cas[j].party);
	}
	int MAX=0,nans=0;
	strcpy(pas[0].name,"tie");pas[0].vote=0;
	for (i=1;i<=np;i++)
		if (pas[i].vote>pas[nans].vote)nans=i;
	for (i=1;i<=np;i++)
		if (i!=nans && pas[i].vote==pas[nans].vote)
		{
			nans=0;
			break;
		}
	if (is_independent(pas[nans].name))
		printf("independent\n");
	else
		printf("%s\n",pas[nans].name);

}
inline void vote(char *pname)
{
	int i;
	for (i=1;i<=np;i++)
		if (strcmp(pas[i].name,pname)==0)
			break;
	if (i>np)
	{
		np=i;
		strcpy(pas[np].name,pname);
		pas[np].vote=0;
	}
	pas[i].vote++;
}
inline bool is_independent(char *name)
{
	char de[30];
	strcpy(de,"independent");
	for (int i=0;i<11;i++)
		if (name[i]!=de[i])
			return 0;
	return 1;
}