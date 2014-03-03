#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int N,M;
vector<int> Q;
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		Q.clear();
		for (int i=1;i<=N;i++)
		{
			int v;
			scanf("%d",&v);
			Q.push_back(v);
		}
		sort(Q.begin(),Q.end());
		int Ans[2],Turn=0;
		Ans[0]=Ans[1]=0;
		for (int i=1;i<=M;i++)
		{
			int Target=!Q.empty()?Q[0]:0,p,q,hit[1009],pocket[1009],sum=0;
			scanf("%d",&p);
			for (int i=1;i<=p;i++)
				scanf("%d",&hit[i]);
			sort(hit+1,hit+p+1);
			scanf("%d",&q);
			for (int i=1;i<=q;i++)
			{
				scanf("%d",&pocket[i]);
				sum+=pocket[i];
				if (pocket[i]!=0)
					Q.erase(remove(Q.begin(),Q.end(),pocket[i]),Q.end());
			}
			sort(pocket+1,pocket+q+1);
			//Penalty
			int not_hit_any_ball=(p==0);
			int cue_ball_pocketed=(q!=0 && pocket[1]==0);
			int hit_wrong_ball=(p && hit[1]!=Target);
			int foul=0;
			if (not_hit_any_ball)
			{
				Ans[Turn^1]+=Target;
				foul=1;
			}
			if ((!cue_ball_pocketed && (hit_wrong_ball || p>1)) || 
				(cue_ball_pocketed && !not_hit_any_ball))
			{
				Ans[Turn^1]+=hit[p];
				foul=1;
			}
			//Point
			if (!foul && q!=0 && pocket[1]==Target)
				Ans[Turn]+=sum;//,printf("C3 ");
			else
			{
				Turn^=1;
				Ans[Turn]+=sum;//,printf("C4 ");
			}
			//printf("%d : %d\n",Ans[0],Ans[1]);
		}
		printf("%d : %d\n",Ans[0],Ans[1]);
	}
	return 0;
}