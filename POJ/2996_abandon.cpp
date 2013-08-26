#include <cstdio>
#include <cstring>
//KQRBNP
const char ROL[7]={0,'K','Q','R','B','N','P'};
const int dASCII='a'-'A';
inline void printpoint(int x,int y)
{
	printf("%c%d",y+'A'-1,9-x);
}
struct point
{
	int x,y;
	inline void pri()
	{
		printpoint(x,y);
	}
}role[2][6];

char map[10][10];
void print(int b)
{
	int i,j;
	printf("K");
	role[b][1].pri();
	for (i=2;i<=5;i++)
	{
		printf(",");
		printf("%c",ROL[i]);
		role[b][i].pri();
	}
	for (i=8;i>=1;i--)
		for (j=1;j<=8;j++)
			if ((map[i][j]=='r' && b==1) || (map[i][j]=='R' && b==0))
			{
				printf(",");
				printpoint(i,j);
			}
	printf("\n");
}
int main()
{
	int i,j,r,b;
	char temp[100];
	gets(temp);
	for (i=1;i<=8;i++)
	{
		gets(temp+1);
		for (j=1;j<=8;j++)
		{
			r=char_int(temp[4*j-1]);
			b=(temp[4*j-1]<97);
			if (r!=6)
			{
				role[b][r].x=i;
				role[b][r].y=j;
			}
			else
			{
				map[i][j]=temp[4*j-1];
			}
		}
		gets(temp);
	}
	printf("White: ");print(0);
	printf("Black: ");print(1);
	return 0;
	
}
