#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int T;
LL dp[20][20][18*9*9];
int bit[20];
//pos第几位(由高到低),center支点位置
//pre之前已经产生的力矩
//limit改位是否限制在bit[pos],目的在于控制数字不得超过bit里面表示的数字
LL getans(int pos,int center,int pre,int limit)
{
	if (pos==0)
		return pre==0;//终止条件,力矩为0才满足要求
	if (pre<0)
		return 0;//pre<0 说明支点太靠左,且pos已经在center右边,再递归也不会使pre增加
	if (!limit && dp[pos][center][pre]!=-1)
		return dp[pos][center][pre];//记忆化
	LL ans=0;
	int up=limit?bit[pos]:9;
	for (int i=0;i<=up;i++)//枚举pos位的数
		//pos-1 是下一位,pre增加当前点的力矩
		//limit 仅当pos位受限且pos位的值(i)已经为up的时候才会限制下一位
		ans+=getans(pos-1,center,pre+(pos-center)*i,limit && i==up);
	if (!limit && dp[pos][center][pre]==-1)
		dp[pos][center][pre]=ans;//记忆
	return ans;
}
LL getsum(LL num)
{
	if (num<0)return 0;//处理调用的时候a-1
	int l;
	for (l=0;num;num/=10)
		bit[++l]=num%10;
	LL ans=0;
	for (int i=1;i<=l;i++)
		ans+=getans(l,i,0,1);
	return ans-(l-1);//全0产生l个答案,实际应产生1个,把l-1个多余的去掉
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		memset(dp,0xff,sizeof(dp));
		printf("%lld\n",getsum(b)-getsum(a-1));
	}	
	return 0;	
}