#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
int N,ANS;
int arr[309],used[309],count[69];
void dfs(int deep,int pos)
{
	if (deep>ANS)
		return;
	if (pos>59)
	{
		ANS=min(ANS,deep);
		return ;
	}
	for (int d=pos+1;pos+d<=59;d++)\
	if (count[pos+d])
	{
		int fail=0;
		for (int p=pos+d;p<=59;p+=d)
			if (!count[p])
			{
				fail=1;
				break;
			}
		if (fail)
			continue;
		for (int p=pos;p<=59;p+=d)
			count[p]--;
		int ppos=pos;
		while (!count[ppos] && ppos<=59)
			ppos++;
		dfs(deep+1,ppos);
		for (int p=pos;p<=59;p+=d)
			count[p]++;
	}
}
int main()
{
	cout << "XXXsss\n";
	while (scanf("%d",&N)!=EOF)
	{
		//time_t start=clock();
		memset(used,0,sizeof(used));
		memset(count,0,sizeof(count));
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&arr[i]);
			count[arr[i]]++;
		}
		ANS=17;
		dfs(0,arr[1]);
		printf("%d\n",ANS);
		//cerr << clock()-start << endl;
		break;
	}
	return 0;
}