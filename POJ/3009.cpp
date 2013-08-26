#include <cstdio>
#include <cstring>
#include <cstdlib>
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int map[21][21];
int w,h,bx,by,ANS;
struct point
{
	int x,y;
	void move(int d)
	{
		switch (d)
		{
			case 0:
				x--;break;
			case 1:
				x++;break;
			case 2:
				y--;break;
			case 3:
				y++;break;
		}
	}
	int dstate(int d)
	{
		int tx=x+dx[d],ty=y+dy[d];
		if (tx>0 && tx<=h && ty>0 && ty<=w)
			return map[tx][ty];
		else
			return -1;
	}
	
};
int DFS(int x,int y,int d,int step);//x,y,direction,step
int main()
{
	int i,j,k;
	while (scanf("%d%d",&w,&h),(w!=0 && h!=0))
	{
		//Read
		memset(map,0,sizeof(map));
		for (i=1;i<=h;i++)
			for (j=1;j<=w;j++)
			{
				scanf("%d",&map[i][j]);
				if (map[i][j]==2)
				{bx=i;by=j;}
			}
		ANS=0x7fffffff;
		DFS(bx,by,0,0);
		if (ANS<0x7fffffff)
			printf("%d\n",ANS);
		else
			printf("-1\n");
	}
}
int DFS(int x,int y,int d,int step)//x,y,direction,step
{
	//printf("x=%4d,y=%4d,step=%6d\n",x,y,step);
	//getchar();
	if (step>10)return -1;
	if (map[x][y]==3)
	{
		if (step<ANS)ANS=step;
		return 1;
	}
	for (int i=0;i<=3;i++)
	{
		//if ((d==0 && i==1) || (d==1 && i==0) || (d==2 && i==3) || (d==3 && i==4))
		//	continue;
		point p;
		int s;
		p.x=x;p.y=y;
		while (s=p.dstate(i),s!=1 && s!=-1)
		{
			if (s==3 && step<10 && (step+1<ANS))
			{	
				ANS=step+1;
			}
			p.move(i);
		}
		if (p.dstate(i)!=-1 && (p.x!=x || p.y!=y))
		{
		//printf("i=%4d,p.x=%4d,p.y=%4d dstate=%4d\n",i,p.x,p.y,p.dstate(i));
			if (map[p.x][p.y]==3)
				DFS(p.x,p.y,i,step+1);
			else
			{
				//printf("dstate=%4d\n",p.dstate(i));
			//*if (p.dstate(i)!=-1)
			//{
				if (p.dstate(i)==1)
				{
					map[p.x+dx[i]][p.y+dy[i]]=0;	
					DFS(p.x,p.y,i,step+1);
					map[p.x+dx[i]][p.y+dy[i]]=1;	
				}
				else
					DFS(p.x,p.y,i,step+1);
			//}	
			}
		}
	}
}


	