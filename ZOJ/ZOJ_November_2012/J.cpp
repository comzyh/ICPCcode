#include <cstdio>
#include <cstring>
int ANS;
int N,M;
int t1,t2,na;
int KK;
void find(int tn,int k);//tn 1表示修剪过
inline void pri(int n)
{
	for (int i=0;i<M;i++)
		if ((n & (1<<i))!=0)
			printf("1");
		else 
			printf("0");
	printf(" %d\n",n);
}
inline int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	int i,j;
	while (scanf("%d",&N)!=EOF)
	{
		
		char tc;
		getchar();
		t1=t2=0;
		for (i=0;i<N;i++)
		if (scanf("%c",&tc),tc=='*')
		{
				t1+=1<<i;
				t2+=1<<(N-i-1);		
		}
		scanf("%d",&M);
		ANS=M+1;
		na=(1<<M)-1;
		//pri(t1);pri(t2);pri(na);
		//printf("%d\n%d\n%d\n",t1,t2,na);
		if (t1==0)
			printf("-1\n");
		else
		{
			KK=0;
			find(0,0);
			printf("%d\n",ANS);
		}
	}
}
void find(int tn,int k)
{
	if (k>=ANS)return ;
	tn=tn & na;
	if (tn==na && k<ANS)ANS=k;
	//printf("k=%2d  ",k);pri(tn);
	//printf("lobit=");pri(lowbit(~tn));
	//getchar();
	for (int i=0;i<=M;i++)
	{
		
		if ((lowbit(~tn)& (t1<<i)))find((tn | (t1<<i)),k+1);
		if ((lowbit(~tn)& (t1>>i)))find((tn | (t1>>i)),k+1);
		if ((lowbit(~tn)& (t2<<i)))find((tn | (t2<<i)),k+1);
		if ((lowbit(~tn)& (t2>>i)))find((tn | (t2>>i)),k+1);
	}
}
inline void pri(int n)
{
	for (int i=0;i<M;i++)
		if ((n & (1<<i))!=0)
			printf("1");
		else 
			printf("0");
	printf(" %d\n",n);
}