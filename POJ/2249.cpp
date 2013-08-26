#include <cstdio>
double combin(int a,int b);
int main()
{
	int x,y;
	while (scanf("%d%d",&x,&y),x && y)
		printf("%.0f",combin(x,y));

}
double combin(int a,int b)
{
	if (b>=(a>>1))
		b=a-b;
	int i,j;
	double ans=1;
	for (i=a,j=b;j>0;i--,j--)
	{
		ans*=i;
		ans/=j;
	}
	return ans;
}
