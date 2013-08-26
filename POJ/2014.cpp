#include <cstdio>
#include <iostream>
using namespace std;
struct Thing
{
	int w,h;
}ts[100];
int M,R;
int main()
{
	
	while (scanf("%d",&M),M)
	{
		int A=0,B=0;
		R=0;
		int a,b;
		while(scanf("%d%d",&a,&b),a>0 && b>0)
		{
			R++;
			ts[R].w=a;
			ts[R].h=b;
		}
		int NW=0,NH=0;
		for (int i=1;i<=R;i++)
		{
			if (NW+ts[i].w>M)
			{
				if (NW>A)
					A=NW;
				B+=NH;
				NW=ts[i].w;
				NH=ts[i].h;
			}
			else
			{
				NW+=ts[i].w;
				if(ts[i].h>NH)
					NH=ts[i].h;
			}
		}
		if (NW>A)
			A=NW;
		B+=NH;
		printf("%d x %d\n",A,B);
	}
	return 0;
}
