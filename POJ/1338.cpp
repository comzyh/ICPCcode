#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const double MAX=2147483647;
int arr[1509];
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(1);
	for (int i=1;i<=1500;i++)
	{
		arr[i]=q.top();
		q.pop();
		while(!q.empty() && q.top()==arr[i])
			q.pop();
		if (arr[i]*2.0<MAX)
			q.push(arr[i]*2);
		if (arr[i]*3.0<MAX)
			q.push(arr[i]*3);
		if (arr[i]*5.0<MAX)
			q.push(arr[i]*5);
	}
	int N;
	while (scanf("%d",&N),N)
		printf("%d\n",arr[N]);
	return 0;
}