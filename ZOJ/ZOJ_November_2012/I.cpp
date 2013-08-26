#include <cstdio>
#include <cstring>
#include <cstdlib>
int main();
char temp[300];
char words[101][40];
char tips[101][300];
char ans[200][250];
int N,M;
inline int find(char* src,char* tip);
inline int findword(char* word)
{
	for (int i=1;i<=N;i++)
		if (strcmp(words[i],word)==0)return i;
}
void qsort(int b,int e);
int main()
{
	int i,j,k;
	int ask[400];
	while (scanf("%d",&N)!=EOF)
	{
		memset(words,0,sizeof(words));
		memset(tips,0,sizeof(tips));
		memset(temp,0,sizeof(temp));
		getchar();
		for (i=1;i<=N;i++)
		{
			gets(words[i]);
			gets(tips[i]);
			
		}
		scanf("%d",&M);
		getchar();
		//printf("M=%d\n",M);
		for (i=1;i<=M;i++)
		{
			memset(temp,0,sizeof(temp));
			memset(ans,0,sizeof(ans));
			int nans=0;
			gets(temp);
			char t[250];
			int pos,existans=0;
			//读words
			for (j=1,pos=0;sscanf(temp+pos,"%s",&t)!=EOF;j++,pos+=strlen(t)+1)
				ask[j]=findword(t);
			ask[0]=--j;
			//判断
			for (pos=0;sscanf(tips[ask[1]]+pos,"%s",&t)!=EOF;pos+=strlen(t)+1)
			{
				int common=1;
				for (k=2;k<=ask[0] && common==1;k++)
					if (find(tips[ask[k]],t)==0)
						common=0;
				if (common)
					memcpy(ans[++nans],t,strlen(t)+1);
			}
			//OutPut
			if (nans)
			{
				qsort(1,nans);
				for (j=1;j<nans;j++)
					printf("%s ",ans[j]);
				printf("%s\n",ans[nans]);
			}
			else 
				printf("NO\n");
		}
	}
}
inline int find(char* src,char* tip)
{
	char t[300];
	//printf("find %s /// %s\n",src,tip);
	for (int i=1,pos=0;sscanf(src+pos,"%s",t)!=EOF;pos+=strlen(t)+1,i++)
		if (strcmp(t,tip)==0)return i;
	return 0;
}
void qsort(int b,int e)
{
	int i=b,j=e;
	char k[200];memcpy(k,ans[(i+j)>>1],strlen(ans[(i+j)>>1])+1);
	while (i<j)
	{
		while (strcmp(ans[i],k)<0)i++;
		while (strcmp(ans[j],k)>0)j--;
		if (i<=j)
		{
			memcpy(temp,ans[j],strlen(ans[j])+1);
			memcpy(ans[j],ans[i],strlen(ans[i])+1);
			memcpy(ans[i],temp,strlen(temp)+1);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
