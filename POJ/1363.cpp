#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int N;
stack<int> s;
int seq[1009];
int main()
{
	while (scanf("%d",&N),N)
	{
		while (scanf("%d",&seq[1]),seq[1])
		{
			while(!s.empty()) s.pop();
			for (int i=2;i<=N;i++)
				scanf("%d",&seq[i]);
			int i=0,j=1;
			do
			{
				s.push(++i);
				while(!s.empty() && j<=N && s.top()==seq[j])
				{
					s.pop();
					j++;
				}
			}while (i<N);
			if (s.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
	return 0;

}