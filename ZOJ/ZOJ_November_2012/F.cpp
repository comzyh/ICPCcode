#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct MJ
{
	char t,n;
	inline bool operator <(const MJ &m)
	{
		return (t<m.t || (t==m.t && n<m.n));
	}
}s[15],temp;
void qsort(int b,int e);
int main()
{
	char str[40];
	int i;
	while (gets(str)!=NULL)
	{
		for (i=1;i<=14;i++)
			sscanf(str+2*i-2,"%1d%c",&s[i].n,&s[i].t);
		qsort(1,14);
		
		int ans=1;
		for (i=1;i<=13;i+=2)
		{
			if (s[i].t!=s[i+1].t || s[i].n!=s[i+1].n )ans=0;
			for (int j=i+2;j<=13;j+=2)
				if (s[i].n==s[j].n && s[i].t==s[j].t)ans=0;
		}
		
		if (ans==0)
		{
			ans=2;
			char tt;
			for (i=1;i<=14;i++)
				for (int j=i+1;j<=14;j++)
					if (s[i].t==s[j].t && s[i].n==s[j].n)
					{
						tt=s[j].t;
						s[j].t='z'+1;
					}
			qsort(1,14);
			//for (int j=1;j<=14;j++)
			//	printf("%2d : %c %d\n",j,s[j].t,s[j].n);
			if (tt!='z' && s[14].n!=1 && s[14].n!=9)ans=0;
			if (s[1].n!=1 && s[2].n!=9 && s[3].n!=1 && s[4].n!=9 &&s[5].n!=1 && s[6].n!=9)ans=0;
			if (s[1].t!='m' ||s[2].t!='m'|| s[3].t!='p'|| s[4].t!='p' || s[5].t!='s'|| s[5].t!='s')ans=0;
			for (i=1;i<=6;i++)
				if (s[i].t=='z')ans=0;
				
			for (i=7;i<=13;i++)
				if (s[i].n!=i-6 || s[i].t!='z')ans=0;
		}
		if (ans==1)printf("Seven Pairs\n");
		if (ans==2)printf("Thirteen Orphans\n");
		if (ans==0)printf("Neither!\n");
	}
}
void qsort(int b,int e)
{
	int i=b,j=e;
	MJ k=s[(b+e)>>1];
	while (i<j)
	{
		while (s[i]<k)i++;
		while (k<s[j])j--;
		if (i<=j)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
			i++;j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
