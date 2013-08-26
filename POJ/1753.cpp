#include <cstdio>
#include <cstring>
#include <cstdlib>
const int tab[16]={0x13,0x27,0x4e,0x8c,0x131,0x272,0x4e4,0x8c8,0x1310,0x2720,0x4e40,0x8c80,0x3100,0x7200,0xe400,0xc800};
inline int no(int x)
{
	x=(x&0x5555)+((x>>1)&0x5555);
	x=(x&0x3333)+((x>>2)&0x3333);
	x=(x&0x0f0f)+((x>>4)&0x0f0f);
	x=(x&0x00ff)+((x>>8)&0x00ff);
	return x;
}
int ANS;
int main()
{
	int input=0;
	int i,j,k;
	char c;
	int ANS=0x7fffffff;
	for (i=0;i<=3;i++)
	{
		for (j=0;j<=3;j++)
		{
			scanf("%c",&c);
			if (c=='b')input+=1<<i*4+j;
		}
		getchar();
	}
	int tn;
	for (k=0;k<=0xffff;k++)
	{
		tn=input;
		for (i=0;i<=3;i++)
		for (j=0;j<=3;j++)
		{
			if (((k>>(4*i+j))&1)==1)
			tn^=tab[4*i+j];
		}
		if ((tn==0xffff || tn==0) && no(k)<ANS)ANS=no(k);
	}
	if (ANS!=0x7fffffff)
		printf("%d",ANS);
	else
		printf("Impossible");
	//system("pause");
}
