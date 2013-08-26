#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int P,ANS=0x7fffffff,NP=0;
int num[1000001],snum[1000001],in[1000001];
inline int bin(int x)
{
	int b=1,e=NP,k;
	while (b<e)
	{
		k=(b+e)>>1;
		if (snum[k]<x)
			b=k+1;
		else if (snum[k]>x)
			e=k-1;
		else return k;
	}
	return b;
}
int main()
{
	int i,j;
	scanf("%d",&P);
	for (i=1;i<=P;i++)
	{
		scanf("%d",&num[i]);
		snum[i]=num[i];
	}
	sort(snum+1,snum+P+1);
	NP=0;
	for (i=1;i<=P;i++)
		if(snum[i]!=snum[i+1])
			snum[++NP]=snum[i];
	for (i=1;i<=NP;i++)
		in[i]=0;
	int b=1,e=0,Nin=0;
	while (e<P)
	{
		int be;
		//向前扩展使得所有元素至少出现一次
		while (Nin!=NP && e<P)
		{
			be=bin(num[++e]);
			in[be]++;
			if(in[be]==1)
				Nin++;
		}
		//去掉尾部不影响出现元素种类的元素
		while (Nin==NP && b<e)
		{
			be=bin(num[b]);
			if (in[be]>1)
			{
				in[be]--;
				b++;
			}
			else
				break;
		}
		if (e-b+1<ANS && Nin==NP)
		{
			ANS=e-b+1;
			//printf("ANS:b=%4d,e=%4d\n",b,e);
		}
		//在尾部多去掉一个元素,这一定会影响出现元素种类
		be=bin(num[b++]);
		in[be]--;
		Nin--;
	}
	printf("%d\n",ANS);
	return 0;
}
