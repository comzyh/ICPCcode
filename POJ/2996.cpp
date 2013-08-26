#include <cstdio>
#include <cstring>
const char ROL[7]={0,'K','Q','R','B','N','P'};
const int dASCII='a'-'A';
inline int char_int(char c)
{
	for (int i=1;i<=6;i++)
		if (c==ROL[i] || c==ROL[i]+dASCII)
			return i;
}
struct role
{
	
	int t,r,x,y;
	inline bool  operator <(const role &k)
	{
		//the piece with the smaller row number must be described before the other one if the pieces are white, and the one with the larger row number must be described first if the pieces are black. If two pieces of the same type appear in the same row, the one with the smaller column letter must appear first.
		if (r!=k.r)return (r<k.r);
		if (x!=k.x)
		{
			if (t==0)
				return (x>k.x);
			else 
				return (x<k.x);
		}
		if (y!=k.y)return (y<k.y);
		
		return 0;
	}
	inline void pri()
	{
		if (r!=6)
			printf("%c",ROL[r]);
		printf("%c%d",y+'a'-1,9-x);
	}
}team[2][64],tmp;
int tnum[2];
void qsort(role arr[],int b,int e);
inline void printeam(int t)
{
	team[t][1].pri();
	for (int i=2;i<=tnum[t];i++)
	{
		printf(",");
		team[t][i].pri();
	}
	printf("\n");
}
int main()
{
	int i,j,t;
	char str[100],c;
	tnum[0]=tnum[1]=0;
	gets(str);
	for (i=1;i<=8;i++)
	{
		gets(str+1);
		for (j=1;j<=8;j++)
			if (c=str[4*j-1],c!=':' && c!='.')
			{
				t=c>'Z';
				role &p=team[t][++tnum[t]];
				p.r=char_int(c);
				p.x=i;
				p.y=j;
				p.t=t;
			}
		gets(str);
	}
	qsort(team[0],1,tnum[0]);
	qsort(team[1],1,tnum[1]);
	printf("White: ");printeam(0);
	printf("Black: ");printeam(1);
	return 0;
	
	
}
void qsort(role arr[],int b,int e)
{
	//printf("b=%4d,e=%4d\n",b,e);
	int i=b,j=e;
	role k=arr[(b+e)>>1];
	while (i<j)
	{
		while (arr[i]<k)i++;
		while (k<arr[j])j--;
		if (i<=j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	}
	//printf("i=%4d,j=%4d\n",i,j);
	if (b<j)qsort(arr,b,j);
	if (i<e)qsort(arr,i,e);
}
