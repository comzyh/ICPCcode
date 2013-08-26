#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,ANS,TS,TF;
int main()
{
	ANS=TS=TF=0;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int s,f;
		scanf("%d%d",&s,&f);
		TS+=s;
		TF+=f;
		if (TS+TF<0)
			TS=TF=0;
		if (TS>0 && TF>0 && TS+TF>ANS)
			ANS=TS+TF;
	}
	printf("%d\n",ANS);
	return 0;
}
