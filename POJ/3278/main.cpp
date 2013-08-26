#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXSIZE 100010
int step[MAXSIZE];
int vis[MAXSIZE];
queue<int>que;
int BFS(int n,int k)
{
    int curr,target;
    que.push(n);
    vis[n]=true;
    while(!que.empty())
    {
        curr=que.front();
        que.pop();
        for(int i=0;i<3;i++)
        {
            switch (i)
            {
                case 0:
                    target=curr+1;
                    break;
                case 1:
                    target=curr-1;
                    break;
                case 2:
                    target=curr*2;
                    break;
            }
            if(target<0 || target>MAXSIZE)  continue;
            if(!vis[target])
            {
                vis[target]=true;
                step[target]=step[curr]+1;
                que.push(target);
            }
            if(target==k)   return step[target];
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        memset(step,0,sizeof(step));
        memset(vis,0,sizeof(vis));
        while(!que.empty()) que.pop();
        int ans=BFS(n,m);
        cout<<ans<<endl;
    }
    return 0;
}
