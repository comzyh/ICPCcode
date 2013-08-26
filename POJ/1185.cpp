#include <cstdio>
#include <cstring>
int N,M;
int le[1024],R;
long long  f[2][1024][1024],MASK;
int map[101];
inline int count(int x)
{
	x=(x&0x5555)+((x>>1)&0x5555);
	x=(x&0x3333)+((x>>2)&0x3333);
	x=(x&0x0f0f)+((x>>4)&0x0f0f);
	x=(x&0x00ff)+((x>>8)&0x00ff);
	return x;
}
inline void maxset(long long &a,long long  b)
{
	if (b>a)
		a=b;
}
int main()
{
	int i,j,k,l;
	R=0;
	for (i=0;i<=1023;i++)
	if ((i&i<<1)==0 && (i&i<<2)==0 && (i&i>>1)==0 && (i&i>>2)==0)
		le[++R]=i;
	//printf("R=%d\n",R);
	scanf("%d%d",&N,&M);
	MASK=(1<<M)-1;
	char str[100];
	getchar();
	memset(map,0,sizeof(map));
	for (i=1;i<=N;i++)
	{
		gets(str);
		for (j=0;j<M;j++)
			if (str[j]=='P')
				map[i]|=1<<j;
	}
	memset(f,0,sizeof(f));
	for (i=1;i<=N;i++)
	{
		int ii=(i+1)&1,i1=i&1;
		for (j=1;j<=R;j++)//-2
			for(k=1;k<=R;k++)//-1
			{
				int ans=(~(le[j]|le[k]))&map[i];
				for(l=1;l<=R;l++)
					if((ans&le[l])==le[l])
						maxset(f[i1][le[k]][le[l]],f[ii][le[j]][le[k]]+count(le[l]));			
			}
	}
	long long  ANS=0;
	int i1=N&1;
	for (i=1;i<=R;i++)
		for (j=1;j<=R;j++)
			maxset(ANS,f[i1][le[i]][le[j]]);
	printf("%lld\n",ANS);
}
