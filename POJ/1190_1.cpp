#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAX=0x30000000;
int DFS(int n,int m,int r,int sum);
int N,M,ANS;
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF){
	int i,j,tans;
	ANS=0x7fffffff;
	for (i=1;i*i<N;i++);
	for (i=i-1;i>=M;i--)
	{
		tans=DFS(N,M,i,i*i)+i*i;
		if (tans<ANS)ANS=tans;
		if (tans>ANS && tans<MAX)break;
	}
	printf("%d\n",ANS);
	}
	//system("pause");
}
int DFS(int n,int m,int r,int sum)
{
	
	if (sum+2*(n/r)>ANS)return MAX;
	int i,j,ans=MAX,tans;
	if (m==1)
	{
		if (n%(r*r)==0 && n!=0)
		{
			int h=n/(r*r);
			if (sum+2*h*r>ANS)return MAX;
			//printf("n=%4d,m=%4d,r=%4d\n",n,m,r);
			return 2*r*h;
		}
		else 
			return MAX;
	}
	for (i=n/(r*r);i>=1;i--)// this h
		for (j=r-1;j>=m;j--)// next r
			{
				tans=DFS(n-r*r*i,m-1,j,sum+2*r*i)+2*r*i;
				if (tans<=ans){ans=tans;j=0;/*i=0;*/}
			}
	if (ans>MAX)ans=MAX;
	return ans;
}
