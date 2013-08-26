#include <cstdio>
#include <cstring>
struct node 
{
	int next,pre;
	char name[20];
}child[70];
int N,W,S;
int main()
{
	int i;
	scanf("%d",&N);
	getchar();
	for (i=1;i<=N;i++)
	{
		gets(child[i].name);
		child[i].next=i+1;
		child[i].pre=i-1;
	}
	child[N].next=1;
	child[1].pre=N;
	scanf("%d,%d",&W,&S);
	while (child[W].next!=W)
	{
		for (i=2;i<=S;i++)
		{
			W=child[W].next;
		}
		puts(child[W].name);
		child[child[W].next].pre=child[W].pre;
		child[child[W].pre].next=child[W].next;
		W=child[W].next;
	}
	puts(child[W].name);
}
