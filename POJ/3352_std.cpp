/*3352    Accepted    292K    110MS    C++    2205B    2012-06-10 16:59:26*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define mpair make_pair
#define pii pair<int,int>
#define MM(a,b) memset(a,b,sizeof(a));
typedef long long lld;
typedef unsigned long long u64;
template<class T> bool up_max(T& a,const T& b){return b>a? a=b,1 : 0;}
template<class T> bool up_min(T& a,const T& b){return b<a? a=b,1 : 0;}
#define maxn 1020

int n,m;
vector<int> adj[maxn];

int Bcnt, Index, Top;
int low[maxn], dfn[maxn], sta[maxn], belong[maxn];
bool vis[maxn];
void Init_tarjan(){
	Bcnt= Index= Top= 0;
	for(int i=1;i<=n;++i) low[i]= dfn[i]= vis[i]= 0;
}
void Tarjan(int u,int fa){
	low[u]= dfn[u]= ++Index;
	sta[++Top]= u;
	vis[u]= 1;
	for(int i=0;i<adj[u].size();++i){
		int v= adj[u][i];
		if( v==fa ) continue;

		if( !dfn[v] ){
			Tarjan( v, u );
			up_min( low[u], low[v] );
		}
		else if( vis[v] )
			up_min( low[u], dfn[v] );
	}
	if( low[u]==dfn[u] ){
		++Bcnt;
		int v;
		do{
			v= sta[Top--];
			vis[v]= 0;
			belong[v]= Bcnt;
		}while( u!=v );
	}
}

int degree[maxn];
void dfs(int u){
    vis[u]= 1;
    for(int i=0;i<adj[u].size();++i){
        int v= adj[u][i];
        if( !vis[v] ){
            if( belong[u]!=belong[v] ){
                ++degree[ belong[v] ];
                ++degree[ belong[u] ];
            }
            dfs(v);
        }
    }
}

int main()
{
	//freopen("poj3352.in","r",stdin);
	while( cin>>n>>m ){
		int i,x,y;
		for(i=1;i<=n;++i) adj[i].clear();
		while( m-- ){
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		Init_tarjan();
		Tarjan( 1, 1 );
		fill( degree, degree+1+Bcnt, 0 );
		// for (int i=1;i<=n;i++)
		// 	for (int j=0;j<adj[i].size();j++)
		// 		if(belong[i]!=belong[adj[i][j]])
		// 			degree[i]++;
		MM( vis, 0 );
        dfs( 1 );
		int tot= 0;
		for(i=1;i<=Bcnt;++i)
			if( degree[i]==1 ) tot++;
		printf("%d\n",(tot+1)/2 );
	}
	return 0;
}