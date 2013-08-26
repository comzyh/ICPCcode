#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int N,ANS;
struct TP
{
	int x,y;
};
TP px[1001],py[1001];
inline bool cmpx(const TP &a,const TP &b){return a.x<b.x || (a.x==b.x && a.y<b.y);}
inline bool cmpy(const TP &a,const TP &b){return a.y<b.y || (a.y==b.y && a.x<b.x);}
int biny(int y)
{
	int b=1,e=N,k;
	while (b<e)
	{
		k=(b+e)>>1;
		if (py[k].y<y)
			b=k+1;
		else
			e=k;
	}
	if (py[b].y==y)
		return b;
	else
		return 0;
}
int main()
{
	while (scanf("%d",&N),N)
	{
		int i,j;
		ANS=0;
		for (i=1;i<=N;i++)
		{
			scanf("%d%d",&px[i].x,&px[i].y);
			py[i]=px[i];
		}
		sort(px+1,px+N+1,cmpx);
		sort(py+1,py+N+1,cmpy);
		// for (i=1;i<=N;i++)
			// printf("(%3d,%3d) ",px[i].x,px[i].y);
		// printf("-----------------------\n");
		// for (i=1;i<=N;i++)
			// printf("(%3d,%3d) ",py[i].x,py[i].y);
		for (i=1;i<=N;i++)
		{
			for (j=i+1;px[i].x==px[j].x;j++)
			{
				int y1=biny(px[i].y),y2=biny(px[j].y);
				while (py[y1].x<px[i].x && py[y1].y==px[i].y)y1++;
				while (py[y2].x<px[j].x && py[y2].y==px[j].y)y2++;
				y1++;y2++;
				while (py[y1].y==px[i].y && py[y2].y==px[j].y)
				{
					while (py[y1].x<py[y2].x && py[y1].y==px[i].y)y1++;
					while (py[y2].x<py[y1].x && py[y2].y==px[j].y)y2++;
					if (py[y1].y!=px[i].y || py[y2].y!=px[j].y)	
						break;
					//printf("%4d%4d%4d%4d\n",px[i].y,py[y1].y,px[j].y,py[y2].y);
					
					if (py[y1].x==py[y2].x)
					{
						printf("%4d%4d%4d%4d\n",px[j].y,px[i].y,py[y1].x,px[i].x);
						if (px[j].y-px[i].y==py[y1].x-px[i].x)
							ANS++;
						printf("(%3d,%3d)-",px[i].x,px[i].y);
						printf("(%3d,%3d)|",px[j].x,px[j].y);
						printf("(%3d,%3d)-",py[y1].x,py[y1].y);
						printf("(%3d,%3d)|",py[y2].x,py[y2].y);
						printf("\n");
						y1++;
						y2++;
						
					}
				}
			}
		}
		printf("%d\n",ANS);
	}
}
