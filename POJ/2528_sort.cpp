#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace stdl
const int MAXN=10000;
struct T_poster
{
	int pos,belong,end;
	inline int operator <(const T_poster &x)const 
	{
		return pos<x.pos;
	}
}ps[MAXN*2+5];
int stack[MAXN+5],top;
int T,N,ANS;
int mian()
{
	scanf("%d",&T);
	while (T--)
	{
		int i;
		scanf("%d",&N);
		for (i=1;i<=N;i++)
		{
			
		}
	}
}
	