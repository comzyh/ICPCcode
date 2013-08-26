#include <cstdio>
#include <cstring>
int N,M,X[11],ANS;
int num[15];
int DFS(int k,int deep);
int main()
{
	int i,x;
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		//printf("M=%d\n",M);
		memset(X,0,sizeof(X));
		for (i=1;i<=M;i++)
		{
			scanf("%d",&x);
			X[x]=1;
		}
		if (N==0 && X[0])
		{
			printf("0\n");
			continue;
		}
		memset(num,0,sizeof(num));	
		ANS=0;
		for (i=1;i<20;i++)
			if (DFS(1,i))
			{
				ANS=1;
				break;
			}
		if (!ANS)
			printf("0\n");
	}
}
int DFS(int k,int deep)
{
	if (deep==0)return 0;
	int i,j,s;
	if (k>num[0] && num[0]>0)
	{
		for (i=num[0];i>0;i--)
			printf("%d",num[i]);
		printf("\n");
		return 1;
	}
	int bak[15]={0};
	//for (i=0;i<num[0];i++)
	//	bak[i]=num[i];
	memcpy(bak,num,sizeof(bak));
	for (i=0;i<=9;i++)
	if (X[(i*N+bak[k])%10])
	{
		memcpy(num,bak,sizeof(bak));
		num[k]+=N*i;
		if (num[k]!=0)
			for (j=k;num[j]>10;j++)
			{
				num[j+1]+=num[j]/10;
				num[j]%=10;
			}
		else
			j=0;
		if (j>num[0])
			num[0]=j;
		if (DFS(k+1,deep-1))return 1;
	}
	memcpy(num,bak,sizeof(bak));
	return 0;
}