#include <cstdio>
#include <cstring>
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int T,N,M,L,K,MASK,ANS;
int h[21][21];
struct node
{
	int x,y,s;
	int g,hg;
	inline void ghg()
	{
		hg=h[x][y]+g;
	}
	inline int test(int tx,int ty)
	{
		int i,ss=s,sx=x,sy=y;
		for (i=1;i<L;i++)
		{
			sx+=dx[ss&0x3];
			sy+=dy[ss&0x3];
			if (tx==sx && ty==sy)
				return 0;
			ss>>=2;
		}
		return 1;
	}
}q[2000000];
int r;
int map[21][21];
int used[21][21][1<<14];
inline void add(node n);
inline void del();
inline void down();
inline void up(int k);
void BFS(int x,int y);
inline void swap(node &x,node &y);
int main()
{
	int i,j,x,y;
	T=0;
	//printf("%d\n",sizeof(used));
	while (scanf("%d%d%d",&N,&M,&L), N && M && L)
	{
		r=1;
		MASK=(1<<(L-1)*2)-1;
		int lx,ly;
		scanf("%d%d",&q[1].x,&q[1].y);
		lx=q[1].x;ly=q[1].y;
		q[1].s=0;
		for (i=1;i<L;i++)
		{
			scanf("%d%d",&x,&y);
			if (x<lx)q[1].s|=(0<<(2*(i-1)));
			if (x>lx)q[1].s|=(2<<(2*(i-1)));
			if (y<ly)q[1].s|=(1<<(2*(i-1)));
			if (y>ly)q[1].s|=(3<<(2*(i-1)));
			lx=x;
			ly=y;
		}
		memset(used,0x3f,sizeof(used));
		used[q[1].x][q[1].y][q[1].s]=0;
		q[1].g=0;
		
		//
		memset(map,0,sizeof(map));
		scanf("%d",&K);
		for (i=1;i<=K;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		BFS(1,1);
		q[1].ghg();
		for (i=1;i<=N,0;i++)
		{
			for (j=1;j<=M;j++)
				printf("%3d ",h[i][j]);
			printf("\n");
		}
		//
		ANS=0x3fffffff;
		while (r)
		{
			node h=q[1];
			//printf("x=%d,y=%d,s=%x,hg=%d,g=%d\n",h.x,h.y,h.s,h.hg,h.g);
			if (h.x==1 && h.y==1 && h.g<ANS)
			{
				ANS=h.g;
				//printf("ANS=%d\n",ANS);
				break;
			}
			del();//删除头结点
			//if (h.g>=ANS-1)continue;
			for (i=0;i<4;i++)
			{
				x=h.x+dx[i];
				y=h.y+dy[i];
				int ns=((h.s<<2)|((i+2)&0x3))&MASK;
				if (x>0 && x<=N && y>0 && y<=M && h.test(x,y) && !map[x][y] && (h.g+1)<used[x][y][ns])
				{ 
					node t;
					t.x=x;
					t.y=y;
					t.s=ns;
					t.g=h.g+1;
					t.ghg();
					add(t);
					//printf(">t.x=%d,t.y=%d,t.hg=%d,t.g=%d\n",t.x,t.y,t.hg,t.g);
					used[x][y][t.s]=t.g;
				}
			}
		}
		printf("Case %d: ",++T);
		if (ANS<0x3fffffff)
			printf("%d\n",ANS);
		else
			printf("-1\n");
	}
}
inline void add(node n)
{
	r++;
	q[r]=n;
	up(r);
}
inline void del()
{
	q[1]=q[r];
	r--;
	down();
}
inline void down()
{
	int k=1,kk;
	node t;
	while (1)
	{
		kk=k<<1;
		if (kk>r)return ;
		if (kk+1<=r && q[kk+1].hg<q[kk].hg)kk++;
		if (q[kk].hg >= q[k].hg)return ;
		swap(q[kk],q[k]);
		//t=q[kk];q[kk]=q[k];q[k]=t;
		k=kk;
	}
}
inline void up(int k)
{
	node t;
	while (k>1)
	{
		if (q[k].hg<=q[k>>1].hg)
		{
			swap(q[k],q[k>>1]);
			//t=q[k];q[k]=q[k>>1];q[k>>1]=t;
			k>>=1;
		}
		else
		return ;
	}
}
void BFS(int x,int y)
{
	memset(h,0xff,sizeof(h));
	int qx[10000],qy[10000],tx,ty;
	int head,tail;
	qx[1]=x;
	qy[1]=y;
	head=0;
	tail=1;
	h[x][y]=0;
	while (head<tail)
	{	
		head++;
		for (int i=0;i<4;i++)
		{
			tx=qx[head]+dx[i];
			ty=qy[head]+dy[i];
			if (tx >0 && tx <=N && ty>0 && ty<=M && h[qx[head]][qy[head]]+1<(unsigned int)h[tx][ty] && !map[tx][ty])
			{
				h[tx][ty]=h[qx[head]][qy[head]]+1;
				tail++;
				qx[tail]=tx;
				qy[tail]=ty;
			}
		}
	}
	
}
inline void swap(node &x,node &y)
{
	node t=x;
	x=y;
	y=t;
	//for (int i=1;i<10;i++);
}
