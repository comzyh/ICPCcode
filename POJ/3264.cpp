#include <cstdio>
#include <cstring>
int N,Q;
int maxst[50005][17],minst[50005][17];
inline void setmax(int &x,int a,int b){if (a>b)x=a;else x=b;};
inline void setmin(int &x,int a,int b){if (a<b)x=a;else x=b;};
void build(int (&arr)[50005][17],void (* cs)(int&,int,int ))
{
	int i,j;
	for (j=1;(1<<j)<N;j++)
	{
		int j2=1<<j;
		for (i=1;i+j2-1<=N;i++)
			cs(arr[i][j],arr[i][j-1],arr[i+(j2>>1)][j-1]);
	}
}
inline int query(int (&arr)[50005][17],void (* cs)(int&,int,int ),int a,int b)
{
	int ans,j;
	for (j=0;(2<<j)<(b-a+1);j++);
	cs(ans,arr[a][j],arr[b-(1<<j)+1][j]);
	return ans;
}
int main()
{
	scanf("%d%d",&N,&Q);
	int i,j;
	for (i=1;i<=N;i++)
	{
		scanf("%d",&maxst[i][0]);
		minst[i][0]=maxst[i][0];
	}
	build(maxst,setmax);
	build(minst,setmin);
	for (i=1;i<=Q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",query(maxst,setmax,a,b)-query(minst,setmin,a,b));
	}
	return 0;
}