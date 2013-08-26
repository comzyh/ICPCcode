#include <cstdio>
#include <cstring>
#include <cstdlib>
const int tab[16]={0x111f,0x222f,0x444f,0x888f,0x11f1,0x22f2,0x44f4,0x88f8,0x1f11,0x2f22,0x4f44,0x8f88,0xf111,0xf222,0xf444,0xf888};
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
	int ansk;
	for (i=0;i<=3;i++)
	{
		for (j=0;j<=3;j++)
		{
			scanf("%c",&c);
			if (c=='+')input+=1<<i*4+j;
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
		if (tn==0 && no(k)<ANS)
		{
			ANS=no(k);
			ansk=k;
		}
	}
	printf("%d\n",ANS);
	for (i=0;i<=3;i++)
		for (j=0;j<=3;j++)
			if (((ansk>>(4*i+j))&1)==1)
				printf("%d %d\n",i+1,j+1);
	//system("pause");
}
