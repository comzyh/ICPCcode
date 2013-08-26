#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T,N;
struct phone
{
	char p[12];
	inline bool operator <(const phone &pp) const
	{
		return strcmp(p,pp.p)<0;
	}
}list[10001];
int main()
{
	int i,j,same;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		getchar();
		for (i=1;i<=N;i++)
			gets(list[i].p);
		sort(list, list+N); 
		for (i=1;i<N;i++)
		{	
			same=1;
			for (j=0;list[i].p[j]!='\0' && list[i+1].p[j]!='\0';j++)	
				if (list[i].p[j]!=list[i+1].p[j])
				{
					same=0;
					break;
				}
			if (same)
				break;
		}
		if (same)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
