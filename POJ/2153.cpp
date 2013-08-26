#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const char Target[]="Li Ming";
int N,M,TN;
inline int strless(const char a[],const char b[])
{
	int i=0;
	while (a[i]!=0 && b[i]!=0 && a[i]==b[i])i++;
	if (a[i]<b[i])	
		return -1;
	if (a[i]==b[i])
		return 0;
	return 1;
}
struct T_Name
{
	char name[31];
	inline bool operator <(const T_Name &x)const
	{
		return strless(name,x.name)==-1;
	}
}Names[10001];
inline int bin(const char name[])
{
	static int b,e,k,t;
	b=1;e=N;
	while (b<e)
	{
		k=(b+e)>>1;
		t=strless(Names[k].name,name);
		if(t==-1)
			b=k+1;
		else if (t==1)
			e=k-1;
		else
			return k;
			//printf("b=%d,e=%d\n",b,e);
	}
	return b;
}
int mark[10001],rep[10001];
inline bool cmp(const int &a,const int &b){return mark[a]>mark[b] || (mark[a]==mark[b] && a==TN);}
int main()
{
	int i,j;
	char name[50];
	scanf("%d",&N);
	getchar();
	for (i=1;i<=N;i++)
	{
		gets(Names[i].name);
		rep[i]=i;
	}
	sort(Names+1,Names+N+1);
	for (i=1;i<=N;i++)
		if(strless(Names[i].name,Target)==0)
			TN=i;
	scanf("%d",&M);
	memset(mark,0,sizeof(mark));
	for(j=1;j<=M;j++)
	{
		for (i=1;i<=N;i++)
		{
			int tm;
			scanf("%d ",&tm);
			gets(name);
			mark[bin(name)]+=tm;
		}
		sort(rep+1,rep+N+1,cmp);
		for (i=1;i<=N;i++)
			if(rep[i]==TN)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}