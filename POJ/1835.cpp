#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dir[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
struct Vector
{
	int x,y,z;
	Vector ()
	{
		x=y=z=0;
	}
	Vector (int x,int y,int z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
	Vector & operator +=(const Vector &a)
	{
		x+=a.x;
		y+=a.y;
		z+=a.z;
		return *this;
	}
	Vector operator *(const int k)
	{
		Vector ans=*this;
		ans.x*=k;
		ans.y*=k;
		ans.z*=k;
		return ans;
	}
};
Vector cross(const Vector &a,const Vector &b)
{
	Vector ans;
	ans.x=-a.y*b.z+a.z*b.y;
	ans.y=-a.z*b.x+a.x*b.z;
	ans.z=-a.x*b.y+a.y*b.x;
	return ans;
}
Vector F,H,P;
int T,N;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		F=Vector(1,0,0);
		H=Vector(0,0,1);
		P=Vector(0,0,0);
		for (int i=1;i<=N;i++)
		{
			char str[20];
			int s;
			scanf("%s%d",str,&s);
			if (strcmp(str,"left")==0)
				F=cross(H,F);
			if (strcmp(str,"right")==0)
				F=cross(F,H);
			if (strcmp(str,"back")==0)
				F=F*-1;
			if (strcmp(str,"up")==0)
			{
				swap(F,H);
				H=H*-1;
			}
			if (strcmp(str,"down")==0)
			{
				swap(F,H);
				F=F*-1;
			}
			P+=F*s;
			// int d;
			// for (d=0;d<6;d++)
			// 	if (F.x==dir[d][0] && F.y==dir[d][1] && F.z==dir[d][2])
			// 		break;
			// printf("%d %d %d %d\n",P.x,P.y,P.z,d);
		}
		int d;
		for (d=0;d<6;d++)
			if (F.x==dir[d][0] && F.y==dir[d][1] && F.z==dir[d][2])
				break;
		printf("%d %d %d %d\n",P.x,P.y,P.z,d);
	}
	return 0;
}