#include <cstdio>
#include <cstdlib>
struct RGB
{
	int r,g,b;
	inline int distance(const RGB &k)
	{
		return (r-k.r)*(r-k.r)+(g-k.g)*(g-k.g)+(b-k.b)*(b-k.b);
	}
	inline int read()
	{
		scanf("%d%d%d",&r,&g,&b);
		if (r<0 || g<0 || b<0)
			return 0;
		return 1;
	}
}src[20];
int  main()
{
	RGB current,ans;
	int dis,min_distance;
	int i;
	for (i=1;i<=16;i++)
		src[i].read();
	while (current.read())
	{
		min_distance=0x7ffffff;
		for (i=1;i<=16;i++)
			if (dis=current.distance(src[i]),dis<min_distance)
			{
				min_distance=dis;
				ans=src[i];
			}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",current.r,current.g,current.b,ans.r,ans.g,ans.b);
	}
}
