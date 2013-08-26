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
inline int  num(int n)
{
	int ans=0;
	for (int i=0;i<M;i++)
		if ((n & (1<<i))!=0)
			ans++;
	return ans;
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
		//pri(t1);pri(t2);
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
	if (++KK>100000)return ;
	if ((tn & na)==na && k<ANS)ANS=k;
	//printf("k=%2d  ",k);pri(tn);
	//getchar();
	int max=0,t,d,r;
	for (int i=0;i<=M;i++)
	{
		
		if (t=num(((~tn)& (t1<<i))&na),t>max)max=t;
		if (t=num(((~tn)& (t1>>i))&na),t>max)max=t;
		if (t=num(((~tn)& (t2<<i))&na),t>max)max=t;
		if (t=num(((~tn)& (t2>>i))&na),t>max)max=t;
		
	}
	//printf("max=%d\n",max);
	if (max>0)
	for (int i=0;i<=M;i++)
	{
		if (num(((~tn)& (t1<<i))&na)==max)find((tn | (t1<<i))&na,k+1);
		if (num(((~tn)& (t1>>i))&na)==max)find((tn | (t1>>i))&na,k+1);
		if (num(((~tn)& (t2<<i))&na)==max)find((tn | (t2<<i))&na,k+1);
		if (num(((~tn)& (t2>>i))&na)==max)find((tn | (t2>>i))&na,k+1);
		
	}
}
