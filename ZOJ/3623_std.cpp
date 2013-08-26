#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,L;
int tim[300];
int LLL[300];
int dp[330];

int main()
{
	int ca = 0;
	while(scanf("%d%d",&n,&L)!=EOF)
	{
		ca++;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&tim[i],&LLL[i]);
			if(ca==10){
			//	cout<< tim[i]<<" "<<LLL[i]<<endl;
			}
		}
		for(int j=0;j<330;j++)
		{
			for(int i=1;i<=n;i++)
			{
				dp[j+tim[i]]=max(dp[j+tim[i]],dp[j]+j*LLL[i]);//表示j时间开始造第i只船
			}
		}
		for(int i=0;i<330;i++)
			if(dp[i]>=L)
			{
				//printf("%d %d\n",ca,i);
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
