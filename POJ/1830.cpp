#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,N;
int matrix[30],S[30],E[30];
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		memset(matrix,0,sizeof(matrix));
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
			scanf("%d",&S[i]);
		for (int i=1;i<=N;i++)
			scanf("%d",&E[i]);
		for (int i=1;i<=N;i++)
			matrix[i]=((S[i]^E[i])<<N) | (1<<(i-1)) ;
		int x,y;
		while (scanf("%d%d",&x,&y),x && y)
			matrix[y]|=1<<(x-1);
		//GS
		int o=0;//offset
		for (int i=1;i+o<=N+1;i++)//行
		{
			int j;
			for (j=i;j<=N;j++)
				if (matrix[j]&(1<<(i+o-1)))
					break;
			if (j>N)
			{
				o++;
				i--;
				continue;
			}
			swap(matrix[i],matrix[j]);
			for (j=i+1;j<=N;j++)
				if (matrix[j]&(1<<(i+o-1)))
					matrix[j]^=matrix[i];
		}
		int RA,RB;
		for (RA=N;!(matrix[RA]&(1<<(N-1))) && RA>0;RA--);
		for (RB=N;!(matrix[RB]&(1<<N)) && RB>0;RB--);
		RB=max(RB,RA);
		//printf("RA=%d\nRB=%d\n",RA,RB);
		if (RA!=RB)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n",1<<(N-RA));
	}
	return 0;
}