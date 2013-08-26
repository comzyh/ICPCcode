#include <cstdio>
#include <cstring>
int pow(int a,int k)
{
	int ans=a;
	while (--k)
		ans*=a;
	return ans;
}
inline int abs(int n)
{
	if (n<0)	
		return -n;
	else
		return n;
}

int A,B,N,dis;
int main()
{
	int i,tans;
	while (scanf("%d%d",&B,&N),B>0 && N>0)
	{
		dis=0x7fffffff;
		i=0;
		while(1)
		{
			tans=pow(++i,N);
			//printf("tans=%d\n",tans);
			if (abs(tans-B)<dis)
				dis=abs(tans-B);
			else
			{
				printf("%d\n",i-1);
				break;
			}
		}		
	}
}
